#include<iostream>
#include<string>
using namespace std;
class Employee{
	public:
		string name;
		float salary;
		Employee(string n, float s){
			name = n;
			salary = s;
		}
		void displaydetails(){
			cout<<"Employee Name = "<<name<<endl;
			cout<<"Salary = $"<<salary<<endl;
		}
};
class Manager : public Employee{
	public:
		float bonus;
		Manager(string n, float s, float b) : Employee(n, s), bonus(b){
		}
		void display(){
			cout<<"Employee Name = "<<name<<endl;
			cout<<"Salary = $"<<salary<<endl;
			cout<<"Bonus = $"<<bonus<<endl;
		}
};
int main(){
	float b, s;
	string n;
	cout<<"Enter Name of manager = "<<endl;
	getline(cin, n);
	cout<<"Enter salary of manager = (in $)"<<endl;
	cin>>s;
	cout<<"Enter bonus of manager = (in $)"<<endl;
	cin>>b;
	Manager m1(n, s, b);
	m1.display();
}
