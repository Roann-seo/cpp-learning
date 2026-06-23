#include<iostream>
using namespace std;
#include<string>
//类模板成员函数类外实现
template<class T1,class T2>
class person{
    public:
    person(T1 name,T2 age);
       // m_name=name;
       // m_age=age;
    
    void show();//{
        //cout<<"姓名:"<<m_name<<endl;
        //cout<<"年龄:"<<m_age<<endl;
    //}
    T1 m_name;
    T2 m_age;
};
//构造函数的类外实现
template<class T1,class T2>
person<T1,T2>::person(T1 name,T2 age){
    m_name=name;
    m_age=age;
}
//类模板普通成员函数的类外实现
template<class T1,class T2>
void person<T1,T2>::show(){
    cout<<"姓名:"<<m_name<<endl;
    cout<<"年龄:"<<m_age<<endl;
}
void test01(){
    person<string,int>p("张三",20);
    p.show();
}
int main(){
    test01();
    return 0;
}