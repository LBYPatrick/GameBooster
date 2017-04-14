#pragma once
#include <string>

using std::string;
namespace util {
	bool lookup(string processName);
	string toUpperString(string str);
	void visualTimer(std::string message, unsigned int currentTime, unsigned int totalTime);
	void highPriority(string processName);
}