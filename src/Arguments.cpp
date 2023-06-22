#include "Arguments.h"
#include <vector>
#include <sstream>
#include "output.h"

Arguments::Arguments(const char* argument_string) {
	std::string new_argstr(argument_string);
	std::string arg;
	std::stringstream ss(new_argstr);
	append(output, "[Arguments] argument_string size: %u\n", strlen(argument_string));
	append(output, "[Arguments] new_argstr size: %u\n", new_argstr.size());
	std::vector<std::string> args;
	while (ss >> arg) {
		args.push_back(arg);
	}

	this->Hostname = args[0];
	//this->Hostname = "dest2.vic.local";
	this->Command = args[1];
	this->Username = args[2];
	this->Password = args[3];

	return;
}