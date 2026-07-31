#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class myprint{
    public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
class greater5{
    public:
    bool operator()(int val){
        return val>=5;
    }
};
void test01(){
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    vector<int>v2;
    v2.resize(v1.size());
    copy(v1.begin(),v1.end(),v2.begin());
    cout<<"换之前:"<<endl;
    for_each(v2.begin(),v2.end(),myprint());
    replace(v2.begin(),v2.end(),2,22);
    //replace会将所有的2改成22
    cout<<"换之后:"<<endl;
    for_each(v2.begin(),v2.end(),myprint());
    replace_if(v2.begin(),v2.end(),greater5(),55);
    cout<<"换5之后:"<<endl;
    for_each(v2.begin(),v2.end(),myprint());
}
int main(){
    test01();
    return 0;
}