#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class FileException: public exception{
    public: 
        virtual const char* what ()const noexcept override{
            return "FileException - File not found or Access denied!";
        }
};
class FileNotFoundException: public FileException{
    public: 
        const char* what ()const noexcept override{
            return "File not found!";
        }
};
class PermissionDeniedException: public FileException{
    public: 
        const char* what ()const noexcept override{
            return "Access denied!";
        }
};

void readFile(const string &file1){
    ifstream file;
    file.open(file1);
    if(!file.is_open()){
        throw FileNotFoundException();
    }else if(file1 == "secret.txt"){
        throw PermissionDeniedException();
    }
    file.close();
}

int main(){
    string fileName = "secret.txt";
    try {
        readFile(fileName);
    } 
    catch (const FileException &e){
        cout<<"Reading '"<<fileName<<"' =  "<<e.what()<<endl;
    }
}
