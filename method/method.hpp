#pragma once

class Method
{
protected:
    const int blockSize;
public:
    Method(int _size) : blockSize(_size) {}
    Method() : Method(16) {};

    virtual char* expandKey(const char* key) {}
    virtual void encrypt(char* output, char* input, char* key) {}
    virtual void decrypt(char* output, char* input, char* key) {}
};
