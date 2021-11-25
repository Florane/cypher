#include "test.hpp"

char* Test::expandKey(const char* key)
{
    char* ret = new char[blockSize];
    for(int i = 0, j = 0;i < blockSize;i++,j++)
    {
        if(key[j] == '\0')
            j = 0;
        ret[i] = key[j];
    }
    return ret;
}

void Test::encrypt(char* output, char* input, char* key)
{
    for(int i = 0;i < blockSize;i++)
        output[i] = input[i]^key[i];
    // delete key;
}

void Test::decrypt(char* output, char* input, char* key)
{
    for(int i = 0;i < blockSize;i++)
        output[i] = input[i]^key[i];
    // delete key;
}