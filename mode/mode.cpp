#include "mode.hpp"

void Mode::decrypt(std::ostream& output, std::istream& input, std::string key)
{
    input.seekg(0, input.end);
	int length = input.tellg();
	input.seekg(0, input.beg);
	decrypt(output, input, (length/16), key);
}
