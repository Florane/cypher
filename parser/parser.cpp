#include "parser.hpp"
#include <iostream>

Parser::Parser(int argc, char* argv[])
{
    std::string key = " ";
    for(int i = 1;i < argc;i++)
    {
        if(argv[i][0] == '-')
        {
            if(key != " " && !args.count(key))
                args[key] = '1';
            key = argv[i];
        }
        else
        {
            if(key != "")
                args[key] = argv[i];
        }
    }
    if(key != " " && !args.count(key))
        args[key] = '1';
}
