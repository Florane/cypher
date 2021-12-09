#pragma once
#include <map>
#include <string>

class Parser
{
    std::map<std::string, std::string> args;
public:
    Parser(int argc, char* argv[]);
    Parser();

    std::string get(std::string key) {return args.count(key)?args[key]:"0";}
    int getInt(std::string key) {return args.count(key)?std::stoi(args[key]):0;}
    bool check(std::string key) {return args.count(key);}
};
