#include<iostream>
#include<string>
using namespace std;
class animal {
public:
	virtual void speak() = 0;
	string name;
	virtual ~animal() {}
};
class dog :virtual public animal {
public:
	dog(string n) {
		name = n;
	}
	void speak() {
		cout << "wangwang" << endl;
	}
	dog operator+(const dog & d) {
		return  dog(this->name + d.name);
	}
	
};
ostream& operator<<(ostream& os, const dog& d) {
	os << d.name;
	return os;
}
class cat :virtual public animal {
public:
	cat() {
		name = "小猫";
	}
	void speak() {
		cout << "miaomiao" << endl;
	}
};
int main() {
	animal* p1 = new dog("大黄");
	animal* p2 = new cat;
	animal** arr = new animal * [2]  { p1, p2 };
	for (int i = 0; i < 2; i++) {
		arr[i]->speak();
	}
	for (int i = 0; i < 2; i++) {
		delete arr[i];
	}
	delete[]arr;
	dog d1("小黑");
	dog d2("大黄");
	dog res = d1 + d2;
	cout << res << endl;
	return 0;
}