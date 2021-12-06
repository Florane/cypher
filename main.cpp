#include <iostream>
#include <fstream>
#include <cstring>
#include "method/aes.hpp"
#include "mode/cbc.hpp"

int main()
{
	CBC cbc(new AES);
	std::ifstream input("output");
	std::ofstream output("output0");
	std::string key = "0";
	cbc.decrypt(output, input, 1000, key);

	return 0;
}
