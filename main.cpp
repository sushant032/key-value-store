#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
*  read a key
*  write a key value pair
*  persistent database
*  multiple databases/documents
*  key auto complition
*  use Btree to store data in IOUtils and serialize/deserialize it
*  automatic checkpointing
*  caching of keys
*  code cleanup
**/

void printLine(std::string text){
    std::cout << text << std::endl;
}

void parseLine(const std::string& line, std::string& key, std::string& value) {
	key = line.substr(0, line.find(','));
	value = line.substr(line.find(','), line.size() - line.find(','));
}

class IOUtils{
    public:
        void readKey(std::ifstream& input_stream, std::string key){
            std::string line;
            while ( std::getline (input_stream,line) )
            {
				std::string cur_key, cur_value;
				parseLine(line, cur_key, cur_value);
                if(cur_key == key) {
                    printLine("Value found: "+ cur_value);
                    return;
                }
            }
            printLine("Key is not present in the DB");
        }

        void writeKeyValue(std::ofstream& output_stream, std::string key, std::string value){
            output_stream<<key+","+value+"\n";
        }
};

class Document{
    public:
        Document(std::string path, std::string name){
            path_ = path;
            name_ = name;
            output_stream_.open(path_, std::ofstream::app);
            input_stream_.open(path_);
        }
        
        ~Document(){
            output_stream_.close();
            input_stream_.close();
        }

        void readKey(std::string key){
            io_utils_->readKey(input_stream_, key);
        }

        void writeKeyValue(std::string key, std::string value){
            io_utils_->writeKeyValue(output_stream_, key, value);
        }

        std::ofstream& getOutputStream(){
            return output_stream_;
        }

        std::ifstream& getInputStream(){
            return input_stream_;
        }
    
    private:
        std::string path_;
        std::string name_;
        std::ofstream output_stream_;
        std::ifstream input_stream_;
        IOUtils *io_utils_;

};


void printMenu(){
    printLine("Select one of the options");
    printLine("1. Create a key-value pair");
    printLine("2. Read a key-value pair");
}

void readDatabase(Document& document){
    std::string key;
    std::cin >> key;
    document.readKey(key);
}

void writeDatabase(Document& document){
    std::string key,value;
    std::cin >> key >> value;
    document.writeKeyValue(key, value);
}

void run(){
    printMenu();
    
    auto readInput = [](){
        int input;
        std::cin >> input;
        return input;
    };
    
    int input = readInput();
    Document document("hello.txt","hello");
    
    switch(input){
        case 1: 
            writeDatabase(document);
            break;
        case 2:
            readDatabase(document); 
            break;
        default:
            printLine("Wrong input.");
    }
}

int main(){
    
    do{
        run();
    }while (true);

    return 0;
}
