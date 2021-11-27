#pragma once

class Method
{
protected:
    const int blockSize;
public:
    Method(int _size) : blockSize(_size) {}
    Method() : Method(16) {};

    virtual unsigned char* expandKey(const unsigned char* key);
    virtual void encrypt(unsigned char* output, unsigned char* input, unsigned char* key);
    virtual void decrypt(unsigned char* output, unsigned char* input, unsigned char* key);
};
