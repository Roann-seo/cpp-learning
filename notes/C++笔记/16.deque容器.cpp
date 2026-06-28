#include<iostream>
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
int main(){
    //test01();
    //test02();
    test03();
    return 0;
}