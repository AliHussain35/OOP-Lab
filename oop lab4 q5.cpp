#include<iostream>
#include<string>
using namespace std;
class Book{
	private:
		string title;
		float baseprice;
		int* stock;
		int bookid;
		static int bookcounter;
	public:
		//using this keyword
		Book(string t, float p, int s) : title(t), baseprice(p), bookid(++bookcounter){
			this->stock = new int(s);
		}
		//copy constructor
		Book(Book& book1) : title(book1.title), baseprice(book1.baseprice), bookid(++bookcounter){
			this->stock = new int(*(book1.stock));
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
			cout<<"Book ID = "<<bookid<<endl;
			cout<<"Book title = "<<this->title<<endl;
			cout<<"Book price = $"<<this->baseprice<<endl;
			cout<<"Stock available = "<<*(this->stock)<<endl;
		}
		~Book() {
            delete stock;
        }
};
int Book::bookcounter = 0;

int main(){
	Book book1("Story of Bill Gates", 80.0, 50);
	Book book2(book1);
	book2.purchase(15);
	cout<<"Details of book 1 "<<endl;
	book1.displaydetails();
	cout<<"Details of book 2 "<<endl;
	book2.displaydetails();
	return 0;
}
