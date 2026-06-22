#include<iostream>
#include<string>
using namespace std;
template<typename nametype,typename agetype=int>
class person{
    public:
    person(nametype name,agetype age){
        this->m_name=name;
        this->m_age=age;
    }
    void showperson(){
        cout<<"姓名:"<<m_name<<endl;
        cout<<"年龄:"<<m_age<<endl;
    }
    nametype m_name;
    agetype m_age;
};
//类模板和函数模板的区别
//1.类模板没有自动类型推导使用方式，必须指定类型
void test01(){
    //person p("张三",20);//错误，类模板没有自动类型推导使用方式，必须指定类型
    person<string,int>p("张三",20);//正确，必须显示指定类型
    p.showperson();
}
//2.类模板在模板参数列表中可以有默认参数，而函数模板不行
void test02(){
    person <string>p2("李四",30);//正确，类模板在模板参数列表中可以有默认参数，而函数模板不行
    p2.showperson();
}
int main(){
    test01();
    test02();
    return 0;
}