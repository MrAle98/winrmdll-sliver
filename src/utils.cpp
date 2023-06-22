#include "utils.h"



std::wstring get_wstring(const std::string& s)
{
	std::wstring ws(s.begin(), s.end());
	return ws;
}

std::wstring ConvertToWideString(const std::string& narrowString) {
	// Determine the required size for the wide string
	size_t wideStringSize = 0;
	mbstowcs_s(&wideStringSize, nullptr, 0, narrowString.c_str(), 0);

	// Convert narrow string to wide string
	std::wstring wideString;
	wideString.resize(wideStringSize - 1); // excluding null terminator
	mbstowcs_s(nullptr, &wideString[0], wideStringSize, narrowString.c_str(), wideStringSize - 1);

	return wideString;

}
