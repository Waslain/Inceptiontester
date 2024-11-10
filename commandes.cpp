#include "include.h"

void doCommand(const std::string& command) {
	system("clear");
	std::cout << "Command: " << command << std::endl << std::endl;
	std::string output = exec(command.c_str());
	std::cout << output << std::endl;
	waitForKeyPress();
}

void doCommandNoColor(const std::string& command) {
	system("clear");
	std::cout << "Command: " << command << std::endl << std::endl;
	std::string output = execNoColor(command.c_str());
	std::cout << output << std::endl;
	waitForKeyPress();
}

void gLsFilesInRootFolder() {
	doCommand("ls -C");
}

void gStopDocker() {
	doCommandNoColor("docker stop $(docker ps -qa); docker rm $(docker ps -qa); docker rmi -f $(docker images -qa); docker volume rm $(docker volume ls -q); docker network rm $(docker network ls -q) 2>/dev/null");
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

void mNginxPort443()
{
	std::string loginurl =  login + ".42.fr";
	doCommand("nc -zv " + loginurl + " 1-65535");
	std::string url = "https://" + loginurl;
	openBrowser(url + ":443");
	openBrowser(url + ":80");
}

void mCheckSSLandTLS()
{
	doCommand("cat srcs/requirements/nginx/conf/nginx.conf | grep -Ei 'ssl|tls'");
}

void mOpenLogin42()
{
	std::string url = "https://login.42.fr";
	openBrowser(url);
}

void mCheckDockerfile()
{
	doCommand("find srcs -name 'Dockerfile' -ls | awk '{print $7, $8, $9, $10, $11}'");
}

void mCheckKernel()
{
	doCommand("find srcs -name 'Dockerfile' -exec grep FROM {} +");
}

void mCheckImageName()
{
	doCommand("grep image srcs/docker-compose.yml");
}

void mCheckMakefile()
{
	doCommand("cat Makefile");
}

void mCheckDockerNetwork()
{
	doCommand("grep network srcs/docker-compose.yml -A1");
	doCommand("docker network ls");
}

void mDockerComposePs()
{
	doCommand("docker compose -f srcs/docker-compose.yml ps");
}

void mNginxNotPort80()
{
	std::string loginurl =  login + ".42.fr";
	std::string url = "https://" + loginurl;
	openBrowser(url + ":80");
}

void mOpenWebPage()
{
	std::string url = "https://" + login + ".42.fr";
	openBrowser(url);
}

void mCheckNoNginxInWP()
{
	doCommand("grep nginx srcs/requirements/wordpress/Dockerfile");
}

void mDockerVolumeLS()
{
	doCommand("docker volume ls");
}

void mCheckOutputPathWP()
{
	doCommand("docker volume inspect srcs_wordpress | grep home");
}

void mOpenLoginPage()
{
	std::string loginurl =  login + ".42.fr";
	std::string url = "https://" + loginurl + "/wp-login.php";
	openBrowser(url);
}

void mCheckNoNginxInMariaDB()
{
	doCommand("grep nginx srcs/requirements/mariadb/Dockerfile");
}

void mCheckOutputPathMariaDB()
{
	doCommand("docker volume inspect srcs_mariadb | grep home");
}