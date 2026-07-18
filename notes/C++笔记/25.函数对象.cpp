#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
//函数对象  超过普通函数的概念，//函数对象是一个类，这个类重载了（）运算符，
//函数对象可以像普通函数一样调用，但是函数对象可以有自己的状态
class myadd{
    public:
    int operator()(int v1,int v2){
        return v1+v2;
    }
};
void test01(){
    myadd add;
    cout<<add(10,20)<<endl;
}
class myprint{
    public:
    void operator()(string test){
        cout<<test<<endl;
        count++;
    }
    int count=0;//内部自己的状态
};
void test02(){
    myprint p;
    p("hello world");
    p("hello world");
    p("hello world");
    p("hello world");
    cout<<"调用次数"<<p.count<<endl;
}
//函数对象作为参数传递
void doprint(myprint&m,string test){
    m(test);
}
void test03(){
    myprint m;
    doprint(m,"C++");
}
//返回bool类型的仿函数称为谓词
//一元谓词：operator()里面接受一个参数
//二元谓词：operator()里面接受两个参数
class greaterfive{
    public:
    bool operator()(int val){
        return val>5;
    }
};
void test04(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    vector<int>::iterator it=find_if(v.begin(),v.end(),greaterfive());
    //find _if的作用是找到第一个满足条件的元素
    cout<<"比5大的数:"<<*it<<endl;
}
class mycompare{
    public:
    bool operator()(int val1,int val2){
        return val1>val2;
    }
};
void test05(){
    vector<int>v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    //默认排序是从小到大
    sort(v.begin(),v.end());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //利用仿函数改成从大到小
    sort(v.begin(),v.end(),mycompare());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

}
int main(){
    // test01();
    // test02();
    // test03();
    //  test04();
    test05();
    return 0;
}