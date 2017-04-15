#include "GameBooster.h"
#include "processList.h"

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


void languageSwitcher() {
	string language = util::detectLanguage();
	if (language == "zh_CN") {
		initialBoostMessage = "正在执行初始加速...";
		detectionIntervalMessage = "扫描间隔:";
		initMessage = "秒\n\n将在5秒后开始扫描, 请将本程序保留在后台，然后开始玩游戏吧!";
		detectMessage = "正在扫描运行中的游戏...";
		detectedMessage = "被成功检测到!正在为其进行加速...";
		boostedMessage = "已加速\n";
		nextScanMessage = "下次扫描 : ";
		startDetectionMessage = "开始检测...请坐和放宽";
		finishDetectionMessage = "检测完成.";
	}
	if (language == "zh_HK"){
		initialBoostMessage = "正在執行初始加速...";
		detectionIntervalMessage = "掃描間隔:";
		initMessage = "秒\n\n將在5秒後開始掃描, 請將本程式保留在後台，然後開始玩遊戲吧!";
		detectMessage = "正在掃描執行中的遊戲...";
		detectedMessage = "被成功檢測到!正在為其進行加速...";
		boostedMessage = "已加速\n";
		nextScanMessage = "下次掃描 : ";
		startDetectionMessage = "開始檢測...";
		finishDetectionMessage = "檢測完成.";
	}
	if (language == "en_US"){
		
		initialBoostMessage = "Initial Boost";
		detectionIntervalMessage = "Detection Interval:";
		initMessage = "Seconds\n\nStart detection in 5 seconds, keep me in the background and start gaming!";
		detectMessage = "Detecting";
		detectedMessage = "Detected!Boosting it now...";
		boostedMessage = "boosted\n";
		nextScanMessage = "Next Scan in : ";
		startDetectionMessage = "Detecting Games...Please sit and relax.";
		finishDetectionMessage = "Detection Complete.";
	}
}

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
