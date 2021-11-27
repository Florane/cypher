#pragma once
#include "method.hpp"

class AES : public Method
{
    int sBox[256], invSBox[256];
    int mult2[256], mult3[256], mult9[256], mult11[256], mult13[256], mult14[256];
    int rCon[10];
    unsigned char roundKey[16*11];
    void subBytes(unsigned char* input);
    void subBytes(unsigned char* input, int size);
    void invSubBytes(unsigned char* input);

    void shiftRows(unsigned char* input, int move);
    void shiftRows(unsigned char* input);
    void invShiftRows(unsigned char* input);

    void mixColumns(unsigned char* input);
    void invMixColumns(unsigned char* input);

    void shiftRoundKey(unsigned char* key);
    void addRoundKey(unsigned char* input, int round);
public:
    using Method::Method;
    AES();

    void encrypt(unsigned char* outp0xut, unsigned char* inp0xut, unsigned char* key);
    void decrypt(unsigned char* outp0xut, unsigned char* inp0xut, unsigned char* key);
};