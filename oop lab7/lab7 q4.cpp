#include<iostream>
#include<string>
using namespace std;
class Person{
	protected:
	string name;
	int id;
	string address;
	string phoneNumber;
	string email;
	public:
		Person(string n, int ID, string a, string p, string e) {
			name = n;
			id = ID;
			address = a;
			phoneNumber = p;
			email = e;
		}
		virtual void displayInfo(){
			cout<<"Name = "<<name<<endl;
			cout<<"ID = "<<id<<endl;
			cout<<"Address = "<<address<<endl;
			cout<<"Phone Number = "<<phoneNumber<<endl;
			cout<<"Email = "<<email<<endl;
		}
		
};
class Student : public Person{
	string courseEnrolled;
	float GPA;
	int enrollmentYear;
	public:
		Student(string n, int ID, string a, string p, string e, string cE, float g, int eY) : Person(n, ID, a, p, e){
			courseEnrolled = cE;
			GPA = g;
			enrollmentYear = eY;
		}
		float getgpa(){
			return GPA;
		}
		void displayInfo(){
			cout<<"Name = "<<name<<endl;
			cout<<"ID = "<<id<<endl;
			cout<<"Address = "<<address<<endl;
			cout<<"Phone Number = "<<phoneNumber<<endl;
			cout<<"Email = "<<email<<endl;
			cout<<"Course Enrolled = "<<courseEnrolled<<endl;
			cout<<"GPA = "<<GPA<<endl;
			cout<<"Enrollment year = "<<enrollmentYear<<endl;
			
		}
};
class Professor : public Person{
	string department;
	string coursesTaught[2];
	float salary;
	public:
		Professor(string n, int ID, string a, string p, string e, string d, string course1, string course2, float s) : Person(n, ID, a, p, e){
			department = d;
			coursesTaught[0] = course1;
			coursesTaught[1] = course2;
			salary = s;
		}
		void displayInfo(){
			cout<<"Name = "<<name<<endl;
			cout<<"ID = "<<id<<endl;
			cout<<"Address = "<<address<<endl;
			cout<<"Phone Number = "<<phoneNumber<<endl;
			cout<<"Email = "<<email<<endl;
			cout<<"Department = "<<department<<endl;
			cout<<"course taught 1 = "<<coursesTaught[0]<<endl;
			cout<<"course taught 2 = "<<coursesTaught[1]<<endl;
			cout<<"Salary = $"<<salary<<endl;

		}
};
class Staff : public Person{
	string department;
	string position;
	float salary;
	public:
		Staff(string n, int ID, string a, string p, string e, string d, string po, float s) :  Person(n, ID, a, p, e) {
			department = d;
			position = po;
			salary = s;
		}
		void displayInfo(){
			cout<<"Name = "<<name<<endl;
			cout<<"ID = "<<id<<endl;
			cout<<"Address = "<<address<<endl;
			cout<<"Phone Number = "<<phoneNumber<<endl;
			cout<<"Email = "<<email<<endl;
			cout<<"Department = "<<department<<endl;
			cout<<"Position = "<<position<<endl;
			cout<<"Salary = $"<<salary<<endl;
		}
};
class Course{
	int courseID;
	string courseName;
	int credits;
	string Instructor;
	string schedule;
	Student *students[5];
	int studentcount;
	public:
		Course(int id, string cN, int c, string I, string s){
			courseID = id;
			courseName = cN;
			credits = c;
			Instructor = I;
			schedule = s;
			studentcount = 0;
		}
		void registerStudent(Student *s){
			if(studentcount==5){
				cout<<"Cannnot add more students"<<endl;
				return;
			}
			else{
				students[studentcount] = s;
				studentcount++;
			}
		}
		void CalculateGrades(){
			for(int i=0; i<studentcount; i++){
				float gpa;
				gpa = students[i]->getgpa();
				if(gpa==4){
					cout<<"Student = "<<i+1<<" grade = A+"<<endl;
				}
				else if(gpa>=3){
					cout<<"Student = "<<i+1<<" grade = A"<<endl;
				}
				else if(gpa>=2){
					cout<<"Student = "<<i+1<<" grade = B"<<endl;
				}
				else{
					cout<<"Student = "<<i+1<<" grade = C"<<endl;
					
				}
			}
		}
};
int main() {
    Student *s1 = new Student("Ali Hussain", 111, "Capital housing society", "123-456-789", "alihussainn124@gmail.com", "CS124", 3.5, 2024);
    Student *s2 = new Student("Abdullah", 222, "Bufferzone", "123-456-789", "abdullah@gmail.com", "CS122", 3.0, 2021);
    Professor p1("Talha Shahid", 201, "FAST University Campus", "111-222-3333", "talhashahid@gmail.com", "Computer Science", "CS101", "CS102", 80000);
    Staff st1("Kamran", 301, "Admin Block", "444-555-6666", "kamran@gmail.com", "Administration", "Manager", 50000);

    Course course1(111, "CS101 - Introduction to Programming", 3, "Talha shahid", "Mon-Fri 10 AM");

    course1.registerStudent(s1);
    course1.registerStudent(s2);
    cout<<"Students Details"<<endl;
    s1->displayInfo();
    cout<<endl;
    s2->displayInfo();
    cout<<endl;
    cout<<"Professor Details"<<endl;
    p1.displayInfo();
    cout<<"Staff Details"<<endl;
    st1.displayInfo();
    cout<<endl;
    cout<<"Calculating Grades"<<endl;
    course1.CalculateGrades();
    delete s1;
    delete s2;
    return 0;
}


