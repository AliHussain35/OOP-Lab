#include <iostream>
#include <string>
using namespace std;
class Movie {
private:
    string title;
    string director;
    int duration;
public:
    Movie() {} 
    Movie(string t, string d, int time) {
        title = t;
        director = d;
        duration = time;
    }
    void display() {
        cout<<"Movie Name: "<<title<<endl;
        cout<<"Director: "<<director<<endl;
        cout<<"Duration: "<<duration<<" hours"<<endl;
    }
};
class CinemaHall {
    private:
        string name;
        Movie movies[10]; //one cinema can have max 10 movies
        int count; 
    public:
        CinemaHall(string n) {
        name = n;
        count = 0; 
        }
        void addMovie(string t, string d, int duration) {
            if(count<10){
                movies[count] = Movie(t, d, duration);
                count++;
            }else{
                cout<<"Cinema hall is full"<<endl;
            }
        }
        void displayMovies(){
            cout<<"Cinema name = "<<name<<endl;
            cout<<"Displaying movies"<<endl;
            for(int i=0; i <count; i++) {
                movies[i].display();
                cout<<endl;
            }
        }
};
int main() {
    CinemaHall n1("Nueplex");
    n1.addMovie("Spiderman", "Ali Hussain", 3);
    n1.addMovie("Batman", "Ahmed", 2);
    n1.displayMovies(); 
    return 0;
}

