//STL六大组件：容器，算法，迭代器，仿函数，适配器，空间配置器
//STL容器：序列式容器：每个元素都有固定位置
//STL容器：关联式容器：放元素的同时会自动排序，查找效率高
//算法：Algorithms质变算法：元素和之前不一样了
//非质变算法：元素和之前还一样
//迭代器：算法通过迭代器才可以访问容器里面的元素
//每个容器都有自己的迭代器类型 
//STL诞生是为了提高代码的复用性，提供一套标准的数据结构和算法
#include<iostream>
#include<vector>
#include<algorithm>//标准算法头文件
using namespace std;
void myprint(int val){
    cout<<val<<endl;
}
void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    vector<int>::iterator pbegin=v.begin();//返回指向第一个元素的迭代器
    vector<int>::iterator pend=v.end();//返回指向最后一个元素下一位的迭代器
    //第一种遍历
    //while(pbegin!=pend){
      //  cout<<*pbegin<<endl;
     //   pbegin++;
    //}
    //第二种遍历
    //for(vector<int>::iterator it=v.begin();it!=v.end();it++){
      //  cout<<*it<<endl;
    //}
    //第三种遍历 利用STL提供便利算法
    for_each(v.begin(),v.end(),myprint);
}
int main(){
    test01();
    return 0;
}