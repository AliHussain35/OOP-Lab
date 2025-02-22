#include <iostream>
#include <string>
using namespace std;
class Patient {
private:
    int id;
    string name;
    int* testresults;
public:
    Patient(int d, string n) {
        id = d;
        name = n;
        testresults = new int[5];  
        for (int i = 0; i < 5; i++) {
            testresults[i] = 0;
        }
    }

    Patient(const Patient &patobj) {
        id = patobj.id;
        name = patobj.name;
        testresults = new int[5];  
        for (int i = 0; i < 5; i++) {
            testresults[i] = patobj.testresults[i];  
        }
    }
    ~Patient() {
        delete[] testresults;
    }
    void display() {
        cout<<"Patient Name: " << name<< endl;
        cout<<"ID: " << id << endl;
        cout<<"Test Results: ";
        for (int i = 0; i < 5; i++) {
            cout<<testresults[i] << " ";
        }
        cout<<endl;
    }
};
int main() {
    Patient pat1(11, "Ali");
    Patient pat2(pat1); 
    cout<<"Patient 1 Details:"<<endl;
    pat1.display();
    cout<<"Patient 2 (Copied) Details:"<<endl;
    pat2.display();
    return 0; 
}

