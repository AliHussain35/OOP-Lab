#include<iostream>
#include<string>
using namespace std;
class InvalidValueException: public exception{
    public:
        const char* what ()const noexcept override{
            return "InvalidValueException - Age cannot be negative or cannot exceed 120";
        }
};
void validateAge(int a){
    if(a<0 || a>120) {
        throw InvalidValueException();
    }else{
        cout<<"Age is valid"<<endl;
    }
}
int main(){
    int age;
    cout<<"Enter Age =  "<<endl;
    cin>>age;
    try{
        validateAge(age);
    }catch(const InvalidValueException &e){
        cout<<"Error= "<<e.what()<<endl;
    }
    return 0;
}
