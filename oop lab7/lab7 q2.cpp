#include <iostream>
#include<string>
#include<cmath>
using namespace std;
struct Point{
	float x;
	float y;
};
class Shape{
	protected:
		Point position;
		string color;
		int borderthickness;
	public:
		Shape(float x, float y, string c, int t){
			position.x = x;
			position.y = y;
			color = c;
			borderthickness = t;
		}
		virtual void draw(){
			cout<<"Drawing"<<endl;
		}
		virtual void calculateArea(){
			cout<<"Calculating Area"<<endl;
		}
		virtual void calculatePerimeter(){
			cout<<"Calculating Perimeter"<<endl;
		}
};
class Circle : public Shape{
	private:
		float radius;
	public:
		Circle(float x, float y, string c, int t, float r) : Shape(x, y, c, t) {
			radius = r;
		}
		void draw(){
			cout<<"Circle with centre ("<<position.x<<", "<<position.y<<") and radius of = "<<radius<<endl;
		}
		void calculateArea(){
			float a;
			a = 3.142*radius*radius;
			cout<<"The area of circle is = "<<a<<endl;
		}
		void calculatePerimeter(){
			float p;
			p = 2*3.142*radius;
			cout<<"The Perimeter of Circle is = "<<p<<endl;
		}	
};
class Rectangle : public Shape{
	private:
		float height;
		float width;
	public:
		Rectangle(float x, float y, string c, int t, float h, float w) : Shape(x, y, c, t) {
			height = h;
			width = w;
		}
		void draw(){
			cout<<"Rectangle with top left corner position ("<<position.x<<", "<<position.y<<") and height of = "<<height<<" width of = "<<width<<endl;
		}
		void calculateArea(){
			float a;
			a = height*width;
			cout<<"The area of rectangle is = "<<a<<endl;
		}
		void calculatePerimeter(){
			float p;
			p = height + height + width + width;
			cout<<"The Perimeter of Rectangle is = "<<p<<endl;
		}
};
class Triangle : public Shape{
	float side1, side2, side3;
	public:
		Triangle(float x, float y, string c, int t, float s1, float s2, float s3) : Shape(x, y, c, t){
			side1 = s1;
			side2 = s2;
			side3 = s3;
		}
		void draw(){
			cout<<"Triangle with centre position of ("<<position.x<<", "<<position.y<<"), having 3 sides of lengths "<<side1<<", "<<side2<<", "<<side3<<" "<<endl;
		}
		void calculateArea(){
			float a, s;
			s = (side1+side2+side3)/2.0;
			a = sqrt(s*(s-side1)*(s-side2)*(s-side3));
			cout<<"The area of triangle is = "<<a<<endl;
		}
		void calculatePerimeter(){
			float p;
			p = side1+side2+side3;
			cout<<"The Perimeter of Triangle is = "<<p<<endl;
		}
};
class Polygon : public Shape{
	float angle1, angle2, angle3, angle4;
	public:
		Polygon(float x, float y, string c, int t, float a1, float a2, float a3, float a4) : Shape(x, y, c, t) {
			angle1 = a1;
			angle2 = a2;
			angle3 = a3;
			angle4 = a4;
		}
		void draw(){
			cout<<"Polygon with interior angles of degree = "<<angle1<<"-"<<angle2<<"-"<<angle3<<"-"<<angle4<<endl;
		}
		void calculateArea(){
			float a;
			a = angle1*angle2*angle3*angle4;
			cout<<"The area of the Polygon is = "<<a<<endl;
		}
		void calculatePerimeter(){
			float p;
			p = 2* (angle1*angle2*angle3*angle4);
			cout<<"Perimeter of the polygon is = "<<p<<endl;
		}
};
int main(){
    Circle c1(5.0, 5.0, "Red", 2, 10);
    Rectangle r1(2.0, 3.0, "Blue", 3, 6, 8);
    Triangle t1(4.0, 4.0, "Green", 1, 5, 6, 7);
    Polygon p1(1.0, 1.0, "Yellow", 2, 90, 90, 90, 90);
    c1.draw();
    r1.draw();
    t1.draw();
    p1.draw();
    cout<<"Calculating Areas"<<endl;
    c1.calculateArea();
    r1.calculateArea();
    t1.calculateArea();
    p1.calculateArea();
    cout<<"Calculating Perimeters"<<endl;
    c1.calculatePerimeter();
    r1.calculatePerimeter();
    t1.calculatePerimeter();
    p1.calculatePerimeter();
    return 0;
}

