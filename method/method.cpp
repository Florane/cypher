#include "method.hpp"

unsigned char* Method::expandKey(const char* key)
{
    unsigned char* ret = new unsigned char[blockSize];
    for(int i = 0, j = 0;i < blockSize;i++,j++)
    {
        if(key[j] == '\0')
            j = 0;
        ret[i] = key[j];
    }
    return ret;
}

void Method::encrypt(unsigned char* output, unsigned char* input, unsigned char* key)
{
    for(int i = 0;i < blockSize;i++)
        output[i] = input[i]^key[i];
    // delete key;
}

void Method::decrypt(unsigned char* output, unsigned char* input, unsigned char* key)
{
    for(int i = 0;i < blockSize;i++)
        output[i] = input[i]^key[i];
    // delete key;
}