#include <iostream>
#include <fstream>

#include "method/aes.hpp"
#include "mode/cbc.hpp"
#include "mode/cfb.hpp"
#include "keygen/shamir.hpp"
#include "parser/parser.hpp"

void encode(Parser& parser, Mode* mode, std::istream& input, std::ostream& output)
{
	std::string key;
	std::ifstream keyFile(parser.get(parser.check("-k")?"-k":"--key").c_str());
	if(keyFile.good())
	{
		char buffer[16];
		keyFile.readsome(buffer,15);
		key = buffer;
		keyFile.close();
		std::ofstream keyScrub(parser.get(parser.check("-k")?"-k":"--key").c_str());
		keyScrub.close();
	}
	else
	{
		key = parser.get(parser.check("-k")?"-k":"--key");
		key = key.substr(0,15);
	}

	Shamir shamir(parser.getInt("-m"),parser.getInt("-t"));
	std::vector<std::string> shares;
	shares.resize(parser.getInt("-t"));
	shamir.split(key,shares.data());
	for(int i = 0;i < shares.size();i++)
	{
		std::string fileName = "share";
		fileName += ('1'+i);
		std::ofstream shareFile(fileName);
		shareFile << i+1 << " " << shares[i];
		shareFile.close();
	}

	mode->encrypt(output,input,key);
}

void decode(Parser& parser, Mode* mode, std::istream& input, std::ostream& output)
{
	std::string key;
	std::vector<std::string> shares;
	std::vector<int> parts;
	for(auto fileName : parser.getAll(parser.check("-s")?"-s":"--shares"))
	{
		std::ifstream file(fileName.c_str());
		std::string buffer; int buffer0;
		file >> buffer0 >> buffer;
		shares.push_back(buffer);
		parts.push_back(buffer0);
	}
	
	Shamir shamir(parser.getInt("-m"),0);
	shamir.glue(shares.data(),parts.data(),key);

	mode->decrypt(output,input,key);

	if(parser.check("--save_key"))
	{
		std::ofstream file(parser.get("--save_key"));
		file << key << std::endl;
	}
}

int main(int argc, char* argv[])
{
	Parser parser(argc, argv);
	if(argc == 1)
		throw std::invalid_argument("Use flag '-h' to view a help message");
	if(parser.check("-h"))
	{
		std::cout
		<< "-h - outputs this help message" << std::endl
		<< "-e - encode" << std::endl
		<< "-d - decode" << std::endl
		<< "-i, --input - input file" << std::endl
		<< "-o, --output - output file" << std::endl
		<< "--cbc - use CBC cipher mode" << std::endl
		<< "--cfb - use CFB cipher mode" << std::endl
		<< "-k, --key - key string or key file name" << std::endl
		<< "-t - total amount of shares" << std::endl
		<< "-m - minimal amount of shares to restore key" << std::endl
		<< "--save_key - key file name" << std::endl;
	}
	if(!(parser.check("-e")^parser.check("-d")))
		throw std::invalid_argument("Only one operation mode can be used");
	if(!(parser.check("-i")^parser.check("--input")))
		throw std::invalid_argument("Input file has not been provided properly");
	if(!(parser.check("-o")^parser.check("--output")))
		throw std::invalid_argument("Output file has not been provided properly");
	if(!(parser.check("--cbc")^parser.check("--cfb")))
		throw std::invalid_argument("Only one cipher mode can be used");
	if(parser.check("-e"))
	{
		if(!(parser.check("-k")^parser.check("--key")))
			throw std::invalid_argument("Key has not been provided properly");
		if(!parser.check("-t"))
			throw std::invalid_argument("No total amount of shares was given");
		if(!parser.check("-m"))
			throw std::invalid_argument("No minimal amount of shares was given");
	}
	if(parser.check("-d"))
	{
		if(!(parser.check("-s")^parser.check("--shares")))
			throw std::invalid_argument("Shares have not been provided properly");
		if(!parser.check("-m"))
			throw std::invalid_argument("No minimal amount of shares was given");
		if(parser.getInt("-m") > parser.getAll(parser.check("-s")?"-s":"-shares").size())
			throw std::invalid_argument("Not enough shares to restore a key");
	}


	std::ifstream input(parser.get(parser.check("-i")?"-i":"--input").c_str());
	std::ofstream output(parser.get(parser.check("-o")?"-o":"--output").c_str());

	Method* method = new AES;
	Mode* mode;
	if(parser.check("--cbc"))
		mode = new CBC(method);
	else if(parser.check("-cfb"))
		mode = new CFB(method);

	if(parser.check("-e"))
		encode(parser,mode,input,output);
	else if(parser.check("-d"))
		decode(parser,mode,input,output);
	return 0;
}
