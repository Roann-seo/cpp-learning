#include<iostream>
#include<string>
#include<list>
using namespace std;
class person{
    public:
    string m_name;
    int m_age;
    int m_height;
    person(string name,int age,int height){
        m_name=name;
        m_age=age;
        m_height=height;
    }
};
bool mycompare(person&p1,person&p2){
    if(p1.m_age==p2.m_age){
        return p1.m_height>p2.m_height;
    }
    else{
        return p1.m_age<p2.m_age;
    }
}
void test01(){
    list<person>l;
    person p1("刘备",35,175);
    person p2("曹操",45,180);
    person p3("孙权",40,170);
    person p4("赵云",25,190);
    person p5("张飞",35,160);
    person p6("关羽",35,200);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);
    cout<<"排序前： "<<endl;
    for(list<person>::iterator it=l.begin();it!=l.end();it++){
        cout<<"姓名: "<<(*it).m_name<<" age "<<it->m_age<<" height "<<it->m_height<<endl;
    }
    l.sort(mycompare);
    cout<<"排序后:  "<<endl;
    for(list<person>::iterator it=l.begin();it!=l.end();it++){
        cout<<"姓名: "<<(*it).m_name<<" age "<<it->m_age<<" height "<<it->m_height<<endl;
    }
}
int main(){
    test01();
    return 0;
}