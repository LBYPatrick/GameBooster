#include "GameBooster.h"

int main(int argc, const char * argv[]) {
	switch (argc) {
	case 0:
	case 1:
		welcome();
		return 0;
	case 2:
	case 3:
		int argument;
		sscanf(argv[2], "%u", &argument);
		if (util::toUpperString(argv[1]).compare("--INTERVAL") == 0 || util::toUpperString(argv[1]).compare("-I") == 0) 
			welcome(argument);
			return 0;
	default: return 0;
	}	
}