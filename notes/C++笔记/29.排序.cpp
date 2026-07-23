#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<ctime>
using namespace std;
//sort
void myprint(int val){
    cout<<val<<" ";
}
void test01(){
    vector<int>v;
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);
    sort(v.begin(),v.end());
    for_each(v.begin(),v.end(),myprint);
    //sort默认是升序
    cout<<endl;
    sort(v.begin(),v.end(),greater<int>());
    for_each(v.begin(),v.end(),myprint);
    //降序
}
//random_shuffle
void test02(){
    srand((unsigned int)time(NULL));
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),myprint);
    cout<<endl;
}
//merge合并两个有序序列
void test03(){
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+1);
    }
    vector<int>v;
    v.resize(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
    for_each(v.begin(),v.end(),myprint);
    cout<<endl;
}
int main(){
    //test01();
    // test02();
    test03();
    return 0;
}