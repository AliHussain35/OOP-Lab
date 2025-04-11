#include <iostream>
#include<string>
using namespace std;
class Teacher;
class Student{
	string name;
	float grades[3];
	friend class Teacher;
	public:
		Student(string n, float g1, float g2, float g3){
			name = n;
			grades[0] = g1;
			grades[1] = g2;
			grades[2] = g3;
		}
		friend float calculateAvg(Student &s);
};
class Teacher{
	string name;
	public:
		Teacher(string n) : name(n){
		}
		
		void modifyGrades(Student &s){
		    int n,g;
		    cout<<"Which Subject Grade to Modify =  "<<endl;
		    cin>>n;
		    if(n>3) {
			    cout<<"Invalid"<<endl;
			    return;
		    }
		    cout<<"Enter New Grade =  "<<endl;
		    cin>>g;
		    s.grades[n-1] = g;
	    }
	    void viewGrades(Student &s){
	    	for(int i=0; i<3; i++){
	    		cout<<"Subject number = "<<i+1<<" grade = "<<s.grades[i]<<endl;
			}
		}
};
float calculateAvg(Student &s) {
	int sum=0;
	for(int i=0; i<3; i++) {
		sum += s.grades[i];
	}
	return sum/3;
}
int main() {
	Student s1("Ali Hussain", 95,85,75);
	Teacher t1("Sir Talha");
	cout<<"---Grades---"<<endl;
	t1.viewGrades(s1);
	cout<<"Average Grade =  "<<calculateAvg(s1)<<endl;
	t1.modifyGrades(s1);
	cout<<"---Updated Grades---"<<endl;
	t1.viewGrades(s1);
	cout<<"Average Grade = "<<calculateAvg(s1)<<endl;
}
