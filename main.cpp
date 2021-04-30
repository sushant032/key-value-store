#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "document.h"
#include "common.h"
#include "csvdb.h"
#include "db.h"

/*
*  multiple databases/documents + map
*  key auto complition
*  use Btree to store data in IOUtils and serialize/deserialize it
*  automatic checkpointing
*  caching of keys
*  distributed database
*  code cleanup
**/

void printMenu(){
    printLine("Select one of the options");
    printLine("1. Create a key-value pair");
    printLine("2. Read a key-value pair");
}

void readDatabase(CsvDb& db){
    std::string key;
    std::cin >> key;
    std::string value = db.read(key);
	std::cout << value << std::endl;
}

void writeDatabase(CsvDb& db){
    std::string key,value;
    std::cin >> key >> value;
	db.write(key, value);
}

CsvDb getDB(Document& document) {
	CsvDb csv_db;
	csv_db.populate(document.getInputStream());	
	return csv_db;
}


void closeDB(CsvDb& db, Document& document) {
	db.flush_data(document.getOutputStream());
}

void run(CsvDb& db, Document& document){
    printMenu();
    
 	int input;
	std::cin >> input;

    switch(input){
        case 1: 
			writeDatabase(db);
            break;
        case 2:
			readDatabase(db);
            break;
        case 3:
			closeDB(db, document);
			exit(0);
		default:
            printLine("Wrong input.");
    }
}

int main(){
    
    Document document("hello.txt", "hello");
	CsvDb db = getDB(document);
    do{
        run(db, document);
    }while (true);
	
    return 0;
}
