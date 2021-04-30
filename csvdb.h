#ifndef CSV_DB_H
#define CSV_DB_H

#include <iostream>
#include <fstream>
#include <vector>
#include "db.h"

class CsvDb : public DB{
    public:
	  void write(std::string key, std::string value) override;

	  std::string read(std::string key) override;

	  int remove(std::string key) override;
		
	  void populate(std::ifstream& input_stream) override;
		
 	  ~CsvDb() = default;
	  
	  void flush_data(std::ofstream& output_stream);

	std::vector <std::string> lines;
};

#endif  // CSV_DB_H
