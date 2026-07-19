//常用遍历算法
//for_each 遍历容器
//transform 搬运容器到另一个容器中
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(int val){
    cout<<val<<" ";
}
class print01{
    public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
void test01(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print);
    //利用普通函数调用，不需要加（）
    cout<<endl;
    for_each(v.begin(),v.end(),print01());
    //利用仿函数调用，需要加（）
}
class transform1{
    public:
    int operator()(int val){
        return val+100;
    }
};
class myprint{
    public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
void test02(){
    vector<int>v2;
    for(int i=0;i<10;i++){
        v2.push_back(i);
    }
    vector<int>v3;
    v3.resize(v2.size());
    transform(v2.begin(),v2.end(),v3.begin(),transform1());
    for_each(v3.begin(),v3.end(),myprint());
}
int main(){
    //test01();
    test02();
    return 0;
}