#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<windows.h>
#include "util.h"
using namespace std;

ifstream ReadTasklist;
string tasklistTemp;
string tasklist;

void util::lookupInit() {
	system("tasklist > tasklist.txt");
	ReadTasklist.open("tasklist.txt");
	while (ReadTasklist>>tasklistTemp) {
		tasklist += tasklistTemp;
	}
	ReadTasklist.close();
}

bool util::lookup(string programName) {
	string tempBuf = programName + ".";
	if (tasklist.find(tempBuf.c_str()) != string::npos) {
		return 1;
	}
		return 0;
}

void util::lookupCleanup() {
	tasklist = "";
	system("del tasklist.txt");
}

/*
DEPRECATED FUNCTION

bool util::lookup(string processName) {
	ifstream Reader;
	string temp;
	char receiver[128];
	sprintf(receiver, "tasklist /FI \"IMAGENAME eq %s\" > result.txt", processName.c_str());
	system(receiver);
	Reader.open("result.txt");

	if (Reader.is_open()) {
		while (!Reader.eof()) {
			getline(Reader, temp);
			if (temp.find("Image Name") != string::npos) {
				Reader.close();
				system("del result.txt");
				return 1;
			}
		}
		Reader.close();
	}
	system("del result.txt");
	return 0;
}
*/
string util::toUpperString(string str) {
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		*it = (char)toupper(*it);
	return str;
}

void util::visualTimer(std::string message, unsigned int currentTime,unsigned int totalTime) {
	system("cls");
	printf("%s\n[", message.c_str());
	
	for (int i = 0; i <= (currentTime); i++) {printf(">");} 
	for (int i = 0; i < (totalTime - currentTime); i++) {printf(" ");}
	if (currentTime + (totalTime - currentTime) < totalTime) {printf (" ");}
	
	
	printf("] %d seconds", totalTime - currentTime);
	if (currentTime == totalTime) {
		printf("\n\n\n");
	}
}

void util::highPriority(string processName) {
	char executor[128];
	sprintf(executor, "wmic process where \"name='%s.exe'\" call setpriority 128 > nul", processName.c_str());
	system(executor);
}

void util::lowPriority(string processName) {
	char executor[128];
	/**
	Something from Microsoft:
	https://msdn.microsoft.com/en-us/library/aa393587(v=vs.85).aspx
	64			- idle
	16384		- Below Normal
	32			- Normal
	32768		- Above Normal
	128			- High
	256			- Realtime (Highest According to microsoft)
	*/
	
	/*
	string execute;
	execute += "wmic process where ";
	execute += "\"name='";
	execute += processName;
	execute += "'\" call setpriority 64 > nul";
	*/

	sprintf(executor, "wmic process where \"name='%s.exe'\" call setpriority 64 > nul", processName.c_str());
	system(executor);
}

void util::visualProgress(string message,int currentProgress,int progressGoal) {
	system("cls");
	printf("%s\n[", message.c_str());
	currentProgress++;
	for (int i = 0; i <= (currentProgress); i++) {
		printf(">");
	} for (int i = 0; i < (progressGoal - currentProgress); i++) {
		printf(" ");
	}
	if (currentProgress + (progressGoal - currentProgress) < progressGoal) {
		printf(" ");
	}
	printf("]%d/%d",currentProgress,progressGoal);
	if (currentProgress == progressGoal) {
		printf("\n\n\n");
	}
};

string util::detectLanguage() {
	/**
	Here's a good reference for hexadecimal identifier of languages:
	https://technet.microsoft.com/en-us/library/cc766503(v=ws.10).aspx
	**/
	string languageTemp;
	ifstream localeReader;
	system("wmic os get locale > language_UTF16.txt");
	system("type language_UTF16.txt > language.txt");
	system("del language_UTF16.txt");
	localeReader.open("language.txt");
	
	if (localeReader.is_open()) {
		while (!localeReader.eof()) {
			localeReader>>languageTemp;
			if (languageTemp.find("0409") != string::npos) {
				localeReader.close();
				system("del language.txt");
				return "en_US";
			}
			
			if (languageTemp.find("0404") != string::npos) {
				localeReader.close();
				system("del language.txt");
				return "zh_HK";
			}

			if (languageTemp.find("0804") != string::npos) {
				localeReader.close();
				system("del language.txt");
				return "zh_CN";
			}
		}
		localeReader.close();
	}

	system("del language.txt");
	return "en_US";
}

string util::getCurrentTime() {
	ifstream timeReader;
	string result;

	system("echo %date% %time% >> time.info");
	timeReader.open("time.info");
	getline(timeReader, result);
	timeReader.close();
	system("del time.info");
	return result;
}

void util::killTask(string taskname){
	char buffer[128];
	sprintf(buffer,"taskkill /f /im %s.exe",taskname.c_str());
	system(buffer);
}


bool util::isUserAdmin() {
	BOOL b;
	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	PSID AdministratorsGroup;
	b = AllocateAndInitializeSid(
		&NtAuthority,
		2,
		SECURITY_BUILTIN_DOMAIN_RID,
		DOMAIN_ALIAS_RID_ADMINS,
		0, 0, 0, 0, 0, 0,
		&AdministratorsGroup);
	if (b) {
		if (!CheckTokenMembership(NULL, AdministratorsGroup, &b)) { b = false; }
		FreeSid(AdministratorsGroup);
	}
	return (bool)b;
}