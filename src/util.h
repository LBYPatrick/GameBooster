#pragma once
#include <string>

using std::string;
namespace util {
	//bool lookup(string processName); //Deprecated
	
	string toUpperString(string str);
	void visualTimer(std::string message, unsigned int currentTime, unsigned int totalTime);
	void highPriority(string processName);
	void lowPriority(string processName);
	void visualProgress(string message, int currentProgress, int progressGoal);
	string detectLanguage();
	bool enhancedLookup(string programName);
	void enhancedLookupInit();
	void enhancedLookupCleanup();
	string getCurrentTime();
	void killTask(string taskname);
}

