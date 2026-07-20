#include<iostream>
#include<stack>
//栈容器  先进后出，后进先出
using namespace std;
void test01(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<"容量"<<s.size()<<endl;
    while(!s.empty()){
        cout<<"栈顶元素"<<s.top()<<endl;
        //这里不能写成s.pop()因为，s.pop()代表删除，没有返回值
        //但是s.top()只读取不删除
        s.pop();
    }
    cout<<"容量"<<s.size()<<endl;
}
int main(){
    test01();
    return 0;
}