#include<iostream>
#include<string>
using namespace std;
class Person{
	public:
		string name;
		int age;
		Person(string n, int a){
			name = n;
			age = a;
		}
		void displayDetails(){
			cout<<"Person name = "<<name<<endl;
			cout<<"Person age = "<<age<<endl;
		}
};
class Teacher : virtual public Person{
	public:
		string subject;
		Teacher(string n, int a, string s) : Person(n, a), subject(s){
		}
		void displayDetails(){
			Person :: displayDetails();
			cout<<"Subject = "<<subject<<endl;
		}
};
class Researcher : virtual public Person{
	public:
		string researchArea;
		Researcher(string n, int a, string r) : Person(n, a), researchArea(r){
		};
		void displayDetails(){
			Person :: displayDetails();
			cout<<"Research Area = "<<researchArea<<endl;
		}
};
class Professor : public Teacher, public Researcher{
	public:
		int publications;
		Professor(string n, int a, string s, string r, int p) : Person(n, a), Teacher(n, a, s), Researcher(n, a, r), publications(p){
		}
		void displayDetails(){
			Teacher::displayDetails();
			cout<<"Researcher = "<<researchArea<<endl;
			cout<<"Number of Publications = "<<publications<<endl;
		}
};
int main(){
	string n, s, r;
	int a, p;
	cout<<"Enter Name = "<<endl;
	getline(cin, n);
	cout<<"Enter age = "<<endl;
	cin>>a;
	cin.ignore();
	cout<<"Enter Subject = "<<endl;
	getline(cin, s);
	cout<<"Enter Research Area = "<<endl;
	getline(cin, r);
	cout<<"Enter number of publications = "<<endl;
	cin>>p;
	Professor p1(n, a, s, r, p);
	p1.displayDetails();
	
}

