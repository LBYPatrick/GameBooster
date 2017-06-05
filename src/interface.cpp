#include "GameBooster.h"
#include "processList.h"
#include "language.h"
string initialBoostMessage;
string boostedPrograms = "";
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
	util::enhancedLookupInit();
	util::visualProgress(initialBoostMessage, -1, num_negativeProcesses);
	for (int i = 0; i < num_negativeProcesses; ++i) {
		if (util::enhancedLookup(negativeProgram_processes[i])) {
			util::visualProgress(initialBoostMessage, i - 1, num_negativeProcesses);
			util::lowPriority(negativeProgram_processes[i]);
		}
	}
	util::visualProgress(initialBoostMessage, num_negativeProcesses - 1, num_negativeProcesses);
	util::enhancedLookupCleanup();
}

void preBoost() {

	for(unsigned int i = 0; i < num_blacklistPrograms; ++i){
		bool result = util::enhancedLookup(blacklistPrograms[i]);
		if(result) {
			util::killTask(blacklistPrograms[i]);
		}
		else {continue;};
	}

}



void scanGames() {

	for (unsigned int counter = 0; counter < num_games; ++counter) {

		bool result = util::enhancedLookup(game_processNames[counter]);
		
		if (result) {
			if (excludedPrograms.find(game_processNames[counter]) != std::string::npos) continue;

			else {
				util::visualProgress(detectMessage + " " + game_names[counter] + "...", counter - 1, num_games);

				printf("\n\"%s\" %s\n",
					game_names[counter].c_str(),
					detectedMessage.c_str()
				);

				util::highPriority(game_processNames[counter]);
				boostedPrograms +=
					util::getCurrentTime()
					+ " \""
					+ game_names[counter]
					+ "\" "
					+ boostedMessage;
				
				excludedPrograms +=
					game_processNames[counter]
					+ "\n";
			}
		}
	}
}

void postBoost() {
	ofstream writeToLog;
	writeToLog.open("Boost.log", ios::app);
	writeToLog << boostedPrograms;
	writeToLog.close();
}

int welcome(int interval) {
	
	initBoost();
	system("cls");

	printf("%s%d %s",
		detectionIntervalMessage.c_str(),
		interval,
		initMessage.c_str());
	system("timeout 5 > nul");
	
	//Detection+Executing Boost
	while (true) {
		
		util::enhancedLookupInit();
		//Kill some junky background tasks...
		preBoost();
		util::visualProgress(startDetectionMessage, 0, num_games);
		//Start scanning games...	
		scanGames();
		
		util::visualProgress(finishDetectionMessage,num_games-1,num_games);
		util::enhancedLookupCleanup();
		system("cls");
		//write logs to Boost.log...
		postBoost();
		

	//Waiting for Next Scan
		for (int timer = 0; timer < interval; ++timer) {
			util::visualTimer(nextScanMessage,timer,interval);
			printf("\n\n");
			printf(boostedPrograms.c_str());
			system("timeout 1 > nul");
		}
	}
}
