#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
void test01(){
    negate<int>n;
    cout<<n(10)<<endl;
}
//算数仿函数
void test02(){
    plus<int>p;//加
    minus<int>m;
    multiplies<int>mu;
    divides<int>d;
    modulus<int>mo;//取模
    cout<<p(10,20)<<endl;
}
// class mycompare{
//     public:
//     bool operator()(int v1,int v2){
//         return v1>v2;
//     }
// };
//关系仿函数
void test03(){
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);
    sort(v.begin(),v.end());
    //默认升序排列
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //sort(v.begin(),v.end(),mycompare());
    //可以将自己写的仿函数改成算法中有的
    //降序
    sort(v.begin(),v.end(),greater());
    //等于equal_to
    //不等于not_equal_to
    //大于greater
    //大于等于greater_equal
    //小于less
    //小于等于less_equal
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
//逻辑仿函数
void test04(){
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    for(vector<bool>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //现在对原有数取反
    vector<bool>v2;
    v2.resize(v.size());
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
    for(vector<bool>::iterator it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    // test01();
    // test02();
    // test03();
    test04();
    return 0;
}