#pragma once
#include <vector>
#include "InfInt.h"

class Shamir
{
    const int required, produced;
    InfInt pow(int a, int b);
    InfInt bitString(std::string &str);
    std::string toBitString(InfInt i);
    InfInt getShare();
    const InfInt prime = pow(2,127)-1;
public:
    Shamir(int r, int q) : required(r), produced(q) {}
    Shamir() : Shamir(3,5) {}

    void split(std::string &key, std::string *piecestreams);
    void glue(std::string *shares, int *parts, std::string &key);

    int producedCount() {return produced;}
    int requiredCount() {return required;}
};
