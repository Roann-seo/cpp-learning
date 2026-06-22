#include<iostream>
#include<string>
using namespace std;
//类模板对象做函数参数
template<class T1,class T2>
class person{
    public :
    T1 m_name;
    T2 m_age;
    person(T1 name,T2 age){
        m_name=name;
        m_age=age;
    }
};//类模板
//1.指定传入类型(最常用)
void printperson1(person<string,int>&p){
    cout<<"姓名:"<<p.m_name<<endl;
    cout<<"年龄:"<<p.m_age<<endl;
}
void test01(){
    person<string,int>p("张三",20);
    printperson1(p);
    //不直接调用p的成员函数，而是通过printperson1函数来调用p的成员函数
}
//2.参数模板化
template<class T1,class T2>
void printperson2(person<T1,T2>&p){
    cout<<"姓名:"<<p.m_name<<endl;
    cout<<"年龄:"<<p.m_age<<endl;
    cout<<"T1的类型:"<<typeid(T1).name()<<endl;
    cout<<"T2的类型:"<<typeid(T2).name()<<endl;
}//函数模板
void test02(){
    person<string,int>p("李四",30);
    printperson2(p);
}

//3.整个类模板化
template<class T>
void printperson3(T&p){
    cout<<"姓名:"<<p.m_name<<endl;
    cout<<"年龄:"<<p.m_age<<endl;
    cout<<"T的类型"<<typeid(T).name()<<endl;
}
void test03(){
    person<string,int>p("王五",40);
    printperson3(p);
}
int main(){
    //test01();
    //test02();
    test03();
    return 0;
}