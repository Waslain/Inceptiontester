#include "include.h"

std::vector<std::string> readFileLines(const std::string& filePath) {
	std::vector<std::string> lines;
	std::ifstream file(filePath);
	std::string line;
	while (std::getline(file, line)) {
		lines.push_back(line);
	}
	return lines;
}

std::string addColorWhenNeeded(const char *cmd)
{
	std::string command(cmd);
	std::vector<std::string> whitelist = {"ls ", "grep "};
	std::string addcolor = " --color=always ";
	for (std::string &whitelisted : whitelist)
	{
		// std::cout << "whitelisted: " << whitelisted << std::endl;
		if (command.find(whitelisted) != std::string::npos)
		{
			size_t pos = command.find(whitelisted);
			// std::cout << "pos: " << pos << std::endl;
			// std::cout << "substr: " << command.substr(0, pos) << std::endl;
			if (pos != std::string::npos) {
				size_t endPos = pos + whitelisted.length();
				command = command.substr(0, endPos) + addcolor + command.substr(endPos);
				// std::cout << "command: " << command << std::endl;
				return command;
			}
		}
	}
	return command;
}

std::string exec(const char* cmd) {
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(addColorWhenNeeded(cmd).c_str(), "r"), pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}

void waitForKeyPress() {
	std::cout << "Press any key to continue..." << std::endl;
	std::cin.get();
	std::cin.get(); // To handle the newline character left in the buffer
}

void printMenuMandatory()
{
	system("clear");
	std::cout << "1) Read file" << std::endl;
	std::cout << "2) Write file" << std::endl;
	std::cout << "3) Exit" << std::endl;
}

void printMenuGeneral()
{
	system("clear");
	std::cout << "1) All the files required are located inside a srcs folder. The srcs folder must be located at the root of the repository." << std::endl;
	std::cout << "2) Makefile is located at the root of the repository." << std::endl;
	std::cout << "3) Run \"docker stop $(docker ps -qa); docker rm $(docker ps -qa) ... etc\"" << std::endl;
	std::cout << "4) Check no 'network: host' in it or 'links:' and 'network(s)' in docker-compose" << std::endl;
	std::cout << "5) Check no  '--link' in makefile or scripts" << std::endl;
	std::cout << "6) Check no 'tail -f' or 'bash' 'sh' used not for running a script in Dockerfile" << std::endl;
	std::cout << "7) If ENTRYPOINT is a script check that it doesn't run program in background" << std::endl;
	std::cout << "8) Check that all scripts doesn't run an infinite loop" << std::endl;
	std::cout << "9) Exit" << std::endl;
}

void printMenu() {
	system("clear");
	std::cout << "1) General" << std::endl;
	std::cout << "2) Mandatory" << std::endl;
	std::cout << "3) Exit" << std::endl;
}