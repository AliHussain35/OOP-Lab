#include<iostream>
#include<string>
using namespace std;

class Tourguide{
	private:
		string name;
		int yearsofexp;
		string specialization;
	public:
		Tourguide(string n, int exp, string spec) : name(n), yearsofexp(exp), specialization(spec){
		};
		void displaytourguide(){
			cout<<"Name = "<<name<<endl;
			cout<<"Years of experience = "<<yearsofexp<<endl;
			cout<<"Specialization = "<<specialization<<endl;
		}
};
class Travelagency{
	private:
		string name;
		Tourguide** guides;
		int count;
	    int initialcap;
	public:
		Travelagency(string n){
			name = n;
			count = 0;
			initialcap = 2;
			guides = new Tourguide*[initialcap];
		}
		void addtourguide(string n, int years, string s){
			if(count==initialcap){
				int newcap = initialcap*2;
				Tourguide** newguides = new Tourguide*[newcap];
				for(int i=0; i<count; i++){
					newguides[i] = guides[i];
				}
				delete[] guides;
				guides = newguides;
				initialcap = newcap;
			}
			guides[count] = new Tourguide(n, years, s);
			count++;
		}
		void displayguides(){
			for(int i=0; i<count; i++){
				guides[i]->displaytourguide();
				cout<<endl;
			}
		}
		~Travelagency(){
			for(int i=0; i<count; i++){
				delete guides[i];
			}
			delete[] guides;
		}
};
int main() {
    string name;
    cout << "Enter the name of the Travel Agency = ";
    getline(cin, name);
    Travelagency travel(name);
    int choice;
    do {
        string name, specialization;
        int years;
        cout<<"Enter name of tour guide = "<<endl;
        getline(cin, name);
        cout<<"Enter years of experience = "<<endl;
        cin>>years;
        cout<<"Enter specialization = "<<endl;
        cin.ignore();
        getline(cin, specialization);
        travel.addtourguide(name, years, specialization);
        cout<<"Do you want to add more tour guides ? (1 for yes/0 for no): ";
        cin>>choice;
        cin.ignore();
    }while(choice == 1);
    travel.displayguides();
    return 0;
}
