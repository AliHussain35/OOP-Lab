#include<iostream>
#include<string>
using namespace std;
class Activity{
	public:
		Activity(){
		}
		
		virtual void calculateCaloriesBurned() = 0;
};
class Running : public Activity{
	float weight;
	double distance;
	double time;
	public:
		Running() : Activity() {
			cout<<"Enter person's weight = "<<endl;
			cin>>weight;
			cout<<"Enter distance of running in km = "<<endl;
			cin>>distance;
			cout<<"Enter time in minutes = "<<endl;
			cin>>time;
		}
		void calculateCaloriesBurned(){
			double Met = 9.0; //estimated met value of running
			double timeHours = time/60;
			double caloriesBurned = Met*weight*timeHours;
			cout<<"Total calories burned in running = "<<caloriesBurned<<" kcal"<<endl;
		}
};
class Cycling : public Activity{
	float weight;
	double speed;
	double time;
	public:
		Cycling() : Activity() {
			cout<<"Enter person's weight = "<<endl;
			cin>>weight;
			cout<<"Enter speed (in km/h) = "<<endl;
			cin>>speed;
			cout<<"Enter time in hours = "<<endl;
			cin>>time;
		}
		void calculateCaloriesBurned(){
			double Met = 10.0; //estimated met value of normal cycling
			if(speed>12){
				Met = 12;
			}
			double caloriesBurned = Met*weight*time;
			cout<<"Total calories burned in cycling = "<<caloriesBurned<<" kcal"<<endl;
		}
};
int main(){
	cout<<"---Enter info for running activity---"<<endl;
	Running r1;
	r1.calculateCaloriesBurned();
	cout<<"---Enter info for cycling activity---"<<endl;
	Cycling c1;
	c1.calculateCaloriesBurned();
}
