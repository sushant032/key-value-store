#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <fstream>

void printLine(std::string text);

void parseLine(const std::string& line, std::string& key, std::string& value);

#endif  // COMMON_H
