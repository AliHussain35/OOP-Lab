#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
int main(){
	fstream file1("config.txt", ios::in | ios::out);
	file1.seekp(5, ios::beg);
	file1<<"XXXXX";
	file1.seekg(0, ios::beg);
	string line;
	getline(file1, line);
	cout<<line;
	file1.close();
}
