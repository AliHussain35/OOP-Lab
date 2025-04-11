#include <iostream>
#include<string>
using namespace std;

class Fraction{
	public:
	float numerator;
	float denominator;
	Fraction(float n, float d) {
		while(d==0) {
			cout<<"Undefined"<<endl;
			return;
		}
		numerator = n;
		denominator = d;	
	}
	
	friend ostream& operator<<(ostream& out, const Fraction& f){
		out<<f.numerator<<"/"<< f.denominator;
		return out;
	}
	Fraction operator*(const Fraction& f){
		return Fraction(numerator * f.numerator , denominator * f.denominator);
	}
	Fraction operator+(const Fraction& f){
		return Fraction((numerator * f.denominator)+(f.numerator * denominator) , denominator * f.denominator);
	}
	Fraction operator-(const Fraction& f){
		return Fraction((numerator * f.denominator)-(f.numerator * denominator) , denominator * f.denominator);
	}
	Fraction operator/(const Fraction& f){
		return Fraction(numerator * f.denominator, denominator * f.denominator);
	}
};

int main() {
	Fraction f1(5,2);
	Fraction f2(3,5);
	cout<<"1) Addition = "<<f1<<" + "<<f2 << " = "<<f1+f2<<endl;
	cout<<"2) Subtraction = "<<f1<<" - "<<f2<<" = "<<f1-f2<<endl;
	cout<<"3) Multiplication = "<<f1<<" * "<<f2<< " = "<<f1*f2<<endl;
	cout<<"4) Division = "<<f1<<" / "<<f2<<" = "<<f1/f2<<endl;
}
