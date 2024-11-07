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

std::vector<std::string> readFileLines(const std::string& filePath);
std::string exec(const char* cmd);
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