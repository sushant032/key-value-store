#ifndef DB_H
#define DB_H

#include <iostream>
#include <fstream>

// No default implementation.
class DB {
public:
  virtual void write(std::string key, std::string value) = 0;

  virtual std::string read(std::string key) = 0;

  virtual int remove(std::string key) = 0;

  virtual void populate(std::ifstream& input_stream) = 0;

  virtual ~DB() = default;
};





#endif  // DB_H
