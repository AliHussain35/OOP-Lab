#include <iostream>
#include<string>
using namespace std;
class Currency{
	protected:
		float amount;
		string currencyCode;//like USD DIR PKR
		char currencySymbol;//$ RS
		float exchangeRate; //assuming base currency as INR
	public:
		Currency(float a, string code, char symbol, float r){
			amount = a;
			currencyCode = code;
			currencySymbol = symbol;
			exchangeRate = r;
		}
		virtual void convertToBase(){
			cout<<"Converting to Base Currency"<<endl;
		}
		virtual void convertTo(string targetCurrencyCode){
			cout<<"Converting to target currency"<<endl;
		}
		virtual void displayCurrency(){
			cout<<"Displaying Currency Details"<<endl;
		}
};
class Dollar : public Currency{
	public:
		Dollar(float a, string code, char symbol, float r) : Currency(a, code, symbol, r){
		};
		
		void convertToBase(){
			float a;
			a = amount*exchangeRate;
			cout<<"Amount = $"<<a<<endl;
		}
		void convertTo(string targetCurrencyCode){
			float a;
			if(targetCurrencyCode=="EUR"){
				a = amount*0.91;
				cout<<"Amount in Euros = €"<<a<<endl;
			}
			else if(targetCurrencyCode=="PKR"){
				a = amount*280.25;
				cout<<"Amount in PKR = Rs"<<a<<endl;
			}
			else{
				cout<<"Invalid currency"<<endl;
			}
		}
		void displayCurrency(){
			cout<<"Currency Code = "<<currencyCode<<endl;
			cout<<"Currency Symbol = "<<currencySymbol<<endl;
			cout<<"Exchange rate to base currency = "<<exchangeRate<<endl;
		}
};
class Euro : public Currency{
	public:
		Euro(float a, string code, char symbol, float r) : Currency(a, code, symbol, r){
		};
		
		void convertToBase(){
			float a;
			a = amount*exchangeRate;
			cout<<"Amount = $"<<a<<endl;
		}
		void convertTo(string targetCurrencyCode){
			float a;
			if(targetCurrencyCode=="USD"){
				a = amount*1.09;
				cout<<"Amount in USD = $"<<a<<endl;
			}
			else if(targetCurrencyCode=="PKR"){
				a = amount*306.7;
				cout<<"Amount in PKR = Rs"<<a<<endl;
			}
			else{
				cout<<"Invalid currency"<<endl;
			}
		}
		void displayCurrency(){
			cout<<"Currency Code = "<<currencyCode<<endl;
			cout<<"Currency Symbol = "<<currencySymbol<<endl;
			cout<<"Exchange rate to base currency = "<<exchangeRate<<endl;
		}
};
class Rupee : public Currency{
	public:
		Rupee(float a, string code, char symbol, float r) : Currency(a, code, symbol, r){
		};
		
		void convertToBase(){
			float a;
			a = amount*exchangeRate;
			cout<<"Amount = $"<<a<<endl;
		}
		void convertTo(string targetCurrencyCode){
			float a;
			if(targetCurrencyCode=="USD"){
				a = amount*0.0036;
				cout<<"Amount in USD = $"<<a<<endl;
			}
			else if(targetCurrencyCode=="EUR"){
				a = amount*0.0033;
				cout<<"Amount in EURO = €"<<a<<endl;
			}
			else{
				cout<<"Invalid currency"<<endl;
			}
		}
		void displayCurrency(){
			cout<<"Currency Code = "<<currencyCode<<endl;
			cout<<"Currency Symbol = "<<currencySymbol<<endl;
			cout<<"Exchange rate to base currency = "<<exchangeRate<<endl;
		}
};
int main(){
	Dollar d(100, "USD", '$', 86.84);
	Euro e(50, "EUR", '€', 94.70);     
    Rupee r(5000, "PKR", 'RS', 0.31);
    
    cout<<"Displaying all the currencies"<<endl;
    d.displayCurrency();
    cout<<endl;
    e.displayCurrency();
    cout<<endl;
    r.displayCurrency();
    cout<<endl;
    cout<<"Converting to Base Currency"<<endl;
    d.convertToBase();
    e.convertToBase();
    r.convertToBase();
    
    cout<<"Converting dollar to Pkr"<<endl;
    d.convertTo("PKR");
	
}

