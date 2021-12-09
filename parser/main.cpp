#include <iostream>
#include "parser.hpp"

int main(int argc, char* argv[])
{
    Parser test(argc,argv);
    std::cout << test.getInt("-h") << std::endl;
}