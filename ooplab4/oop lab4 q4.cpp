
#include<iostream>
#include<string>
using namespace std;
class Book{
	private:
		string title;
		float baseprice;
		int* stock;
	public:
		//using this keyword
		Book(string title, float baseprice, int stock){
			this->title = title;
			this->baseprice = baseprice;
			this->stock = new int;  
			*(this->stock) = stock;
		}
		//copy constructor
		Book(Book& book1){
			this->title= book1.title;
			this->baseprice = book1.baseprice;
			this->stock = new int;
			*(this->stock) = *(book1.stock);
		}
		void purchase(int q){
			float bill;
			if(q>*(this->stock)){
				cout<<"Error"<<endl;
				cout<<"Available stock is not enough for the purchase"<<endl;
				return;
			}
			else{
				//bulkpurchase
				if(q>20){
					bill = (this->baseprice)*q;
					bill = bill*0.80;
					*(this->stock) = *(this->stock) -q;
					cout<<"20% discount applied as you purchased in bulk (more than 20 books)"<<endl;
					cout<<"Total bill = $"<<bill<<endl;
					return;
				}
				else if(q>10 && q<=20){
					bill = (this->baseprice)*q;
					bill = bill*0.90;
					*(this->stock) = *(this->stock) -q;
					cout<<"10% discount applied as you purchased more than 10 books"<<endl;
					cout<<"Total bill = $"<<bill<<endl;
				}
			}
		}
		void displaydetails(){
			cout<<"Book title = "<<this->title<<endl;
			cout<<"Book price = $"<<this->baseprice<<endl;
			cout<<"Stock available = "<<*(this->stock)<<endl;
		}
		~Book() {
            delete stock;
        }
};
int main(){
	Book book1("Data structures", 30.0, 80);
	Book book2(book1);
	book2.purchase(25);
	cout<<"Details of book 1 "<<endl;
	book1.displaydetails();
	cout<<"Details of book 2 "<<endl;
	book2.displaydetails();
	return 0;
}
