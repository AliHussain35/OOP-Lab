#include <iostream>
using namespace std;
class InsufficientFundsException: public exception{
    private:
        double deficit;
        string message;
    public:
        InsufficientFundsException(float d) : deficit (d){
            message = "InsufficientFundsException - Deficit: $" + to_string(deficit);
        } 
        const char* what()const noexcept override{
            return message.c_str();
        }
};
template <typename T>
class BankAccount {
    public:
        T balance;
        BankAccount(T b) : balance (b){
            cout<<"Balance = $"<<balance<<endl;
        }
        void widthdraw (T a){
            if(a > balance){
                throw InsufficientFundsException(a - balance);
            }else{
                balance -= a;
                cout<<"withdrawn $"<<a<<endl;
            }
        }
};

int main(){
    BankAccount <float>account(700.0);
    try{
        account.widthdraw(900.0);
    }
    catch(const InsufficientFundsException &e){
        cout<<"withdraw $900: "<<e.what()<<endl;
    } 
}
