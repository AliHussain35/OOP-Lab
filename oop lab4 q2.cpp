#include<iostream>
#include<string>
using namespace std;
class Book{
	private:
		string title;
		float price;
		int* stock;
	public:
		Book(string n, float p, int s){
			title = n;
			price = p;
			stock = new int;
			*stock = s;
		}
		void purchase(int q){
			float bill;
			if(q>*stock){
				cout<<"Error"<<endl;
				cout<<"Available stock is not enough for the purchase"<<endl;
				return;
			}
			else{
				if(q>10){
					bill = price*q;
					bill = bill*0.90;
					*stock = *stock -q;
					cout<<"10% discount applied as you purchased more than 10 books"<<endl;
					cout<<"Total bill = $"<<bill<<endl;
					return;
				}
				else if(q>5 && q<=10){
					bill = price*q;
					bill = bill*0.95;
					*stock = *stock -q;
					cout<<"5% discount applied as you purchased more than 5 books"<<endl;
					cout<<"Total bill = $"<<bill<<endl;
				}
			}
		}
		void displaydetails(){
			cout<<"Book title = "<<title<<endl;
			cout<<"Book price = $"<<price<<endl;
			cout<<"Stock available = "<<*stock<<endl;
		}
		~Book() {
            delete stock;
        }
};
int main(){
	Book book1("40 rules of love", 60.0, 40);
	book1.purchase(12);
	book1.displaydetails();
	return 0;
}
