#include "GameBooster.h"
#include "gameList.h"

int welcome(int interval) {
	
	cout<<"Detection Interval:"<<interval<< " Seconds\n\nNow start detection, keep me in the background and start gaming!";
	string boostedPrograms = "";
	while (true) {
		for (int counter = 0; counter < num_games; counter++) {
			bool result = util::lookup(game_processNames[counter]);
			if (result) {
				cout << "\"" << game_names[counter] << "\" Detected!Boosting it now...\n";
				util::highPriority(game_processNames[counter]);
				boostedPrograms += game_names[counter] + " got boosted\n";
			}
		}
		for (int timer = -1; timer < interval; timer++) {
			system("timeout 1 > nul");
			util::visualTimer(boostedPrograms+"\n"+"Next Scan in:",timer,interval);
		}
	}
}
