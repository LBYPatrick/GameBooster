#include<string>
#include "util.h"
using std::string;
extern string initialBoostMessage;
extern string boostedPrograms;
extern string detectionIntervalMessage;
extern string initMessage;
extern string detectMessage;
extern string detectedMessage;
extern string boostedMessage;
extern string nextScanMessage;
extern string startDetectionMessage;
extern string finishDetectionMessage;
extern string excludedPrograms;

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