#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <fstream>
#include <iostream>
#include "csvdb.h"

class Document{
    public:
        Document(std::string path, std::string name);
        
        ~Document();

        std::ofstream& getOutputStream();

        std::ifstream& getInputStream();
    
    private:
        std::string path_;
        std::string name_;
        std::ofstream output_stream_;
        std::ifstream input_stream_;
};

// Document -> input, output streams -> map<key, value>
// First time read -> map, B-Tree, write()
// Serialization, Deserialization
// file store -> key,value
// read(), write(), delete()

#endif // DOCUMENT_H
