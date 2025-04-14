#include<iostream>
#include<string>
using namespace std;
class Vehicle{
	protected:
		string model;
		double rate;
	public:
		Vehicle(string m, double r) : model(m), rate(r){
		}
		
		virtual double getDailyRate () = 0;
		virtual void displayDetails() = 0;
};

class Car : public Vehicle{
	public:
		Car(string m, double r) : Vehicle(m, r){
		}
		
		double getDailyRate(){
			return rate;
		}
		void displayDetails(){
			cout<<"Car model = "<<model<<endl;
			cout<<"Daily rate = $"<<rate<<endl;
		}
};
class Bike : public Vehicle{
	public:
		Bike(string m, double r) : Vehicle(m, r){
		}
		
		double getDailyRate(){
			return rate;
		}
		void displayDetails(){
			cout<<"Bike model = "<<model<<endl;
			cout<<"Daily rate = $"<<rate<<endl;
		}
};
int main(){
	Car c1("Mercedes G63", 3000);
	Bike b1("Ninja H2R", 1000);
	cout<<"---Details of car---"<<endl;
	c1.getDailyRate();
	c1.displayDetails();
	cout<<"---Details of bike---"<<endl;
	b1.getDailyRate();
	b1.displayDetails();
	
}

