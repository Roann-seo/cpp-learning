#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
void test01(){
    vector<int>v;
    for(int i=1;i<=100;i++){
        v.push_back(i);
    }
    int sum=accumulate(v.begin(),v.end(),0);
    cout<<sum<<endl;
}
//交集
void myprint(int val){
    cout<<val<<" ";
}
void test02(){
    vector<int>v1;
    vector<int>v2;
    for(int i=1;i<=10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int>vtarget;
    vtarget.resize(min(v1.size(),v2.size()));
    vector<int>::iterator itend=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vtarget.begin());
    for_each(vtarget.begin(),itend,myprint);
}
//并集
void test03(){
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int>vtarget;
    vtarget.resize(v1.size()+v2.size());
    vector<int>::iterator itend=set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),vtarget.begin());
    for_each(vtarget.begin(),itend,myprint);
}
//交集
void test04(){
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int>vtarget;
    vtarget.resize(max(v1.size(),v2.size()));
    vector<int>::iterator itend=set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),vtarget.begin());
    cout<<"v1和v2的交集"<<endl;
    for_each(vtarget.begin(),itend,myprint);
}
int main(){
    // test01();
    //test02();
    // test03();
    test04();
    return 0;
}