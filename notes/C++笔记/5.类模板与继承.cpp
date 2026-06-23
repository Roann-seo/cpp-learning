#include<iostream>
using namespace std;
template<class T>
class base{
    public:
    T m;
};
//class son:public base{
//这样写是错误的，如果父类是类模板，子类在继承的时候，需要指定父类的数据类型
//}
class son1:public base<int>{
    //可以这样写，但如果这样写，父类的模板类型就让写死了，模板就没有意义了
};
template<class T1,class T2>
class son2:public base<T2>{
    public:
    son2(){
        cout<<"base的数据类型"<<typeid(T2).name()<<endl;
        cout<<"son2的数据类型"<<typeid(T1).name()<<endl;
    }
};
void test01(){
    son1 s1;
    s1.m=100;
    cout<<"s1的数据类型"<<typeid(s1.m).name()<<endl;
    son2<int,double>s2;

}
int main(){
    test01();
    return 0;
}