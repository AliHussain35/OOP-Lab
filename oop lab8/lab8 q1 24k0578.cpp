#include <iostream>
using namespace std;
class Humidity;
class Temperature{
	float temp;
	public:
		Temperature(float t) : temp(t){
		}
		friend float computeHeatindex(Temperature t, Humidity h);
};
class Humidity{
	float humidity;
	public:
		Humidity(float h) : humidity(h){
		}
        friend float computeHeatindex(Temperature t, Humidity h);
};
float computeHeatindex(Temperature t, Humidity h){
	float heatIndex = t.temp*h.humidity;
	return heatIndex;
}
int main(){
	Temperature t(32);
	Humidity h(0.7);
	cout<<"Head Index = "<<computeHeatindex(t,h);
}
