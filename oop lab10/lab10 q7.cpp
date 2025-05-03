#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
int main(){
	ofstream file1("sensors.txt", ios :: app);
	file1<<"Hello i am ali \n";
	streampos pos = file1.tellp();
	cout<<"Current position = "<<pos<<endl;
	file1<<"Okay bye \n";
	streampos pos1 = file1.tellp();
	cout<<"Position now ="<<pos1<<endl;
	file1.close();
	
	
}
