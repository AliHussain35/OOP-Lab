#include<iostream>
#include<string>
using namespace std;
class Car{
	public:
		int regnum;
		string model;
		string ownername;
	public:
		Car(int r, string m, string n){
			regnum = r;
			model = m;
			ownername = n;
		}
		Car(Car &carobj, string newname){
			regnum = carobj.regnum;
			model = carobj.model;
			ownername = newname;
		}
		void Displaycar(){
			cout<<"Registration num = "<<regnum<<endl;
			cout<<"Model name = "<<model<<endl;
			cout<<"Owner name = "<<ownername<<endl;
		}
};
int main(){
	Car car1(110, "city", "Ali");
	Car car2(car1, "Ahmed");
	car2.Displaycar();
}