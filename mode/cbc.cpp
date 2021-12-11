#include "cbc.hpp"
#include <random>
#include <thread>
#include <vector>

void CBC::encrypt(std::ostream& output, std::istream& input, std::string key)
{
    u_char block[size];
    u_char initVector[size];

    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<> randint(0,255);
    for(int i = 0; i < size;i++)
        initVector[i] = randint(gen);

    output.write(reinterpret_cast<char*>(initVector), size);
    while(input.readsome(reinterpret_cast<char*>(block),size))
    {
        u_char buffer[size];
        for(int i = 0;i < size;i++)
            buffer[i] = block[i]^initVector[i];
        method->encrypt(initVector,buffer,method->expandKey(key.c_str()));
        output.write(reinterpret_cast<char*>(initVector), size);
    }
}

void CBC::decrypt(std::ostream& output, std::istream& input, size_t blocks, std::string key)
{
    std::vector<std::thread*> blockThreads;
    std::vector<u_char*> blockOutputs;
    std::vector<u_char*> blockInputs;
    blockInputs.push_back(new u_char[size]);
    input.read(reinterpret_cast<char*>(blockInputs[0]), size);
    for(size_t lagbox = 1;lagbox < blocks;lagbox+=30000)
    {
        for(size_t i = lagbox;i < blocks && i < lagbox+30000;i++)
        {
            blockOutputs.push_back(new u_char[size]);
            blockInputs.push_back(new u_char[size]);
            input.read(reinterpret_cast<char*>(blockInputs[i]), size);
            blockThreads.push_back(new std::thread(&Method::decrypt, method, blockOutputs[i-1], blockInputs[i], method->expandKey(key.c_str())));
        }
        for(size_t i = lagbox-1;i < blocks-1 && i < lagbox+29999;i++)
        {
            blockThreads[i]->join();
            u_char buffer[size];
            for(int j = 0;j < size;j++)
                buffer[j] = blockOutputs[i][j]^ blockInputs[i][j];
            output.write(reinterpret_cast<char*>(buffer), size);
        }
    }
}