#include<iostream>
#include<algorithm>
#include<deque>
//deque相当于队列
using namespace std;
void printdeque(const deque<int>&d){//加入const使里面的参数不能被修改
    for(deque<int>::const_iterator it=d.begin();it<d.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
//deque容器构造
void test01(){
    deque<int>d1;
    for(int i=0;i<10;i++){
        d1.push_back(i);
    }
    printdeque(d1);
    deque<int>d2(d1.begin(),d1.end());
    printdeque(d2);
    deque<int>d3(10,100);
    printdeque(d3);
    deque<int>d4(d3);
    printdeque(d4);
}
//deque容器赋值
void test02(){
    deque<int>d1;
    for(int i=0;i<10;i++){
        d1.push_back(i);
    }
    printdeque(d1);
    deque<int>d2;
    d2=d1;
    printdeque(d2);
    deque<int>d3;
    d3.assign(d1.begin(),d1.end());
    printdeque(d3);
    deque<int>d4;
    d4.assign(10,100);
    printdeque(d4);
}
//deque容器大小操作
void test03(){
    deque<int>d1;
    for(int i=0;i<10;i++){
        d1.push_back(i);
    }
    printdeque(d1);
    if(d1.empty()){
        cout<<"d1为空"<<endl;
    }
    else{
        cout<<"d1不为空"<<endl;
        cout<<"d1的大小"<<d1.size()<<endl;
        //和vector不同的是deque没有capaticy容量，可以无限插
    }
    //重新指定大小与vector相同
    d1.resize(15,10);
    printdeque(d1);
    d1.resize(6);
    printdeque(d1);
}
//deque插入和删除
void test04(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(300);
    printdeque(d1);
    d1.pop_back();
    d1.pop_front();
    printdeque(d1);
}
//插入
void test05(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(300);
    d1.insert(d1.begin(),200);
    printdeque(d1);
    d1.insert(d1.begin(),2,1000);
    printdeque(d1);
    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.begin(),d2.begin(),d2.end());
    //在d1的begin()上面插入d2.begin()和d2.end()
    printdeque(d1);
}
//删除
void test06(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(300);
    deque<int>::iterator it=d1.begin();
    it++;
    d1.erase(it);
    printdeque(d1);
    d1.erase(d1.begin(),d1.end());
    d1.clear();
    printdeque(d1);
}
//deque数据存取
void test07(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(1000);
    for(int i=0;i<d1.size();i++){
        cout<<d1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<d1.size();i++){
        cout<<d1.at(i)<<" ";
    }
    cout<<endl;
    cout<<"第一个元素是"<<d1.front()<<endl;
    cout<<"最后一个元素是"<<d1.back()<<endl;
}
//deque排序
void test08(){
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    printdeque(d);
    sort(d.begin(),d.end());
    printdeque(d);
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