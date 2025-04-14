#include<iostream>
#include<string>
using namespace std;
class PaymentMethod{
	public:
		PaymentMethod(){
		}
		virtual void processPayment(double amount) = 0;
};
class CreditCard : public PaymentMethod{
	private:
		string cardNumber;
		double accLimit;
	public:
		CreditCard(string n, double l) : PaymentMethod(){
			cardNumber = n;
			accLimit = l;
		}
		void processPayment(double amount){
			if(amount>accLimit){
				cout<<"Payment failed as it was beyond account limit"<<endl;
			}
			else{
				cout<<"Payment successful of amount = $"<<amount<<endl;
				cout<<"From Card number = "<<cardNumber<<endl;
			}
		}
};
class DigitalWallet : public PaymentMethod{
	private:
		string Username;
		double balance;
	public:
		DigitalWallet(string n, double b) : PaymentMethod(){
			Username = n;
			balance = b;
		}
		void processPayment(double amount){
			if(amount>balance){
				cout<<"Payment failed due to low funds"<<endl;
			}
			else{
				cout<<"Payment successful of amount = $"<<amount<<endl;
				cout<<"From wallet of user = "<<Username<<endl;
			}
		}
};
int main(){
	CreditCard hbl("110019193", 10000);
	DigitalWallet sadapay("Ali Hussain", 20000);
	cout<<"Checking Credit Card object"<<endl;
	hbl.processPayment(2000);
	cout<<"Checking Digital Wallet Object"<<endl;
	sadapay.processPayment(4300000);
}

