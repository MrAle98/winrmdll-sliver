#pragma once
#include "Entry.h"
/*
 * Sliver API requirements for the library to communicate with the Sliver implant
 */

// Struct to contain all output
struct Output {
	char* data;
	int len;
	goCallback callback;
};

// Create initial output buffer
Output* NewOutput(int bufferSize, goCallback callback);

// Used to add additional output
void append(Output* output, const char* format, ...);

// For use in all places a function returns
int failure(Output* output);
int success(Output* output);

// pseudo 'printf' buffer
extern Output* output;
