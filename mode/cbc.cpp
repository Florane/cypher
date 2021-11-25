#include "cbc.hpp"
#include <random>
#include <thread>
#include <vector>

void CBC::encrypt(std::ostream& output, std::istream& input, std::string key)
{
    char block[size];
    char initVector[size];

    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<> randint(0,255);
    for(int i = 0; i < size;i++)
        initVector[i] = randint(gen);

    output.write(initVector, size);
    while(input.read(block,size))
    {
        char buffer[size];
        for(int i = 0;i < size;i++)
            buffer[i] = block[i]^initVector[i];
        method->encrypt(initVector,buffer,method->expandKey(key.c_str()));
        output.write(initVector, size);
    }
}

void CBC::decrypt(std::ostream& output, std::istream& input, size_t blocks, std::string key)
{
    std::vector<std::thread*> blockThreads;
    std::vector<char*> blockOutputs;
    std::vector<char*> blockInputs;
    for(size_t i = 0;i < blocks;i++)
    {
        blockOutputs.push_back(new char[size]);
        blockInputs.push_back(new char[size]);
        input.read(blockInputs[i], size);
        blockThreads.push_back(new std::thread(&Method::decrypt, method, blockOutputs[i], blockInputs[i], method->expandKey(key.c_str())));
    }
    for(size_t i = 1;i < blocks;i++)
    {
        blockThreads[i]->join();
        char buffer[size];
        for(int j = 0;j < size;j++)
            buffer[j] = blockOutputs[i][j]^ blockInputs[i-1][j];
        output.write(buffer, size);
    }
}