#include<iostream>
using namespace std;
#define pi 3.14159
class shape {
public:
	virtual double area() = 0;
	virtual double perimeter() = 0;

};
class rectangle :public shape {
private:
	double length;
	double width;
public:
	rectangle(double l, double w) {
		length = l;
		width = w;
	}
	double area() {
		return length * width;
	}
	double perimeter() {
		return 2 * (length + width);
	}
	~rectangle(){}
};
class circle :public shape {
private:
	double radius;
public:
	circle(double r) {
		radius = r;
	}
	double area() {
		return pi * radius * radius;
	}
	double perimeter() {
		return 2 * pi * radius;
	}
	~circle(){}
};
int main() {
	shape* r = new rectangle(3, 4);
	shape* c = new circle(6);
	shape** arr = new shape * [2] {r, c};
	cout << arr[0]->area() << endl;
	cout << arr[0]->perimeter() << endl;;
	arr[1]->area();
	arr[1]->perimeter();
	for (int i = 0; i < 2; i++) {
		delete arr[i];
	}
	delete[]arr;
	return 0;
}