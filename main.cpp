#include "include.h"

void Mandatory() {
}

void General() {
	std::map<std::string, std::function<void()>> menuOptions = {
		{"1", gLsFilesInRootFolder},
		{"2", gLsFilesInRootFolder},
		{"3", gStopDocker},
		{"4", gCheckNetworksOrLinks},
		{"5", gCheckNoLinkMakefileAndScripts},
		{"6", gCheckEntryPoint},
		{"7", gCheckEntryPointScripts},
		{"8", gCheckInfiniteLoop},
		{"9", []() { exit(0); }},
		{"n", []() {}}
		};
	std::map<std::string, std::function<void()>>::iterator it = menuOptions.begin();
	int current = 0;
	while (true)
	{
		printMenuGeneral();
		std::string userInput;
		std::cin >> userInput;
		it = menuOptions.find(userInput);
		if (it != menuOptions.end()) {
			if (it->first == "n") {
				current++;
				it = menuOptions.find(std::to_string(current));
				it->second();
			}
			else
			{
				current = it->first[0] - '0';
				it->second();
			}
		} else {
			std::cout << "Invalid input" << std::endl;
		}
	}
}


int main() {
	std::cout << "Bienvendio a la programma de correctionasss de inception, LOL" << std::endl;
	std::cout << "Pleaz, enter el nombre de ce que tu veux faire chef : " << std::endl;
	// sleep(2);
	system("cd ../Inception/");
	while (true) {
		printMenu();
		std::map<std::string, std::function<void()>> menuOptions = {
		{"1", General},
		{"2", Mandatory},
		{"3", []() { exit(0); }}
		};
		std::string userInput;
		std::cin >> userInput;
		// std::getline(std::cin, userInput); for multiple words
		std::map<std::string, std::function<void()>>::iterator it = menuOptions.find(userInput);
		if (it != menuOptions.end()) {
			it->second();
		} else {
			std::cout << "Invalid input" << std::endl;
		}
	}
	return 0;
}