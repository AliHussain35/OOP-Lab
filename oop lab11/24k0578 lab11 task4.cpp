#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

class NegativeNumberException: public exception{
    public: 
        const char* what ()const noexcept override{
            return "Input must be non-negative";
        }
};
class InvalidTypeException: public exception{
    public: 
        const char* what ()const noexcept override{
            return "Non Numeric Type detected";
        }
};
template <typename T>
double computeSqrRoot(T n) {
    if(n < 0){
        throw NegativeNumberException();
    }
    return sqrt(n);
    
}

double computeSqrRoot(const char* n){
    throw InvalidTypeException();
}

double computeSqrRoot(string n) {
    throw InvalidTypeException();
}

int main () {
    try {
        cout<<"sqrt(16) = "<<computeSqrRoot(16)<<endl;
    } 
    catch(const NegativeNumberException& e){
        cout<<e.what()<<endl;
    }
    catch(const InvalidTypeException& e) {
        cout<<e.what()<<endl;
    }
    try{
        cout<<"sqrt(-4) =  "<<computeSqrRoot(-4)<<endl;
    } 
    catch(const NegativeNumberException& e){
        cout<<e.what()<<endl;
    }
    catch(const InvalidTypeException& e){
        cout<<e.what()<<endl;
    }
    try{
        cout<<"sqrt(\"hello\") = "<<computeSqrRoot(string("hello"))<<endl;
    } 
    catch (const NegativeNumberException& e){
        cout<<e.what()<<endl;
    }
    catch(const InvalidTypeException& e){
        cout<<e.what()<<endl;
    }
}
