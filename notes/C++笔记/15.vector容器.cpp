#include<iostream>
#include<vector>
using namespace std;
void myprint(vector<int>&v){
    for(vector<int>::iterator it =v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    //默认构造函数 无参构造
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    myprint(v1);
    //通过区间方式构造
    vector<int>v2(v1.begin(),v1.end());
    myprint(v2);
    //n个elem方式构造
    vector<int>v3(10,100);
    myprint(v3);//打印10个100
    //拷贝构造
    vector<int>v4(v3);
    myprint(v4);
}
//赋值操作
void test02(){
    vector<int>v5;
    for(int i=0;i<11;i++){
        v5.push_back(i);
    }
    myprint(v5);
    vector<int>v6;
    v6.assign(v5.begin(),v5.end());
    myprint(v6);
    vector<int>v7=v6;
    myprint(v7);
    vector<int>v8(10,1000);
    myprint(v8);
}
//vector容量和大小
void test03(){
    vector<int>v9;
    for(int i=0;i<11;i++){
        v9.push_back(i);
    }
    if(v9.empty()){
        cout<<"v9为空"<<endl;
    }
    else{
        cout<<"v9的容量"<<v9.capacity()<<endl;
        cout<<"v9的大小"<<v9.size()<<endl;
        //capacity一直比size大
    }
    v9.resize(15,10);
    //如果指定的大小比原来大小大，就用数字来填充
    myprint(v9);
    //0 1 2 3 4 5 6 7 8 9 10 10 10 10 10 
    v9.resize(5);
    //如果指定的数字比原来大小小，就从中截断
    myprint(v9);
    //0 1 2 3 4
}
//vector插入和删除
void test04(){
    vector<int>v10;
    //尾插法
    v10.push_back(10);
    v10.push_back(20);
    v10.push_back(30);
    v10.push_back(40);
    v10.push_back(50);
    myprint(v10);
    //尾删法
    v10.pop_back();
    myprint(v10);
    //插入
    v10.insert(v10.begin(),1000);
    myprint(v10);
    v10.insert(v10.begin(),2,1000);
    myprint(v10);
    //删除
    v10.erase(v10.begin());
    myprint(v10);
    v10.erase(v10.begin(),v10.end());
    myprint(v10);
    v10.clear();
    myprint(v10);
}
//vector数据存取
void test05(){
    vector<int>v11;
    for(int i=20;i<30;i++){
        v11.push_back(i);
    }
    for(int i=0;i<v11.size();i++){
        cout<<v11[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v11.size();i++){
        cout<<v11.at(i)<<" ";
    }
    cout<<endl;
    cout<<"第一位："<<v11.front()<<endl;
    cout<<"最后一位："<<v11.back()<<endl;
}
//vector容器的互换容器
void printvector(vector<int>&v){
    for(vector<int>::iterator it=v.begin();it<v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test06(){
    vector<int>v12;
    for(int i=0;i<10;i++){
        v12.push_back(i);
    }
    cout<<"交换前"<<endl;
    printvector(v12);
    vector<int>v13;
    for(int i=10;i>0;i--){
        v13.push_back(i);
    }
    printvector(v13);
    v12.swap(v13);
    cout<<"交换后"<<endl;
    printvector(v12);
    printvector(v13);
}
//交换函数的实际用途
//巧用swap可以收缩内存空间
void test07(){
    vector<int>v13;
    for(int i=0;i<100;i++){
        v13.push_back(i);
    }
    cout<<"v13的容量:"<<v13.capacity()<<endl;//128
    cout<<"v13的大小:"<<v13.size()<<endl;//100
    v13.resize(3);
    cout<<"v13的容量:"<<v13.capacity()<<endl;//128
    cout<<"v13的大小:"<<v13.size()<<endl;//3
    vector<int>(v13).swap(v13);
    cout<<"v13的容量:"<<v13.capacity()<<endl;//3
    cout<<"v13的大小:"<<v13.size()<<endl;//3
}    
//利用reserve可以预留空间
void test08(){
    vector<int>v14;
    v14.reserve(100);//不能写v14.size(),因为此时vector刚创建此时为空，相当于没扩容
    int*p=NULL;
    int num=0;
    for(int i=0;i<100;i++){
        v14.push_back(i);
        if(p!=&v14[0]){
            p=&v14[0];
            num++;
        }
    }
    cout<<"内存改动"<<num<<"次"<<endl;
}
int main(){
    //test01();
    //test02(); 
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    test08();
    return 0;
}