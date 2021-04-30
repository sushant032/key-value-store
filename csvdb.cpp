#include "csvdb.h"
#include <iostream>
#include <fstream>
#include "common.h"

std::string CsvDb::read(std::string key) {
	for (const auto& line : lines)
	{
		std::string cur_key, cur_value;
  		parseLine(line, cur_key, cur_value);
		printLine("reading");
		std::cout << cur_key << " " << cur_value << std::endl;

		if(cur_key==key){
			return cur_value;
		}
	}
	return "";
}

void CsvDb::write(std::string key, std::string value) {
	lines.push_back(key + "," + value);
	printLine("writing");
	std::cout << lines.size() << std::endl;
	std::cout << key << " " << value << std::endl;
}

int CsvDb::remove(std::string key) {
  return 0;
}

void CsvDb::populate(std::ifstream& input_stream) {
	std::string line;
	while (std::getline ( input_stream, line) ) {
		lines.push_back(line);
		printLine("populating" + line);
    }	
}

void CsvDb::flush_data(std::ofstream& output_stream) {
	for (auto line : lines) {
		output_stream << line << "\n";
		output_stream.flush();
		printLine("appending" + line);
    }	
}
