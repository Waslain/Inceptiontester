#include "include.h"

void doCommand(const std::string& command) {
	system("clear");
	std::cout << "Command: " << command << std::endl << std::endl;
	std::string output = exec(command.c_str());
	std::cout << output << std::endl;
	waitForKeyPress();
}

void gLsFilesInRootFolder() {
	doCommand("ls -C");
}

void gStopDocker() {
	doCommand("docker stop $(docker ps -qa); docker rm $(docker ps -qa); docker rmi -f $(docker images -qa); docker volume rm $(docker volume ls -q); docker network rm $(docker network ls -q) 2>/dev/null");
}

void gCheckNetworksOrLinks() {
	doCommand("cat srcs/docker-compose.yml | grep -E 'network: host|links:'");
	doCommand("cat srcs/docker-compose.yml | grep 'network' -A 1");
}

void gCheckNoLinkMakefileAndScripts() {
	doCommand("cat Makefile | grep link");
	doCommand("find srcs -name '*.sh' -exec cat {} + | grep link");
}

void gCheckEntryPoint() {
	doCommand("find srcs -name 'Dockerfile' -exec grep ENTRYPOINT {} +");
}

void gCheckEntryPointScripts() {
	doCommand("cat srcs/requirements/wordpress/tools/wpscript.sh");
	doCommand("cat srcs/requirements/mariadb/tools/dbscript.sh");
} 

void gCheckInfiniteLoop() {
	doCommand("find srcs -name '*.sh' -exec grep -E 'sleep infinity|tail -f /dev/null|tail -f /dev/random' {} +");
}