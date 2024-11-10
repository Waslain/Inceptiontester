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
			if (command[pos - 1] == '-')
				continue;
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

void openBrowser(const std::string& url) {
	std::string command = "xdg-open " + url;
	system(command.c_str());
}

void waitForKeyPress() {
	std::cout << "Press any key to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
	std::cin.get(); // Wait for a key press
}

void printMenuMandatory()
{
	system("clear");
	std::cout << "Basic Setup" << std::endl;
	std::cout << "	1) Check nginx accessed port 443 only" << std::endl;
	std::cout << "	2) Check SSL/TLS is used" << std::endl;
	std::cout << "	3) Open login.42.fr (shouldn't work)" << std::endl;
	std::cout << "Basic Docker Setup" << std::endl;
	std::cout << "	4) Check one Dockerfile per docker and Dockerfiles not empty" << std::endl;
	std::cout << "	5) Check kernel used is penultimate stable version" << std::endl;
	std::cout << "	6) Check Image name is the same as the service name" << std::endl;
	std::cout << "	7) Makefile build with dockercompose only" << std::endl;
	std::cout << "Docker Network" << std::endl;
	std::cout << "	8) Check docker-network in docker-compose then do 'docker network ls'" << std::endl;
	std::cout << "Nginx" << std::endl;
	std::cout << "	9) Do 'docker compose ps'" << std::endl;
	std::cout << "	10) Open " << login << ".42.fr with port 80" << std::endl;
	std::cout << "	11) Open " << login << ".42.fr and do Ctrl + I to open info (should see tls encrypted)" << std::endl;
	std::cout << "WordPress" << std::endl;
	std::cout << "	12) Check no NGINX in wordpress Dockerfile" << std::endl;
	std::cout << "	13) Do 'docker compose ps'" << std::endl;
	std::cout << "	14) Check volume, do 'docker volume ls'" << std::endl; 
	std::cout << "	15) Check output path" << std::endl;
	std::cout << "	16) Open " << login << ".42.fr/wp-login.php" << std::endl;
	std::cout << "MariaDB" << std::endl;
	std::cout << "	17) Check no NGINX in mariadb Dockerfile" << std::endl;
	std::cout << "	18) Do 'docker compose ps'" << std::endl;
	std::cout << "	19) Check output path" << std::endl;
	std::cout << "	20) Connect to MariaDB, 'docker exec -it mariadb mariadb --user ? -p?'" << std::endl;
	std::cout << std::endl << "21) Exit" << std::endl;
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