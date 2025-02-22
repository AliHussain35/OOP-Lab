#include<iostream>
#include<string>
using namespace std;
//Composition
class Battery{
	public:
		int size;
		
};
class Smartphone{
	string name;
	Battery battery;
	public:
		Smartphone(string n, int s){
			name = n;
			battery.size = s;
		}
		void displayinfo(){
			cout<<"Smart Phone name = "<<name<<endl;
			cout<<"Battery (in mAH) = "<<battery.size<<endl;
		}
};
int main(){
	Smartphone s1("Samsung", 10000);
	s1.displayinfo();
}
