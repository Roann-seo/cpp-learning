#include<iostream>
#include<map>
#include<string>
using namespace std;
void printmap(map<int,int>&m){
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<"key="<<(*it).first<<" value= "<<it->second<<endl;
    }
    cout<<endl;
}
void test01(){
    //map函数的构造
    map<int,int>m1;
    //注意map容器里面插入时是对组
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));
    //printmap(m1);
    map<int,int>m2(m1);
    //printmap(m2);
    map<int,int>m3;
    m3=m2;
    //printmap(m3);
    m1.erase(m1.begin());
    printmap(m1);
    m1.erase(3);
    //这里里面只能填key值，不能value值
    printmap(m1);
    m1.erase(m1.begin(),m1.end());
    printmap(m1);
}
//map的大小和交换
void test02(){
    map<int,int>m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));
    map<int,int>m2;
    m2.insert(pair<int,int>(1,100));
    m2.insert(pair<int,int>(2,200));
    m2.insert(pair<int,int>(3,300));
    m2.insert(pair<int,int>(4,400));
    if(m1.empty()){
        cout<<"empty"<<endl;
    }else{
        cout<<"no empty"<<endl;
        cout<<"m1的size"<<m1.size()<<endl;
    }
    cout<<"交换前:"<<endl;
    printmap(m1);
    printmap(m2);
    m1.swap(m2);
    cout<<"交换后:"<<endl;
    printmap(m1);
    printmap(m2);
}
//查找和统计
void test03(){
    map<int,int>m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));
    //m.find最后返回的是迭代器，如果找不到最后返回的是m.end()
    map<int,int>::iterator pos=m1.find(3);
    if(pos==m1.end()){
        cout<<"没找到"<<endl;
    }else{
        cout<<"key="<<(*pos).first<<" value: "<<pos->second<<endl;
    }
    int num=m1.count(3);
    cout<<"num="<<num<<endl;
}
//map容器的排序规则
//自定义数据类型排序
class person{
    public:
    string m_name;
    int m_age;
    person(string name,int age){
        m_name=name;
        m_age=age;
    }
};
class mycompare{
    public:
    bool operator()(const int&p1,const int&p2)const{
        return p1>p2;
    }
};
void test04(){
    map<int,person,mycompare>p;
    person p1("lisa",21);
    person p2("Rose",25);
    person p3("Jisoo",24);
    person p4("jennie",22);
    p.insert(pair<int,person>(1,p1));
    p.insert(pair<int,person>(2,p2));
    p.insert(pair<int,person>(3,p3));
    p.insert(pair<int,person>(4,p4));
    for(map<int,person,mycompare>::iterator it=p.begin();it!=p.end();it++){
        cout<<"key="<<(*it).first<<" name: "<<it->second.m_name
        <<" age: "<<it->second.m_age<<endl;
    }
}
//key=4 name: jennie age: 22
// key=3 name: Jisoo age: 24
// key=2 name: Rose age: 25
// key=1 name: lisa age: 21
//这是按照键值降序排列，如果想要按照年龄降序排列，那么需要将person放在键值位置
class mycompare1{
    public:
    bool operator()(const person &p1,const person &p2)const{
        return p1.m_age<p2.m_age;
    }
};
void test05(){
    map<person,int,mycompare1>p;
    person p1("lisa",21);
    person p2("Rose",25);
    person p3("Jisoo",24);
    person p4("jennie",22);
    p.insert(pair<person,int>(p1,1));
    p.insert(pair<person,int>(p2,2));
    p.insert(pair<person,int>(p3,3));
    p.insert(pair<person,int>(p4,4));
    for(map<person,int,mycompare1>::iterator mit=p.begin();mit!=p.end();mit++){
        cout<<"key="<<(*mit).second<<" name: "<<mit->first.m_name
        <<" age: "<<mit->first.m_age<<endl;
    }
}
// key=1 name: lisa age: 21
// key=4 name: jennie age: 22
// key=3 name: Jisoo age: 24
// key=2 name: Rose age: 25
int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    test05();
    return 0;
}