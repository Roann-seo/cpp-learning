#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
void printlist(const list<int>&l){
    for(list<int>::const_iterator it=l.begin();it!=l.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
//赋值
void test01(){
    list<int>l1;
    
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printlist(l1);
    //list<int>l2(l1.begin(),l1.end());
    list<int>l2;
    l2=l1;
    //赋值的第一种形式=
    printlist(l2);
    //list<int>l3(l2);
    list<int>l3;
    l3.assign(l2.begin(),l2.end());
    //赋值的第二种形式.assign
    printlist(l3);
    //list<int>l4(10,1000);
    list<int>l4;
    l4.assign(10,100);
    printlist(l4);
    if(l1.empty()){
        //判断是否为空empty
        cout<<"l1为空"<<endl;
    }
    else{
        cout<<"l1不为空"<<endl;
        cout<<"l1的长度"<<l1.size()<<endl;
        //判断长度size
    }
    l1.resize(10,100);
    //重新指定长度resize
    printlist(l1);
}
//交换
void test02(){
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    list<int>l2;
    l2.assign(10,100);
    cout<<"交换前"<<" ";
    printlist(l1);
    printlist(l2);
    l1.swap(l2);
    cout<<"交换后"<<" ";
    printlist(l1);
    printlist(l2);
}
void test03(){
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_front(300);
    l1.push_front(200);
    l1.push_front(100);
    printlist(l1);
    l1.pop_back();
    printlist(l1);
    l1.pop_front();
    printlist(l1);
    list<int>::iterator it=l1.begin();
    l1.insert(++it,987);
    printlist(l1);
    l1.erase(it);
    printlist(l1);
    l1.push_back(10000);
    l1.push_back(10000);
    l1.push_back(10000);
    l1.push_back(10000);
    printlist(l1);
    l1.remove(10000);
    printlist(l1);
}
//数据存取
void printlist(list<int>&l){
    for(list<int>::const_iterator it=l.begin();it!=l.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test04(){
    list<int>v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    //list容器不可以根据[]和at来访问数据
    //但是vector容器可以用[]和at来访问数据
    cout<<"第一个元素"<<v1.front()<<endl;
    cout<<"最后一个元素"<<v1.back()<<endl;
    //list容器的迭代器是双向迭代器，不支持随机访问
    list<int>::iterator it=v1.begin();
    it++;
    it--;
    //可以用来验证，如果++和--都不报错的话，说明支持双向
    //it=it+1;
    //这个报错了，说明不支持随机访问
}
//list容器反转和排序
void test05(){
    list<int>l1;
    l1.push_back(30);
    l1.push_back(20);
    l1.push_back(10);
    l1.push_back(40);
    cout<<"反转前: ";
    printlist(l1);
    l1.reverse();
    cout<<"反转后: ";
    printlist(l1);
    //所有不支持随机访问的容器，不可以用标准算法库
    //sort(l1.begin(),l1.end());
    //这个是在vector容器中可以使用
    //此时的sort容器可以当成成员函数
    l1.sort();//默认排序 从小到大 升序
    cout<<"排序后(升序): "<<endl;
    printlist(l1);
    l1.reverse();
    cout<<"排序后(降序): "<<endl;
    printlist(l1);
}
//如果想要降序
// bool mycompare(int v1,int v2){
//     return v1<v2;
// }
int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    test05();
    return 0;
}