#include<iostream>
#include<string>
using namespace std;
class person {
private:
	string name;
	int age;
public:
	person() {
		name = "0";
		age = 0;
	}
	person(string n, int a) {
		name = n;
		age = a;
	}
	person operator+(person& p) {
		return person(name + p.name, age + p.age);
	}
	friend ostream& operator<<(ostream& os, const person& p);
	friend bool operator==(const person&p1, const person& p2);
};
ostream& operator<<(ostream& os, const person& p) {
	os << p.name;
	os << p.age;
	return os;
}
bool operator==(const person&p1, const person& p2) {
	if (p1.age == p2.age && p1.name == p2.name) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	person p1("张三", 20);
	person p2("李四", 18);
	person p3 = p1 + p2;
	cout << (p1 == p2) << endl;
	person p4("张三", 20);
	cout << (p1 == p4) << endl;
	return 0;
}