#include <iostream>
#include <fstream>
#include "shamir.hpp"

int main()
{
    Shamir test;
    std::string key = "Hello World!";
    std::string res[5];
    test.split(key,res);
    for(int i = 0;i < 5;i++)
        std::cout << res[i] << std::endl;

    int parts[3] = {1,2,3};
    std::string key1;
    test.glue(res, parts, key1);
    std::cout << key << " " << key1 << " " << (key==key1?"true":"false") << std::endl;
    return 0;
}