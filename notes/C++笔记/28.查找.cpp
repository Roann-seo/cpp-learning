#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void test01(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    vector<int>::iterator it=find(v.begin(),v.end(),5);
    if(it==v.end()){
        cout<<"没找到"<<endl;
    }else{
        cout<<"找到了"<<*it<<endl;
    }
}
class person{
    public:
    string m_name;
    int m_age;
    person(string name,int age){
        m_name=name;
        m_age=age;
    }
    bool operator==(const person&p){
        if(p.m_age==m_age&&p.m_name==m_name){
            return true;
        }
        else{
            return false;
        }
    }
};
void test02(){
    vector<person>p;
    person p1("aaa",20);
    person p2("bbb",20);
    person p3("ccc",20);
    person p4("ddd",20);
    person p5("eee",20);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);
    vector<person>::iterator dit=find(p.begin(),p.end(),p2);
    if(dit==p.end()){
        cout<<"没有找到"<<endl;
    }else{
        cout<<"找到了"<<dit->m_age<<" "<<dit->m_name<<endl;
    }
}
//find_if是找条件查找
//adjacent_find查找相邻重复元素
void test03(){
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(3);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    vector<int>::iterator pos=adjacent_find(v.begin(),v.end());
    if(pos==v.end()){
        cout<<"没找到"<<endl;
    }else{
        cout<<"找到了相邻重复元素"<<endl;
    }
}
//binary_search查找指定元素是否存在
//注意容器必须是有序数列
void test04(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    //v.push_back(3);
    //加上这个数列就没有顺序了
    bool ret=binary_search(v.begin(),v.end(),9);
    if(ret){
        cout<<"找到了"<<endl;
    }else{
        cout<<"没找到"<<endl;
    }
}
//count 统计数据类型
class person1{
    public:
    string m_name;
    int m_age;
    person1(string name,int age){
        m_name=name;
        m_age=age;
    }
    bool operator==(const person1&p){
        if(p.m_age==m_age){
            return true;
        }else{
            return false;
        }
    }
};
void test05(){
    vector<person1>p;
    person1 p1("刘备",35);
    person1 p2("关羽",35);
    person1 p3("张飞",35);
    person1 p4("赵云",30);
    person1 p5("曹操",28);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);
    person1 p6("诸葛亮",35);
    int num=count(p.begin(),p.end(),p6);
    cout<<"num="<<num<<endl;
}
//count_if按照条件统计元素个数
class agegreater20{
    public:
    bool operator()(const person1&p){
        return p.m_age>20;
    }
};
void test06(){
    vector<person1>p;
    person1 p1("刘备",35);
    person1 p2("关羽",35);
    person1 p3("张飞",35);
    person1 p4("赵云",30);
    person1 p5("曹操",28);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);
    int num=count_if(p.begin(),p.end(),agegreater20());
    cout<<"num="<<num<<endl;
}
int main(){
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();
    return 0;
}