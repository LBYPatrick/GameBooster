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
		initialBoostMessage = "����ִ�г�ʼ����...";
		detectionIntervalMessage = "ɨ����:";
		initMessage = "��\n\n����5���ʼɨ��, �뽫���������ں�̨��Ȼ��ʼ����Ϸ��!";
		detectMessage = "����ɨ�������е���Ϸ...";
		detectedMessage = "���ɹ���⵽!����Ϊ����м���...";
		boostedMessage = "�Ѽ���\n";
		nextScanMessage = "�´�ɨ�� : ";
		startDetectionMessage = "��ʼ���...�����ͷſ�";
		finishDetectionMessage = "������.";
	}
	if (language == "zh_HK"){
		initialBoostMessage = "���ڈ��г�ʼ����...";
		detectionIntervalMessage = "�����g��:";
		initMessage = "��\n\n����5�����_ʼ����, Ո������ʽ��������̨��Ȼ���_ʼ���[���!";
		detectMessage = "���ڒ�������е��[��...";
		detectedMessage = "���ɹ��z�y��!���ڞ����M�м���...";
		boostedMessage = "�Ѽ���\n";
		nextScanMessage = "�´Β��� : ";
		startDetectionMessage = "�_ʼ�z�y...";
		finishDetectionMessage = "�z�y���.";
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