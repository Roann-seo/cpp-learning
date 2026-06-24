#include<iostream>
using namespace std;
#include<string>
class student {
private:
	string name;
	double score;
	static int count;
public:
	static double totalscore;
	student(string n, double s) {
		name = n;
		score = s;
		count++;
		totalscore += score;
	}
	~student() {
		count--;
		totalscore -= score;
	}
	friend void showavg( student s) {
		cout << "当前所有学生平均分" << totalscore / 3 << endl;
	}
	int getcount() {
		return count;
	}
};
int student::count = 0;
double student::totalscore = 0.0;
int main() {
	student s1("san", 98);
	student s2("si", 79);
	student s3("wu", 89);
	cout << "总人数" << s1.getcount() << endl;
	cout << "总分" << s1.totalscore << endl;
	cout << "平均分";
	showavg(s1);
	return 0;
}