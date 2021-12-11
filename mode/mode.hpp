#pragma once
#include <iostream>
#include "../method/method.hpp"

class Mode
{
protected:
    const int size;
    Method* method;
public:
    Mode(int _size, Method* _method) : size(_size), method(_method) {}
    Mode(Method* _method) : Mode(16,_method) {}
    Mode() : Mode(new Method()) {}

    virtual void encrypt(std::ostream& output, std::istream& input, std::string key) {}
    virtual void decrypt(std::ostream& output, std::istream& input, std::string key);
    virtual void decrypt(std::ostream& output, std::istream& input, size_t blocks, std::string key) {}
};
