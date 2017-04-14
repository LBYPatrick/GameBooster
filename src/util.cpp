#include "GameBooster.h"
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

string util::toUpperString(string str) {
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		*it = (char)toupper(*it);
	return str;
}

void util::visualTimer(std::string message, unsigned int currentTime,unsigned int totalTime) {
	system("cls");
	cout << message << "\n[";
	currentTime++;
	for (int i = 0; i <= (currentTime); i++) {
		cout << ">";
	} for (int i = 0; i < (totalTime - currentTime); i++) {
		cout << " ";
	}

	cout << "] " << totalTime-currentTime << " seconds";
	if (currentTime == totalTime) {
		cout << "\n\n\n";
	}
}

void util::highPriority(string processName) {
	char executor[128];
	sprintf(executor, "wmic process where \"name='%s'\" call setpriority 128 > nul", processName);
	system(executor);
}

