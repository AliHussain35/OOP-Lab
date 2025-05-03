#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
int main(){
	ifstream file1("largelog.txt");
	string line;
	file1.read((char*)&line, 10);
	streampos pos = file1.tellg();
	cout<<"Current position = "<<pos<<endl;
	string line1;
	file1.read((char*)&line1, 10);
	streampos pos1 = file1.tellg();
	cout<<"Position now = "<<pos1<<endl;
	file1.close();
}
