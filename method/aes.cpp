#include "aes.hpp"
#include <cstring>

//S-box manipulation of a block
void AES::subBytes(unsigned char* input)
{
    for(int i = 0;i < blockSize;i++)
        input[i] = sBox[input[i]];
}
void AES::subBytes(unsigned char* input, int size)
{
    for(int i = 0;i < size;i++)
        input[i] = sBox[input[i]];
}
void AES::invSubBytes(unsigned char* input)
{
    for(int i = 0;i < blockSize;i++)
        input[i] = invSBox[input[i]];
}

void AES::shiftRows(unsigned char* input, int move)
{
    unsigned char buffer[4];
    for(int i = 0;i < 4;i++)
        buffer[i] = input[i];
    for(int i = 0;i < 4;i++)
        input[i] = buffer[(i+move)%4];
}
void AES::shiftRows(unsigned char* input)
{
    shiftRows(input+4,1);
    shiftRows(input+8,2);
    shiftRows(input+12,3);
}
void AES::invShiftRows(unsigned char* input)
{
    shiftRows(input+4,3);
    shiftRows(input+8,2);
    shiftRows(input+12,1);
}

void AES::mixColumns(unsigned char* input)
{
    unsigned char buffer[blockSize];
    for(int i = 0;i < 4;i++)
    {
        buffer[i] = mult2[input[i]]^mult3[input[4+i]]^input[8+i]^input[12+i];
        buffer[4+i] = input[i]^mult2[input[4+i]]^mult3[input[8+i]]^input[12+i];
        buffer[8+i] = input[i]^input[4+i]^mult2[input[8+i]]^mult3[input[12+i]];
        buffer[12+i] = mult3[input[i]]^input[4+i]^input[8+i]^mult2[input[12+i]];
    }
    for(int i = 0;i < blockSize;i++)
        input[i] = buffer[i];
}
void AES::invMixColumns(unsigned char* input)
{
    unsigned char buffer[blockSize];
    for(int i = 0;i < 4;i++)
    {
        buffer[i] = mult14[input[i]]^mult11[input[4+i]]^mult13[input[8+i]]^mult9[input[12+i]];
        buffer[4+i] = mult9[input[i]]^mult14[input[4+i]]^mult11[input[8+i]]^mult13[input[12+i]];
        buffer[8+i] = mult13[input[i]]^mult9[input[4+i]]^mult14[input[8+i]]^mult11[input[12+i]];
        buffer[12+i] = mult11[input[i]]^mult13[input[4+i]]^mult9[input[8+i]]^mult14[input[12+i]];
    }
    for(int i = 0;i < blockSize;i++)
        input[i] = buffer[i];
}

void AES::shiftRoundKey(unsigned char* key)
{
    for(int i = 0;i < blockSize;i++)
        roundKey[i] = key[i];

    for(int round = 0;round < 10;round++)
    {
        unsigned char buffer[4];
        for(int i = 0;i < 4;i++)
            buffer[i] = roundKey[12+i+round*blockSize];
        shiftRows(buffer,1);
        subBytes(buffer,4);
        buffer[0] ^= rCon[round];
        
        for(int i = 0;i < 4;i++)
            roundKey[(round+1)*blockSize+i] = buffer[i]^roundKey[round*blockSize+i];
        for(int i = 1;i < 4;i++)
            for(int j = 0;j < 4;j++)
                roundKey[(round+1)*blockSize+i*4+j] = roundKey[(round+1)*blockSize+(i-1)*4+j]^roundKey[round*blockSize+i*4+j];
    }
}
void AES::addRoundKey(unsigned char* input, int round)
{
    for(int i = 0;i < blockSize;i++)
        input[i] ^= roundKey[i+round*blockSize];
}

void AES::encrypt(unsigned char* output, unsigned char* input, unsigned char* key)
{
    shiftRoundKey(key);
    for(int i = 0;i < 9;i++)
    {
        addRoundKey(input,i);
        subBytes(input);
        shiftRows(input);
        mixColumns(input);
    }
    addRoundKey(input,9);
    subBytes(input);
    shiftRows(input);
    addRoundKey(input,10);
    for(int i = 0;i < blockSize;i++)
        output[i] = input[i];
}

void AES::decrypt(unsigned char* output, unsigned char* input, unsigned char* key)
{
    shiftRoundKey(key);
    addRoundKey(input,10);
    for(int i = 9;i > 0;i--)
    {
        invShiftRows(input);
        invSubBytes(input);
        addRoundKey(input,i);
        invMixColumns(input);
    }
    invShiftRows(input);
    invSubBytes(input);
    addRoundKey(input,0);
    for(int i = 0;i < blockSize;i++)
        output[i] = input[i];
}