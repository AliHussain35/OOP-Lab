#include<iostream>
#include<string>
using namespace std;
class Vehicle{
	public:
		string brand;
		int speed;
		Vehicle(string b, int s){
			brand = b;
			speed = s;
		}
		void displaydetails(){
			cout<<"Brand name = "<<brand<<endl;
			cout<<"Speed = "<<speed<<endl;
		}
};
class Car : public Vehicle{
	public:
		int seats;
		Car(string b, int s, int seat) : Vehicle(b, s), seats(seat){
		};
		void display(){
			cout<<"Brand name = "<<brand<<endl;
			cout<<"Speed = "<<speed<<endl;
			cout<<"Seats = "<<seats<<endl;
		}
};
class ElectricCar : public Car{
	public:
		int batterylife;
		ElectricCar(string b, int s, int seat, int life) : Car(b, s, seat), batterylife(life){
		};
		void display(){
			cout<<"Brand name = "<<brand<<endl;
			cout<<"Speed = "<<speed<<" km"<<endl;
			cout<<"Seats = "<<seats<<endl;
			cout<<"Battery life = "<<batterylife<<" MAH";
		}
};
int main(){
	ElectricCar tesla("Tesla", 350, 4, 5000);
	tesla.display();
}
