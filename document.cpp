#include "document.h"
#include <iostream>
#include <fstream>

Document::Document(std::string path, std::string name){
	path_ = path;
	name_ = name;
	output_stream_.open(path_, std::ofstream::app);
	input_stream_.open(path_);
}

Document::~Document(){
	output_stream_.close();
	input_stream_.close();
}

std::ofstream& Document::getOutputStream(){
	return output_stream_;
}

std::ifstream& Document::getInputStream(){
	return input_stream_;
}
    
