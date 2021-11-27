#include <iostream>
#include <fstream>
#include <cstring>
#include "method/aes.hpp"
#include "mode/cbc.hpp"

int main()
{
	CBC cbc(new AES);
	std::ifstream input("input");
	std::ofstream output("output");
	std::string key = "0";
	cbc.encrypt(output, input, key);

	return 0;
}
