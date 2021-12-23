#pragma once
#include <map>
#include <string>
#include <vector>

/**
 * \defgroup _Parser
 * \{
 */
/// Парсер аргументов коммандной строки
class Parser
{
    std::map<std::string, std::vector<std::string>> args;
public:
    Parser(int argc, char* argv[]);
    Parser();

    std::string get(std::string key) {return args.count(key)?args[key][0]:"0";}
    int getInt(std::string key) {return args.count(key)?std::stoi(args[key][0]):0;}
    std::vector<std::string> getAll(std::string key) {if(args.count(key)) return args[key];}
    bool check(std::string key) {return args.count(key);}
};///\}
