#include <iostream>
#include <fstream>

void printLine(std::string text){
    std::cout << text << std::endl;
}

void parseLine(const std::string& line, std::string& key, std::string& value) {
 	// s.substr(start_index, length)

	int key_length = line.find(',');

	int value_length = line.size() - (key_length + 1);

	key = line.substr(0, key_length);
	
	value = line.substr(line.find(',') + 1, value_length);
}

