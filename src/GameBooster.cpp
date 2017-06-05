#include "GameBooster.h"
#include "language.h"

int main(int argc, const char * argv[]) {
	switch (argc) {
	case 0:
	case 1:
		languageSwitcher();
		welcome();
		return 0;
	case 2:
	case 3:
		int argument;
		sscanf(argv[2], "%u", &argument);
		if (util::toUpperString(argv[1]).compare("--INTERVAL") == 0 || util::toUpperString(argv[1]).compare("-I") == 0) 
			languageSwitcher();
			welcome(argument);
			return 0;
	default: return 0;
	}	
}