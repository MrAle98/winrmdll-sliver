#pragma once
#include <iostream>

typedef int (*goCallback)(char*, int);

extern "C" {
	__declspec(dllexport) int __cdecl Execute(char* argsBuffer, uint32_t bufferSize, goCallback callback);
#ifdef DEBUG
	__declspec(dllexport) int __cdecl Testing();
#endif

}

#ifdef DEBUG
int callbackMockFunc(char*, int);
#endif