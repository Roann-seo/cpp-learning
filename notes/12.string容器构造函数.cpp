#include<iostream>
#include<string>
using namespace std;
//string的本质是类不是指针，类内封装了char*,是char*型的容器
//
void test01(){
    string s1;//创建空字符串
    const char*str="hello world";
    string s2(str);//使用字符串str初始化
    cout<<s2<<endl;
    string s3(s2);//使用一个string对象初始化另一个string对象
    cout<<s3<<endl;
    string s4(10,'a');//使用n个字符c初始化
    cout<<s4<<endl;//aaaaaaaaaa

}
int main(){
    test01();
    return 0;
}