//set容器：所有元素都会在插入时自动被排序
//set/multiset属于关联式容器，底层结构是二叉树
//set不允许容器中有重复元素
//multiset允许容器中有重复元素
#include<iostream>
#include<set>
#include<string>
using namespace std;
void printset(set<int>&s){
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    set<int>s;
    //这里不能push_back,只能insert;
    //s.push_back(10);
    s.insert(3);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    printset(s);
    //set容器特点：所有元素插入时自动排序，不允许插入重复值
    //拷贝构造
    set<int>s2(s);
    printset(s2);
    //赋值
    set<int>s3;
    s3=s;
    printset(s3);
}
// void printset(set<int>&s){
//     for(set<int>::iterator it=s.begin();it!=s.end();it++){
//         cout<<*it<<" ";
//     }
//     cout<<endl;
// }
//大小和交换
void test02(){
    set<int>s;
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(40);
    printset(s);
    if(s.empty()){
        cout<<"容器为空"<<endl;
    }else{
        cout<<"容器不是空"<<endl;
        cout<<s.size()<<endl;
    }
    set<int>s2;
    s2.insert(100);
    s2.insert(300);
    s2.insert(200);
    s2.insert(400);
    cout<<"交换前";
    printset(s);
    printset(s2);
    s.swap(s2);
    cout<<"交换后";
    printset(s);
    printset(s2);
}
//插入和删除
void test03(){
    set<int>s;
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(40);
    s.erase(s.begin());
    printset(s);
    s.erase(30);
    printset(s);
    s.erase(s.begin(),s.end());
    s.clear();
    printset(s);
}
//查找和统计
void test04(){
    set<int>s;
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(40);
    set<int>::iterator pos=s.find(30);//利用迭代器来接受位置
    if(pos==s.end()){
        cout<<"没找到"<<endl;
    }else{
        cout<<"找到了"<<endl;
        cout<<"元素"<<*pos<<endl;
    }
    int num=s.count(30);
    cout<<"num="<<num<<endl;
}
//set和multiset的区别
//set不可以插入重复数据，但是multiset可以插入重复数据
void test05(){
    set<int>s;
    pair<set<int>::iterator,bool> ret=s.insert(10);
    if(ret.second){
        cout<<"第一次插入成功"<<endl;
    }else{
        cout<<"第一次插入失败"<<endl;
    }
    ret=s.insert(10);
    if(ret.second){
        cout<<"第一次插入成功"<<endl;
    }else{
        cout<<"第一次插入失败"<<endl;
    }
    multiset<int>ms;
    ms.insert(10);
    ms.insert(10);
    for(multiset<int>::iterator it=ms.begin();it!=ms.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
//pair队组的创建
void test06(){
    pair<string,int>p("TOM",20);
    cout<<"name: "<<p.first<<" age: "<<p.second<<endl;
    pair<string,int>p1=make_pair("JERRY",30);
    cout<<"name: "<<p1.first<<" age: "<<p1.second<<endl;
}
//仿函数set容器排序规则
class mycompare{
    public:
    bool operator()(const int& v1,const int& v2)const{
        return v1>v2;
    }
};
void test07(){
    set<int,mycompare>s;
    s.insert(20);
    s.insert(10);
    s.insert(30);
    s.insert(50);
    s.insert(40);
    for(set<int,mycompare>::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
//仿函数set对于自定义数据类型的排序
class person{
    public:
    string m_name;
    int m_age;
    person(string name,int age){
        m_name=name;
        m_age=age;
    }
};
class mycompare1{
    public:
    bool operator()(const person&p1,const person&p2)const{
        return p1.m_age>p2.m_age;
    }
};
void test08(){
    set<person,mycompare1>p;
    person p1("TOM",21);
    person p2("JERRY",25);
    person p3("Rose",27);
    person p4("lisa",23);
    person p5("Jenny",22);
    p.insert(p1);
    p.insert(p2);
    p.insert(p3);
    p.insert(p4);
    p.insert(p5);
    for(set<person,mycompare1>::iterator it=p.begin();it!=p.end();it++){
        cout<<" name: "<<it->m_name<<" age: "<<it->m_age<<endl;
    }
}
int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    test08();
    return 0;
}