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
                args[key] = std::vector<std::string>{"1"};
            key = argv[i];
        }
        else
        {
            if(key != "")
                if(args.count(key))
                    args[key].push_back(argv[i]);
                else
                    args[key] = std::vector<std::string>{argv[i]};
        }
    }
    if(key != " " && !args.count(key))
        args[key] = std::vector<std::string>{"1"};
}
