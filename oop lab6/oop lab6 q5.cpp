#include<iostream>
using namespace std;
class Device{
    public:
        int deviceID;
        bool status;
        Device(int id, bool s) : deviceID(id), status(s) {}
        virtual void displayDetails(){
            cout<<"Device ID = "<<deviceID<<endl;
            cout<<"status = "<<(status ? "ON" : "OFF")<<endl;
        }
};
class SmartPhone : virtual public Device {
    public:
        float screenSize;
        SmartPhone(int id, bool s, float size) : Device(id, s), screenSize(size){}
        void displayDetails(){
            Device::displayDetails();
            cout<<"Screen size = "<<screenSize<<" inches"<<endl;
    }
};
class SmartWatch : virtual public Device {
    public:
        bool heartRateMonitor;
        SmartWatch(int id, bool s, bool heart) : Device(id, s), heartRateMonitor(heart) {}
        void displayDetails(){
            Device::displayDetails();
            cout<<"Heart Rate Monitor = "<<(heartRateMonitor ? "Yes" : "No")<<endl;
        }
};
class SmartWearable : public SmartPhone, public SmartWatch {
    public:
        int stepCounter;
        SmartWearable(int id, bool s, float size, bool heart, int steps)
        : Device(id, s), SmartPhone(id, s, size), SmartWatch(id, s, heart), stepCounter(steps) {}
        void displayDetails(){
            Device::displayDetails();
            cout<<"Screen size = " <<screenSize<<" inches" <<endl;
            cout<<"Heart rate monitor = "<<(heartRateMonitor ? "Yes" : "No")<<endl;
            cout<<"Step counter = "<<stepCounter<<" steps"<<endl;
        }
};

int main() {
    int id, steps;
    bool status, heartMonitor;
    float screenSize;
    cout<<"Enter Device ID =  ";
    cin>>id;
    cout<<"Enter Status = 1. for on, 0. for off = ";
    cin>>status;
    cout<<"Enter Screen Size = (in inches) ";
    cin>>screenSize;
    cout<<"Does it have a Heart Rate Monitor ? 1. for Yes, 0. for No =  ";
    cin>>heartMonitor;
    cout<<"Enter Step Counter Value: ";
    cin>>steps;
    SmartWearable s1(id, status, screenSize, heartMonitor, steps);
    cout<<"Smart Wearable Details"<<endl;
    s1.displayDetails();
    return 0;
}

