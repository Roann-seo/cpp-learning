#include<iostream>
#include<string>
using namespace std;
//让编译器知道模板
template<class T1, class T2>
//提前知道里面的person类
class person;
//全局函数类外实现，提前先让编译器知道
template<class T1, class T2>
void show2(person<T1, T2>& p) {
    cout << "姓名:" << p.m_name << " " << "年龄：" << p.m_age << endl;
}
template<class T1, class T2>
class person {
private:
    T1 m_name;
    T2 m_age;
public:
    person(T1 name, T2 age) {
        m_name = name;
        m_age = age;
    }
    //全局函数类内实现
    friend void show(person<T1, T2>& p) {
        cout << "姓名:" << p.m_name << " " << "年龄：" << p.m_age << endl;
    }
    //这里的friend是全局函数，虽然在类内，但是没有用类名：：，说明它是全局函数
    //写在类内加friend只有用了私有数据
    //全局函数类外实现
    friend void show2<>(person<T1, T2>& p);//这个相当于普通函数但后面实现是函数模板，会报错
    //我如果想让其变成模板函数，需要加<>
    //如果全局函数是类外实现，需要让编译器提前知道这个模板
};

void test01() {
    
    person<string, int>p("TOM", 18);
    show(p);
}
void test02() {
    person<string, int>p("Jerry", 18);
    show2(p);
}
int main() {
    test01();
    test02();
    return 0;
}
//优先类内实现