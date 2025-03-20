#include<iostream>
#include<string>
using namespace std;
class Media{
	protected:
		string title;
		string publicationDate;
		int uniqueID;
		string publisher;
		bool isAvailable;
	public:
		Media(string t, string d, int u, string p){
			title = t; 
			publicationDate = d;
			uniqueID = u;
			publisher = p;
			isAvailable = true;
		}
		void displayInfo(){
			cout<<"Title = "<<title<<endl;
			cout<<"ID = "<<uniqueID<<endl;
			cout<<"Publication date = "<<publicationDate<<endl;
			cout<<"Publisher = "<<publisher<<endl;
		}
		//overloading
		void displayInfo(int ID){
			cout<<"Title = "<<title<<endl;
			cout<<"Publication date = "<<publicationDate<<endl;
			cout<<"Publisher = "<<publisher<<endl;
			
		}
		void checkOut(){
			if(isAvailable==true){
				isAvailable = false;
				cout<<"CheckedOut"<<endl;
			}
			else{
				cout<<"Not present, Already Checked out"<<endl;
			}
		}
		void returnItem(){
			isAvailable = true;
			cout<<"Item returned successfully"<<endl;
		}
};
class Book : public Media{
	string author;
	int ISBN;
	int numofPages;
	public:
		Book(string t, string d, int u, string p, string a, int I, int n) : Media(t, d, u, p) {
			author = a;
			ISBN = I;
			numofPages = n;
		}
		void displayInfo(int Isbnid){
			if(ISBN==Isbnid){
				Media :: displayInfo();
				cout<<"Author = "<<author<<endl;
				cout<<"ISBN number = "<<ISBN<<endl;
				cout<<"Num of pages = "<<numofPages<<endl;
			}
			else{
				cout<<"Sorry book not present"<<endl;
			}
		}
		
};
class DVD : public Media{
	string director;
	int duration;//in hours
	int rating;
	public:
		DVD(string t, string d, int u, string p, string dir, int dur, int r) : Media(t, d, u, p) {
			director = dir;
			duration = dur;
			rating = r;
		}
		void displayInfo(string direct){
			if(director==direct){
				Media :: displayInfo();
				cout<<"Director = "<<director<<endl;
				cout<<"Duration = "<<duration<<" hours"<<endl;
				cout<<"Rating = "<<rating<<endl;
			}
			else{
				cout<<"Sorry DVD not present"<<endl;
			}
		}
		
};
class CD : public Media{
	string artist;
	int numofTracks;//in hours
	string genre;
	public:
		CD(string t, string d, int u, string p, string a, int numoft, string g) : Media(t, d, u, p) {
			artist = a;
			numofTracks = numoft;
			genre = g;
		}
		void displayInfo(string a){
			if(artist==a){
				Media :: displayInfo();
				cout<<"Artist = "<<artist<<endl;
				cout<<"Number of Tracks = "<<numofTracks<<endl;
				cout<<"Genre = "<<genre<<endl;
			}
			else{
				cout<<"Sorry CD not present"<<endl;
			}
		}
};
class Magazine : public Media{
	string editor;
	int Issuenum;//in hours
	string frequency;
	public:
		Magazine(string t, string d, int u, string p, string e, int Inum, string f) : Media(t, d, u, p) {
			editor = e;
			Issuenum = Inum;
			frequency = f;
		}
		void displayInfo(string e){
			if(editor==e){
				Media :: displayInfo();
				cout<<"Editor = "<<editor<<endl;
				cout<<"Issue Number = "<<Issuenum<<endl;
				cout<<"Frequency = "<<frequency<<endl;
			}
			else{
				cout<<"Sorry Magazine not present"<<endl;
			}
		}
};
int main(){
	Media m1("Shiekhani Group", "2024", 555, "Ali Shiekhani");
	//overloading function
	m1.displayInfo(555);
	cout<<endl;
    Book B1("Linear Algebra", "2019", 111, "DOGAR brothers", "Ali Hussain", 12345, 1000);
    DVD D1("IT", "2015", 222, "Warner Bros", "Huzaifa Shahid", 4, 10);
    CD C1("The last night", "2000", 333, "Epic Records", "Abdullah", 9, "Pop");
    Magazine M1("National Geographic", "2000", 444, "National Geographic", "Haris Asim", 130, "Weekly");
    B1.checkOut();
    cout<<endl;
    B1.returnItem();
    cout<<endl;
    B1.displayInfo(12345);
    cout<<endl;
    D1.displayInfo("Huzaifa Shahid");
    cout<<endl;
    C1.displayInfo("Abdullah");
    cout<<endl;
    M1.displayInfo("Haris Asim");
    cout<<endl;
    return 0;
}


