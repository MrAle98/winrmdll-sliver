#pragma once
#include <iostream>
class Arguments {
public:
	Arguments(const char* argument_string);
	std::string Hostname;
	std::string Command;
	std::string Username;
	std::string Password;
};

