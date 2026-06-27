#include<iostream>
#include<vector>
using namespace std;
void myprint(vector<int>&v){
    for(vector<int>::iterator it =v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    //默认构造函数 无参构造
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    myprint(v1);
    //通过区间方式构造
    vector<int>v2(v1.begin(),v1.end());
    myprint(v2);
    //n个elem方式构造
    vector<int>v3(10,100);
    myprint(v3);//打印10个100
    //拷贝构造
    vector<int>v4(v3);
    myprint(v4);
}
//赋值操作
void test02(){
    vector<int>v5;
    for(int i=0;i<11;i++){
        v5.push_back(i);
    }
    myprint(v5);
    vector<int>v6;
    v6.assign(v5.begin(),v5.end());
    myprint(v6);
    vector<int>v7=v6;
    myprint(v7);
    vector<int>v8(10,1000);
    myprint(v8);
}
//vector容量和大小
void test03(){
    vector<int>v9;
    for(int i=0;i<11;i++){
        v9.push_back(i);
    }
    if(v9.empty()){
        cout<<"v9为空"<<endl;
    }
    else{
        cout<<"v9的容量"<<v9.capacity()<<endl;
        cout<<"v9的大小"<<v9.size()<<endl;
        //capacity一直比size大
    }
    v9.resize(15,10);
    //如果指定的大小比原来大小大，就用数字来填充
    myprint(v9);
    //0 1 2 3 4 5 6 7 8 9 10 10 10 10 10 
    v9.resize(5);
    //如果指定的数字比原来大小小，就从中截断
    myprint(v9);
    //0 1 2 3 4
}
//vector插入和删除
void test04(){
    vector<int>v10;
    //尾插法
    v10.push_back(10);
    v10.push_back(20);
    v10.push_back(30);
    v10.push_back(40);
    v10.push_back(50);
    myprint(v10);
    //尾删法
    v10.pop_back();
    myprint(v10);
    //插入
    v10.insert(v10.begin(),1000);
    myprint(v10);
    v10.insert(v10.begin(),2,1000);
    myprint(v10);
    //删除
    v10.erase(v10.begin());
    myprint(v10);
    v10.erase(v10.begin(),v10.end());
    myprint(v10);
    v10.clear();
    myprint(v10);
}
int main(){
    test01();
    test02(); 
    test03();
    test04();
    return 0;
}