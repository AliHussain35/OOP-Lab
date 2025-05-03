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
        if(type=="HybridTruck"){
			int index = extra.find(':');
			if(index == string :: npos){
				cout<<"Error";
				continue;
			}
            int index2 = extra.find('|');
            if(index2 == string :: npos){
				cout<<"Error";
				continue;
			}
            int l1 = index2-index;
			string c = extra.substr(index+1, l1);
			int cap = stoi(c);
            int index3 = extra.find(':', index+1);
			if(index3 == string :: npos){
				cout<<"Error";
				continue;
			}
            string s = extra.substr(index3+1);
            int s1 = stoi(s);

			cout<<ID<<endl;
			cout<<cap<<endl;
            cout<<s1<<endl;
		}
		
	}
	file.close();
}

