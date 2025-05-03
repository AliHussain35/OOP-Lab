#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	ifstream file("vehicles.txt");
	if(!file){
		cerr<<"File cannot be opened";
		exit(1);
	}
	string line;
	while(getline(file, line)){
		cout<<line<<endl;
	}
	file.close();
}
