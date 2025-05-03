#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main(){
	ifstream file("vehicles.txt");
	if(!file){
		cerr<<"File cannot be opened";
		exit(1);
	}
	string line;
	while(getline(file, line)){
		if(line.substr(0,2) == "//"){
			continue;
		}
		istringstream iss(line);
		string type, ID, name, year, extra, certification;
		getline(iss, type, ',');
		getline(iss, ID, ',');
		getline(iss, name, ',');
		getline(iss, year, ',');
		getline(iss, extra, ',');
		getline(iss, certification, ',');
		int Year = stoi(year);
		cout<<type<<endl;
		cout<<ID<<endl;
		cout<<name<<endl;
		cout<<Year<<endl;
		cout<<extra<<endl;
		cout<<certification<<endl;
		
	}
	file.close();
}

