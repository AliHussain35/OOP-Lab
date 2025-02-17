#include<iostream>
#include<string>
using namespace std;
class Book{
	private:
		string title;
		float price;
		int* stock;
	public:
		Book(){
			title = "Unknown";
			price = 0.0;
			stock = new int;
			*stock = 30;
		}
		void updatebookdetails(string n, float p, int s){
			title = n;
			price = p;
			*stock = s;
			cout<<"Book details updated"<<endl;
		}
		void purchasebook(int q){
			if(q>*stock){
				cout<<"Not enough books available in the inventory"<<endl;
				return;
			}
			else{
				*stock = *stock - q;
				cout<<"Books purchased successfully"<<endl;
			}
			
			if(*stock < 5){
				cout<<"WARNING"<<endl;
				cout<<"LOW STOCK AVAILABLE"<<endl;
			}
		}
		void display(){
			cout<<"Book title = "<<title<<endl;
			cout<<"Book price = "<<price<<endl;
			cout<<"Stock = "<<*stock<<endl;
		}
		~Book() {
            delete stock;
        }
};
int main(){
	Book book1;
	book1.updatebookdetails("David copper", 300.0, 30);
	book1.purchasebook(26);
	book1.display();
	return 0;
}
