#pragma once
#include "mode.hpp"

class CBC : public Mode
{
public:
    using Mode::Mode;
    void encrypt(std::ostream& output, std::istream& input, std::string key);
    void decrypt(std::ostream& output, std::istream& input, size_t blocks, std::string key);
    // void decrypt(std::ostream& output, std::istream& input, std::string key);
};
