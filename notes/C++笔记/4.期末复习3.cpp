#include<iostream>
#include<cmath>
using namespace std;
class complex {
private:
	float real;
	float imag;
public:
	complex(float r, float i) {
		real = r;
		imag = i;
	}
	friend complex operator+(complex& c1, complex& c2) {
		return complex(c1.real + c2.real, c1.imag + c2.imag);
	}
	friend ostream& operator<<(ostream& os, const complex & c) {
		os <<c.real;
		if (c.imag > 0) {
			os << "+" << c.imag << "i" << endl;
		}
		else if (c.imag < 0) {
			os << c.imag << "i" << endl;
		}
		return os;
	}

	float modulus(complex&c) {
		return sqrt(c.imag * c.imag + c.real * c.real);
	}
};
int main() {
	complex c1(3, 4);
	complex c2(5, 6);
	complex c3 = c1 + c2;
	cout << c3<<endl;
	cout<<c3.modulus(c3);
	return 0;
}
