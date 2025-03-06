#include<iostream>
#include<string>
using namespace std;
class Account{
	public:
		int accountNumber;
		float balance;
		Account(int a, float b){
			accountNumber = a;
			balance = b;
		}
		void displayDetails(){
			cout<<"Account number = "<<accountNumber<<endl;
			cout<<"Balance = $"<<balance<<endl;
		}
};
class SavingsAccount : public Account{
	public:
		float interestRate;
		SavingsAccount(int a, float b, float i) : Account(a, b), interestRate(i){
		};
		void displayDetails(){
			Account :: displayDetails();
			cout<<"Interest Rate = "<<interestRate<<"%"<<endl;
		}
};
class CheckingAccount : public Account{
	public:
		float overdraftLimit;
		CheckingAccount(int a, float b, float l) : Account(a, b), overdraftLimit(l){
		};
		void displayDetails(){
			Account :: displayDetails();
			cout<<"Over Draft Limit = "<<overdraftLimit<<endl;
		}
};
int main(){
	int a;
	float b, i, l;
	cout<<"Enter your account number = "<<endl;
	cin>>a;
	cout<<"Enter balance = (in $)"<<endl;
	cin>>b;
	int choice; 
	int flag =1; 
	do{
		cout<<"What do you want = 1. Savings account, 2. Checking account "<<endl;
	    cin>>choice;
	    if(choice==1){
		cout<<"Enter Interest rate = (in % )"<<endl;
		cin>>i;
		SavingsAccount s1(a, b, i);
		s1.displayDetails();
		flag = 0;
	    }
	    else if(choice == 2){
		cout<<"Enter over draft limit = "<<endl;
		cin>>l;
		CheckingAccount a1(a, b, l);
		a1.displayDetails();
		
	    }
	}while(flag==1);
	
}
