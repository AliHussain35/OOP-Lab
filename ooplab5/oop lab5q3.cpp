#include<iostream>
#include<string>
using namespace std;
class Professor{
	private:
		string name;
		string department;
	public:
		Professor(string n, string d) : name(n), department(d){
		};
		void display(){
			cout<<"Name of Professor = "<<name<<endl;
			cout<<"Department = "<<department<<endl;
		}
};
class University{
	string name;
	Professor** professors; //making array of pointers to store
	int count;
	int initialcap;
	public:
		University(string n){
			name = n;
			count = 0;
			initialcap = 2;
			professors = new Professor*[initialcap];
		}
		void addprofessor(string n, string d){
			if(count==initialcap){
				int newcap = initialcap*2;
				Professor** newprofessors = new Professor*[newcap];
				for(int i=0; i<count; i++){
					newprofessors[i] = professors[i];
				}
				delete[] professors;
				professors = newprofessors;
				initialcap = newcap;
			}
			professors[count] = new Professor(n, d);
			count++;
		}
		void displayprofessors(){
			for(int i=0; i<count; i++){
				professors[i]->display();
				cout<<endl;
			}
		}
		~University(){
			for(int i=0; i<count; i++){
				delete professors[i];
			}
			delete[] professors;
		}
};
int main() {
    string uniname;
    cout << "Enter the name of the university: ";
    getline(cin, uniname);
    University uni(uniname);
    int choice;
    do {
        string name, department;
        cout<<"Enter name of professor = ";
        getline(cin, name);
        cout<<"Enter department of professor = ";
        getline(cin, department);
        uni.addprofessor(name, department);
        cout<<"Do you want to add professor? (1 for yes/0 for no): ";
        cin>>choice;
        cin.ignore();
    }while(choice == 1);
    uni.displayprofessors();
    return 0;
}
