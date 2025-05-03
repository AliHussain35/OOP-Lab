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
		if(type=="AutonomousCar"){
			int index = extra.find(':');
			if(index == string :: npos){
				cout<<"Error";
				continue;
			}
			string v = extra.substr(index+1);
			float version = stof(v);
			cout<<ID<<endl;
			cout<<version<<endl;
		}
		if(type=="ElectricVehicle"){
			int index = extra.find(':');
			if(index == string :: npos){
				cout<<"Error";
				continue;
			}
			string c = extra.substr(index+1);
			int cap = stoi(c);
			cout<<ID<<endl;
			cout<<cap<<endl;
		}
		
	}
	file.close();
}

