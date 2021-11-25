#include <iostream>
#include <fstream>
#include <cstring>
#include "method/test.hpp"
#include "mode/cbc.hpp"

int main()
{
	CBC cbc(new Test);
	std::ifstream input("input");
	std::ofstream output("output");
	std::string key = "0";

	cbc.decrypt(output, input, 2, key);

	return 0;
}
