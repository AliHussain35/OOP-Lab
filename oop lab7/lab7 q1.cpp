#include <iostream>
using namespace std;
class Account {
    protected:
        int accountNum;
        float balance;
        string accountHolderName;
        float transactionHistory[10];
        int transactionCount;  

    public:
        Account(int n, string name) {
            accountNum = n;
            balance = 0.0;
            accountHolderName = name;
            transactionCount = 0;  
        }

        void deposit(float amount) {
            balance = balance + amount;
            if (transactionCount < 10) {
                transactionHistory[transactionCount++] = amount;
            }
            cout << "Deposited: $" << amount << endl;
        }

        virtual void withdraw(float amount){
            if(amount > balance){
                cout<<"Insufficient balance, withdrawn: $" <<balance<<endl;
                if (transactionCount < 10) {
                    transactionHistory[transactionCount++] = -balance; 
                }
                balance = 0.0;
            } else {
                balance = balance - amount;
                cout << "Withdrawn: $" << amount << endl;
                if (transactionCount < 10) {
                    transactionHistory[transactionCount++] = -amount;  
                }
            }
            cout<<"Remaining balance: $"<<balance<<endl;
        }
        virtual void calculateInterest(){
    	    cout<<"Calculating Interest"<<endl;
	    }  
        virtual void printStatement(){
            cout <<"Account Number: "<<accountNum << endl;
            cout<< "Account Holder: " << accountHolderName << endl;
            cout<<"Balance: $" << balance << endl;
            cout<<"Transaction History (last 5 transactions) = "<<endl;
        
            for(int i = 0; i < transactionCount; i++) {
                if(transactionHistory[i] < 0)
                    cout<<"- Withdrawn: $"<<-transactionHistory[i]<<endl;
                else
                    cout<<"- Deposited: $"<<transactionHistory[i]<<endl;
            }
       }
};

class SavingsAccount : public Account {
    float interestRate;
    float minimumBalance;

    public:
        SavingsAccount(int n, string name, float i, float m) : Account(n, name), interestRate(i), minimumBalance(m) {}
        void calculateInterest(){
            float interest = balance * interestRate;
            cout<<"Savings Account Interest = $"<<interest<<endl;
        }

        void printStatement(){
            Account::printStatement();
            cout<<"Interest Rate = " <<interestRate * 100<<"%"<<endl;
        }

        void withdraw(float amount){
            if (balance - amount < minimumBalance) {
                cout<<"Cannot withdraw. Minimum balance requirement = $"<<minimumBalance<<endl;
            }else{
            Account::withdraw(amount);
        }
    }
};

class CheckingAccount : public Account{
    float minimumBalance;
    float interestRate;
    public:
        CheckingAccount(int n, string name, float m, float i) : Account(n, name), minimumBalance(m), interestRate(i) {}

        void calculateInterest(){
            float interest = balance * interestRate + 1000.00;
            cout<<"Checking Account Interest =  $"<<interest<<endl;
        }

        void printStatement(){
            Account::printStatement();
            cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
        }

        void withdraw(float amount){
            if(balance - amount < minimumBalance) {
                cout<<"Cannot withdraw. Minimum balance requirement =  $"<<minimumBalance<<endl;
            } else{
                Account::withdraw(amount);
            }
        }
};

class FixedDepositAccount : public Account {
    int maturityDate;
    float fixedInterestRate;
    public:
    FixedDepositAccount(int n, string name, int m, float f) : Account(n, name), maturityDate(m), fixedInterestRate(f) {}
    void calculateInterest(){
        float interest = balance * fixedInterestRate + 100.00;
        cout<<"Fixed Deposit Interest = $" <<interest<<endl;
    }
    void printStatement(){
        Account::printStatement();
        cout<<"Fixed Interest Rate = "<<fixedInterestRate*100<<"%"<<endl;
    }
};

int main() {
    SavingsAccount sa(101, "Ali Hussain", 0.05, 500.0);
    CheckingAccount ca(102, "Abdullah Asim", 1000.0, 0.02);
    FixedDepositAccount fda(103, "Shuja Ahmed", 365, 0.07);
    sa.deposit(2000);
    sa.calculateInterest();
    sa.printStatement();
    sa.withdraw(1800);
    cout<< endl;
    ca.deposit(5000);
    ca.calculateInterest();
    ca.printStatement();
    ca.withdraw(4500);
    fda.deposit(10000);
    fda.calculateInterest();
    fda.printStatement();
    fda.withdraw(500);  
    return 0;
}

