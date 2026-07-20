#include<iostream>
#include<string>
#include<queue>
//队列 先进先出 
using namespace std;
class person{
    public:
    string m_name;
    int m_age;
    person(string name,int age){
        m_name=name;
        m_age=age;
    }
};
void test01(){
    queue<person>q;
    person p1("孙悟空",1000);
    person p2("唐僧",30);
    person p3("猪八戒",20);
    person p4("沙和尚",30);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    cout<<"现在队列里面有的元素"<<q.size()<<endl;
    while(!q.empty()){
        cout<<"队顶元素 姓名"<<q.front().m_name<<
        " 队列元素 年龄"<<q.back().m_age<<endl;
        q.pop();
    }
    cout<<"现在队列里面有的元素"<<q.size()<<endl;
}
int main(){
    test01();
    return 0;
}