#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <unistd.h>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include <algorithm>

extern std::string login;

std::vector<std::string> readFileLines(const std::string& filePath);
std::string exec(const char* cmd);
void openBrowser(const std::string& url);
void waitForKeyPress();

void printMenuMandatory();
void printMenuGeneral();
void printMenu();

// General Commands
void gLsFilesInRootFolder();
void gStopDocker();
void gCheckNetworksOrLinks();
void gCheckNoLinkMakefileAndScripts();
void gCheckEntryPoint();
void gCheckEntryPointScripts();
void gCheckInfiniteLoop();

// Mandatory Commands
void mNginxPort443();
void mCheckSSLandTLS();
void mOpenLogin42();
void mCheckDockerfile();
void mCheckKernel();
void mCheckImageName();
void mCheckMakefile();
void mCheckDockerNetwork();
void mDockerComposePs();
void mNginxNotPort80();
void mCheckNoNginxInWP();
void mDockerVolumeLS();
void mCheckOutputPathWP();
void mOpenLoginPage();
void mCheckNoNginxInMariaDB();
void mCheckOutputPathMariaDB();