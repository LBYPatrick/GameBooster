#include "util.h"
#include "processList.h"
#include "language.h"
#include <windows.h>
#include <fstream>

using namespace std;

string initialBoostMessage;
string boostedPrograms = "";
string boostedPrograms_buf = "Empty";
string detectionIntervalMessage;
string initMessage;
string detectMessage;
string detectedMessage;
string boostedMessage;
string nextScanMessage;
string startDetectionMessage;
string finishDetectionMessage;
string excludedPrograms = "";




void initBoost() {
	
	util::lookupInit(); //Generate a tasklist

	util::visualProgress(initialBoostMessage, -1, num_negativeProcesses); //Show progress

	for (int i = 0; i < num_negativeProcesses; ++i) {
		if (util::lookup(negativeProgram_processes[i])) {
			util::visualProgress(initialBoostMessage, i - 1, num_negativeProcesses);
			util::lowPriority(negativeProgram_processes[i]); //Set negative-impact programs to low priority
		}
	}
	util::visualProgress(initialBoostMessage, num_negativeProcesses - 1, num_negativeProcesses);
	util::lookupCleanup();
}

void preBoost() {

	for(unsigned int i = 0; i < num_blacklistPrograms; ++i){
		bool result = util::lookup(blacklistPrograms[i]);
		if(result) {
			util::killTask(blacklistPrograms[i]);
		}
		else {continue;};
	}

}



void scanGames() {

	for (unsigned int counter = 0; counter < num_games; ++counter) {

		bool result = util::lookup(game_processNames[counter]); //Would return 1 if the process exists in the tasklist
		
		if (result) {
			if (excludedPrograms.find(game_processNames[counter]) != std::string::npos) continue; //If this program had been boosted already, skip.

			if (excludedPrograms.find(game_processNames[counter]) == std::string::npos) { 
				
				//Show the current progress for scanning
				util::visualProgress(detectMessage + " " + game_names[counter] + "...", counter - 1, num_games); 
				printf("\n\"%s\" %s\n",
					game_names[counter].c_str(),
					detectedMessage.c_str()
				);

				//Set the process to high priority
				util::highPriority(game_processNames[counter]);
				boostedPrograms +=
					util::getCurrentTime()
					+ " \""
					+ game_names[counter]
					+ "\" "
					+ boostedMessage;
				
				//Add this process to the exclude list, so that next time it would be skipped
				excludedPrograms +=
					game_processNames[counter]
					+ "\n";
			}
		}
	}
}

void postBoost() {
	

	if (boostedPrograms != boostedPrograms_buf && boostedPrograms != "") {
		ofstream writeToLog;
		writeToLog.open("Boost.log", ios::app);
		
		writeToLog << "Update on:  "
		<<util::getCurrentTime()
		<<"\n"
		<<"======================================================="
		<<"\n\n";
		
		writeToLog << boostedPrograms;
		writeToLog << "\n\n\n";
		writeToLog.close();
	}
    //Store the current list of boosted programs, if there is no change next time, this function would not write anything to the log
	boostedPrograms_buf = boostedPrograms;
	
}

int welcome(int interval, bool DebugMode, bool toRunAdminCheck) {
	
	if (toRunAdminCheck) {
		if (!util::isUserAdmin()) {
			printf("[Error] You need to run this program as Administrator for all functions to run properly.\n");
			Sleep(2000);
			return 0;
		}
	}
	initBoost();
	system("cls");

	printf("%s%d %s",
		detectionIntervalMessage.c_str(),
		interval,
		initMessage.c_str());
	system("timeout 5 > nul");
	
	//Detection+Executing Boost
	while (true) {
		
		util::lookupInit();
		//Kill some junky background tasks...
		preBoost();
		util::visualProgress(startDetectionMessage, 0, num_games);
		//Start scanning games...	
		scanGames();
		
		util::visualProgress(finishDetectionMessage,num_games-1,num_games);
		util::lookupCleanup();
		system("cls");
		//write logs to Boost.log...
		postBoost();
		

	//Waiting for Next Scan
		for (int timer = 0; timer < interval; ++timer) {
			util::visualTimer(nextScanMessage,timer,interval);
			printf("\n\n");
			printf(boostedPrograms.c_str());
			Sleep(1000);
		}
	}
}
