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
    //类模板中的成员函数，并不是一开始就创建，而是在调用的时候才创建
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
    //func2函数中调用了person2的showperson2函数，而person1类中没有showperson2函数，所以编译器在创建func2函数时就会报错
    //生成时没有报错但是在编译时错了
    //说明函数在调用时才会创建成员函数
}
int main(){
    test01();
    return 0;
}