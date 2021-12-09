#include <iostream>
#include <fstream>
#include "shamir.hpp"

int main()
{
    Shamir test;
    std::string key = "";
    InfInt res[5];
    test.split(key,res);
    for(int i = 0;i < 5;i++)
        std::cout << res[i] << std::endl;

    int parts[3] = {1,2,3};
    test.glue(res, parts, key);
    std::cout << key << std::endl;
    return 0;
}