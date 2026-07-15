//set容器：所有元素都会在插入时自动被排序
//set/multiset属于关联式容器，底层结构是二叉树
//set不允许容器中有重复元素
//multiset允许容器中有重复元素
#include<iostream>
#include<set>
using namespace std;
void printset(set<int>&s){
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    set<int>s;
    //这里不能push_back,只能insert;
    //s.push_back(10);
    s.insert(3);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    printset(s);
    //set容器特点：所有元素插入时自动排序，不允许插入重复值
    //拷贝构造
    set<int>s2(s);
    printset(s2);
    //赋值
    set<int>s3;
    s3=s;
    printset(s3);
}
int main(){
    test01();
    return 0;
}