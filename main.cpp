#include "include.h"

std::string login;

void Mandatory() {
	std::map<std::string, std::function<void()>> menuOptions = {
		{"1", mNginxPort443},
		{"2", mCheckSSLandTLS},
		{"3", mOpenLogin42},
		{"4", mCheckDockerfile},
		{"5", mCheckKernel},
		{"6", mCheckImageName},
		{"7", mCheckMakefile},
		{"8", mCheckDockerNetwork},
		{"9", mDockerComposePs},
		{"10", mNginxNotPort80},
		{"11", mOpenWebPage},
		{"12", mCheckNoNginxInWP},
		{"13", mDockerComposePs},
		{"14", mDockerVolumeLS},
		{"15", mCheckOutputPathWP},
		{"16", mOpenLoginPage},
		{"17", mCheckNoNginxInMariaDB},
		{"18", mDockerComposePs},
		{"19", mCheckOutputPathMariaDB},
		{"20", []() {}},
		{"21", []() { exit(0); }},
		{"n", []() {}}
		};
	std::map<std::string, std::function<void()>>::iterator it = menuOptions.begin();
	int current = 0;
	while (true)
	{
		printMenuMandatory();
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
				// current = it->first[0] - '0';
				current = std::stoi(it->first);
				it->second();
			}
		} else {
			std::cout << "Invalid input" << std::endl;
		}
	}
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
	std::cout << "Pleaz, enter el login ke va tu utilizare : " << std::endl;
	std::cin >> login;
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