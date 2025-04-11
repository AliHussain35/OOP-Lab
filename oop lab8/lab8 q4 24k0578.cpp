#include <iostream>
#include<string>
using namespace std;
class Currency {
	int value;
	public:
	Currency(int v) : value(v){}
	
	Currency operator-(const Currency& c) {
		return Currency(value-c.value);
	}
	
	Currency operator+(const Currency& c) {
		return Currency(value+c.value);
	}
	
	Currency operator-() {
		return Currency(-value);
	}
	
	void operator+=(const Currency& c) {
		value+=c.value;
	}
	void operator-=(const Currency& c) {
		value-=c.value;
	}
	friend ostream& operator<<(ostream& out, const Currency& c){
		out<<c.value;
		return out;
	}
};

int main() {
	Currency Dollar(100);
	int money;
	cout<<"Current Money = $"<<Dollar<< endl;
	while(1) {
		int choice;
		cout<<"1) Spend Money, 2) Earn Money, What you want to do = "<<endl;
		cin>>choice;
		if(choice==1) {
			cout<<"How Much Money you want to Spend = ";
			cin>>money;
			Currency tempMoney(money);
			Dollar-=tempMoney;
			cout<<"Money Gained =  $"<<-tempMoney<<endl;
			cout<<"Remaining Money = $"<<Dollar<<endl;
		}
		else if(choice==2) {
			cout<<"How Much Money you want to Earn = ";
			cin>>money;
			Currency tempMoney(money);
			Dollar = Dollar + tempMoney;
			cout<<"Money Gained =  $"<<tempMoney<<endl;
			cout<<"Remaining Money =  $"<<Dollar<<endl;
		}
		else {
			cout<<"---Exiting---"<<endl;
			break;
		}
	}
    return 0;
}
