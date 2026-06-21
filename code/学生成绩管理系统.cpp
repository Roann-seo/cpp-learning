#include <iostream>
#include<string>
#include<fstream>
using namespace std;
class person {
private:
	string name;
	int num;
public:
	person(string n, int m) {
		name = n;
		num = m;
	}
	virtual void show() = 0;
	string getname() {
		return name;
	}
	int getnum() {
		return num;
	}
	virtual ~person() = 0;
};
person::~person(){}
class evaluator {
public:
	virtual void fixscore(class student& stu, int index, double newscore) = 0;
};
class student :public person{
private:
	string major;
	int time;
	double score[7];
public:
	student(string n, int m, string a, int t, double s[7]) :person(n, m) {
		major = a;
		time = t;
		for (int i = 0; i < 7; i++) {
			score[i] = s[i];
		}
	}
	string getmajor() {
		return major;
	}
	int gettime() {
		return time;
	}
	double getscore(int i) {
		if (i >= 0 && i < 7) {
			return score[i];
		}
	}
	void setscore(int i, double s) {
		if (i >= 0 && i < 7) {
			score[i] = s;//建立接口便于teacher访问student的私有数据
		}
	}
	double avescore() {
		int sum = 0.0;
		for (int i = 0; i < 7; i++) {
			sum += score[i];
		}
		return sum / 7;
	}
	void show() {
		cout << "学号" << getnum() << endl;
		cout << "姓名" << getname() << endl;
		cout << "专业" << major << endl;
		cout << "入学时间" << time << endl;
		cout << "成绩"  << endl;
		for (int i = 0; i < 7; i++) {
			cout << score[i] << " ";
		}
		cout << endl;
		cout << "平均分" << avescore() << endl;
	}
	~student() {}
};
class teacher :public person, public evaluator {
private:
	string department;
public:
	teacher(string n, int m, string dep) :person(n, m) {
		department = dep;
	}
	void fixscore(class student& s, int index, double newscore) {
		cout << getname() << "老师修改第" << index + 1 << "科目成绩为" << newscore << endl;
		s.setscore(index, newscore);
	}
	void show() {
		cout << "姓名" << getname() << endl;
		cout << "工号" << getnum() << endl;
		cout << "办公室" << department << endl;
	}
	string getdep() {
		return department;
	}
	~teacher(){}
};
void writefile(student &s,teacher &t) {
	ofstream ofs;
	ofs.open("student.txt", ios::out);
	ofs << "姓名" << s.getname() << endl;
	ofs << "学号" << s.getnum() << endl;
	ofs << "专业" <<s.getmajor() << endl;
	ofs << "入学时间" << s.gettime() << endl;
	ofs << "成绩" << endl;
	for (int i = 0; i < 7; i++) {
		ofs << s.getscore(i) << " ";
	}
	ofs << endl;
	ofs << "平均分" << s.avescore() << endl;
	ofs << "姓名" << t.getname() << endl;
	ofs << "工号" << t.getnum() << endl;
	ofs << "办公室" << t.getdep() << endl;
	ofs.close();
}
void readfile() {
	ifstream ifs;
	ifs.open("student.txt", ios::in);
	if (!ifs.is_open()) {
		return;
	}
	string line;
	while (getline(ifs, line)) {
		cout << line << endl;
	}
	ifs.close();
}
int main() {
	double score1[7] = { 87,88,89,87,88,87,89 };
	student s1("张三",2003,"计算机",2025,score1);
	double score2[7] = { 86,88,80,86,84,83,99 };
	student s2("李四", 2001, "电子信息", 2025, score2);
	teacher t1("张教授", 1000, "三号楼");
	//cout << s1.avescore(score1) << endl;
	//cout << s2.avescore(score2) << endl;
	s1.show();
	s2.show();
	t1.fixscore(s1, 4, 100);
	s1.show();
	t1.show();
	writefile(s1, t1);
	readfile();
	return 0;
}