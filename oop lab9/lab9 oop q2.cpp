#include<iostream>
#include<string>
using namespace std;
class SmartDevice{
	protected:
		bool isOn;
	public:
		SmartDevice() : isOn(false){
	}
		virtual void turnOn () = 0;
		virtual void turnOff() = 0;
		virtual void getStatus() = 0;
};

class LightBulb : public SmartDevice{
	private:
		int brightness;
	public:
		LightBulb(int b) : SmartDevice(){
			brightness = b;
		}
		void turnOn(){
			isOn = true;
		}
		void turnOff(){
			isOn = false;
		}
		void getStatus(){
			cout<<"Power status = ";
			if(isOn){
				cout<<"On"<<endl;
			}
			else{
				cout<<"Off"<<endl;
			}
			cout<<"Brightness Level = "<<brightness<<endl;
		}
};
class Thermostat : public SmartDevice{
	private:
		double temperature;
	public:
		Thermostat(double t) : SmartDevice(){
		    temperature = t;
		}
		void turnOn(){
			isOn = true;
		}
		void turnOff(){
			isOn = false;
		}
		void getStatus(){
			cout<<"Power status = ";
			if(isOn){
				cout<<"On"<<endl;
			}
			else{
				cout<<"Off"<<endl;
			}
			cout<<"Temperature Level = "<<temperature<<endl;
		}
};
int main(){
	LightBulb l1(50);
	Thermostat t1(20.0);
	cout<<"---LightBulb---"<<endl;
	l1.turnOn();
	l1.getStatus();
	cout<<"---Thermostat---"<<endl;
	t1.turnOn();
	t1.getStatus();
}
