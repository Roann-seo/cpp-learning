#include<iostream>
#include<string>
using namespace std;
void test01(){
    string str1;
    str1+="Hello";
    cout<<str1<<endl;
    str1+=" C++";
    str1+=";";
    cout<<str1<<endl;
    string str2;
    str2.append(str1);
    str2.append("我");
    cout<<str2<<endl;
    string str3;
    str3.assign("I LOVE ");
    str3.append(str2,6,3);
    cout<<str3<<endl;
}
int main(){
    test01();
    return 0;
}