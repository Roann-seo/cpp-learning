#include<iostream>
#include<string>
using namespace std;
class student {
public:
    string name;
    double score;
    student(string n, double s) {
        name = n;
        score = s;
    }
    virtual void display() = 0;
    double getscore() {
        return score;
    }
    virtual ~student() = 0;
};
student::~student(){}
class excellent :public student {
public:
    excellent(string n, double s) :student(n, s) {}
    void display() {
        cout << "excellent student: " << name << " score: " << score << " " << "优秀" << endl;
    }
};
class normalstudent :public student {
public:
    normalstudent(string n, double s) :student(n, s) {

    }
    void display() {
        cout << "noramlstudent:" << name << "score" << score << endl;
    }
};
int main() {
    student* s1 = new excellent("Alice", 95);
    student* s2 = new normalstudent("Bob", 85);
    student* s3 = new normalstudent("Charlie", 75);
    student* s4 = new excellent("David", 98);
    student** arr = new student * [4];
    arr[0] = s1;
    arr[1] = s2;
    arr[2] = s3;
    arr[3] = s4;
    for (int i = 0; i < 4; i++) {
        arr[i]->display();
    }
    for (int i = 0; i < 4; i++) {
        delete arr[i];
    }
    delete[]arr;
    system("pause");
    return 0;
}
