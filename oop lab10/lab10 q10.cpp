#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
int main(){
	ifstream file1("records.txt");
	file1.seekg(20);
	string line;
	getline(file1, line);
	cout<<line<<endl;
	file1.close();
}
