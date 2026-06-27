#include<iostream>
#include<vector>
using namespace std;
void test01(){
    //先定义大容器
    vector<vector<int>> v;
    //在定义小容器
    vector<int> p1;
    vector<int> p2;
    vector<int> p3;
    vector<int> p4;
    //先给小容器赋值
    for(int i=0;i<4;i++){
        p1.push_back(i+1);
        p2.push_back(i+2);
        p3.push_back(i+3);
        p4.push_back(i+4);
    }
    //将小容器插入到大容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    //通过大容器把所有的数据都遍历一遍
    for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++){
        //(*it)=vector<int>
        for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++){
            cout<<*vit<<" ";
        }
        cout<<endl;
    }
}
int main(){
    test01();
    return 0;
}