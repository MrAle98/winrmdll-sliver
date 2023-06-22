#include <stdio.h>
#include <string>
#include <vector>
#include "Entry.h"
#include "base64.h"
#include "winrm.h"
#include "Arguments.h"
#include "output.h"
#include "utils.h"

#ifdef DEBUG
int callbackMockFunc(char* buf, int i) {
	return 1;
}

goCallback callback = callbackMockFunc;

int Testing() {
	// global variable to hold all output returned to Sliver
	
	const char* argsBuffer = "127.0.0.1 whoami contoso.local\\Administrator Password123!";
	int bufferSize = strlen(argsBuffer);
	output = NewOutput(2049, callback);

	append(output, "Executing winrmdll-sliver v0.3.7\n");

	if (bufferSize < 1) {
		append(output, "You must provide an argument\n");
		return failure(output);
	}

	append(output, "[Execute] buffer size: %u\n", bufferSize);
	append(output, "[Execute] argsBuffer: %s\n", argsBuffer);
	append(output, "[Arguments] argsBuffer size2: %u\n", strlen(argsBuffer));

	//try {
	Arguments args = Arguments(argsBuffer);

	append(output, "[Execute] Arguments processed...\n");
	append(output, "          hostname: %s\n", args.Hostname.c_str());
	append(output, "           command: %s\n", args.Command.c_str());
	append(output, "          username: %s\n", args.Username.c_str());
	append(output, "          password: %s\n", args.Password.c_str());

	/*
	catch (const std::exception&) {
		append(output, "[Execute] Error processing arguments!\n");
		failure(output);
	}
	*/

	// convert for winrm
	std::wstring host = ConvertToWideString(args.Hostname);
	std::wstring command = ConvertToWideString(args.Command);
	std::wstring username = ConvertToWideString(args.Username);
	std::wstring password = ConvertToWideString(args.Password);


	// begin winrm
	if (username == L"NULL" || password == L"NULL")
	{
		username = username.erase();
		password = password.erase();
	}

	append(output, "[Execute] (wide)username:%ls | (wide)password:%ls\n", username.c_str(), password.c_str());

	WinRM* pWinRM = new WinRM();

	if (pWinRM->Setup(host, username, password))
	{
		append(output, "[Execute] Successfully setup pWinRM\n");
		//pWinRM->Execute(command);
	}

	delete pWinRM;

	append(output, "[Execute] Finished!\n");

	return success(output);
}
#endif
int Execute(char* argsBuffer, uint32_t bufferSize, goCallback callback)
{
	// global variable to hold all output returned to Sliver
	output = NewOutput(2049, callback);

	append(output, "Executing winrmdll-sliver v0.3.7\n");

	if (bufferSize < 1) {
		append(output, "You must provide an argument\n");
		return failure(output);
	}

	append(output, "[Execute] buffer size: %u\n", bufferSize);
	append(output, "[Execute] argsBuffer: %s\n", argsBuffer);
	append(output, "[Arguments] argsBuffer size2: %u\n", strlen(argsBuffer));

	//try {
	Arguments args = Arguments(argsBuffer);

	append(output, "[Execute] Arguments processed...\n");
	append(output, "          hostname: %s\n", args.Hostname.c_str());
	append(output, "           command: %s\n", args.Command.c_str());
	append(output, "          username: %s\n", args.Username.c_str());
	append(output, "          password: %s\n", args.Password.c_str());

	/*
	catch (const std::exception&) {
		append(output, "[Execute] Error processing arguments!\n");
		failure(output);
	}
	*/

	// convert for winrm
	std::wstring host = ConvertToWideString(args.Hostname);
	std::wstring command = ConvertToWideString(args.Command);
	std::wstring username = ConvertToWideString(args.Username);
	std::wstring password = ConvertToWideString(args.Password);


	// begin winrm
	if (username == L"NULL" || password == L"NULL")
	{
		username = username.erase();
		password = password.erase();
	}

	append(output, "[Execute] (wide)username:%ls | (wide)password:%ls\n", username.c_str(), password.c_str());

	WinRM* pWinRM = new WinRM();

	if (pWinRM->Setup(host, username, password))
	{
		append(output, "[Execute] Successfully setup pWinRM\n");
		//pWinRM->Execute(command);
	}

	delete pWinRM;

	append(output, "[Execute] Finished!\n");

	return success(output);
}
//
//
//BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpReserved)
//{
//
//	BOOL bReturnValue = TRUE;
//
//	switch (dwReason) {
//
//	case DLL_PROCESS_ATTACH:
//		hAppInstance = hinstDLL;
//		/* print some output to the operator */
//		if (lpReserved != NULL)
//		{
//			std::string b64 = (char*)lpReserved;
//			std::string decoded;
//			macaron::Base64::Decode(b64, decoded);
//			std::vector<std::string> params = split(decoded, '||');
//
//			if (params.size() != 4)
//			{
//				printf("[!] Parameter issue!\n");
//				fflush(stdout);
//				ExitProcess(0);
//				break;
//			}
//
//			std::wstring host;
//			std::wstring command;
//			std::wstring username;
//			std::wstring password;
//
//			host = get_wstring(params[0]);
//			command = get_wstring(params[1]);
//			username = get_wstring(params[2]);
//			password = get_wstring(params[3]);
//
//			if (username == L"NULL" || password == L"NULL")
//			{
//				username = username.erase();
//				password = password.erase();
//			}
//
//			WinRM* pWinRM = new WinRM();
//
//			printf("%ws:%ws\n", username.c_str(), password.c_str());
//
//			if (pWinRM->Setup(host, username, password))
//			{
//				pWinRM->Execute(command);
//			}
//
//			delete pWinRM;
//		}
//		else
//		{
//			printf("[!] No parameters!\n");
//			bReturnValue = FALSE;
//		}
//
//		fflush(stdout);
//		ExitProcess(0);
//		break;
//	case DLL_PROCESS_DETACH:
//	case DLL_THREAD_ATTACH:
//	case DLL_THREAD_DETACH:
//		break;
//	}
//	return bReturnValue;
//}