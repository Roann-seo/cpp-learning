#include<iostream>
using namespace std;
//类模板中成员函数创建时机
//类模板中成员函数的创建时机是在调用成员函数时才创建的
class person1{
    public:
    void showperson1(){
        cout<<"person1的showperson1函数被调用了"<<endl;
    }
};
class person2{
    public:
    void showperson2(){
        cout<<"person2的showperson2函数被调用了"<<endl;
    }
};
template<class T>
class myclass{
    public:
    T obj;
    void func1(){
        obj.showperson1();
    }
    void func2(){
        obj.showperson2();
    }

};
void test01(){
    myclass<person1>m1;
    m1.func1();
    //m1.func2();
}
int main(){
    test01();
    return 0;
}