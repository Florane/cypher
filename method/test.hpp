#pragma once
#include "method.hpp"

class Test : public Method
{
public:
    char* expandKey(const char* key);
    void encrypt(char* output, char* input, char* key);
    void decrypt(char* output, char* input, char* key);
};
