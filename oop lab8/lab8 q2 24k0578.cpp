#include <iostream>
#include<string>
class Manager;
using namespace std;
class Book{
	string title;
	float price;
	friend class Manager;
	public:
		Book(string t, float p) : title(t), price(p){
		}
		
};
class Manager{
	string name;
	public:
		Manager(string n) : name(n){
		}
		
		void viewDetails(Book b){
			cout<<"Book title = "<<b.title<<endl;
			cout<<"Book price = $"<<b.price<<endl;
		}
		void applyDiscount(Book &b){
			float discountedPrice = b.price*0.8;
			cout<<"20% discount applied = $"<<discountedPrice<<endl;
			b.price = discountedPrice;
		}
};
int main() {
	Book b("40 rules of Love",80);
	Manager m("Ali");
	m.viewDetails(b);
	m.applyDiscount(b);
	cout<<"---Updated Details---"<<endl;
	m.viewDetails(b);
return 0;
}
