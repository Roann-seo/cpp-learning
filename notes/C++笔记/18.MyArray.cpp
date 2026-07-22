#include<iostream>
#include<string>
using namespace std;
template<class T>
class MyArray{
    private:
    T* pAddress;
    int m_capacity;
    int m_size;
    public:
    MyArray(int capacity){
        //cout<<"有参构造调用"<<endl;
        this->m_capacity=capacity;
        this->m_size=0;
        this->pAddress=new T[capacity];
    }
    MyArray(const MyArray&p){
        //cout<<"拷贝构造调用"<<endl;
        this->m_capacity=p.m_capacity;
        this->m_size=p.m_size;
        //如果直接写 this->pAddress = p.pAddress 就是浅拷贝：
        //两个对象共用同一块堆内存，析构时会重复delete，程序崩溃。
        //深拷贝
        this->pAddress=new T[p.m_capacity];
        for(int i=0;i<p.m_size;i++){
            this->pAddress[i]=p.pAddress[i];
        }
    }
    //operator=重载 防止浅拷贝
    //&是支持连续赋值
    MyArray& operator=(const MyArray& arr){
        //cout<<"operator=构造调用"<<endl;
        //先判断原来堆区是否有数据，如果有数据先释放
        if(this->pAddress!=NULL){
            delete []pAddress;
            pAddress=NULL;
            m_capacity=0;
            m_size=0;
        }
        //深拷贝
        this->m_capacity=arr.m_capacity;
        this->m_size=arr.m_size;
        this->pAddress=new T [arr.m_capacity];
        for(int i=0;i<arr.m_size;i++){
            this->pAddress[i]=arr.pAddress[i];
        }
        return *this;
    }
    void push_back(const T&val){
        if(m_capacity==m_size){
            return ;
        }
        pAddress[m_size]=val;
        m_size++;
    }
    void pop_back(){
        if(m_size==0){
            return ;
        }
        m_size--;
    }
    //通过下标来找数据
    //通过【】重载来实现
    //如果函数调用想要作为左值存在，需要加入引用
    T &operator[](int index){
        return pAddress[index];
    }
    int get_capacity(){
        return m_capacity;
    }
    int get_size(){
        return m_size;
    }
    ~MyArray(){
        if(this->pAddress!=NULL){
            delete[] this->pAddress;
            this->pAddress=NULL;
        }
    }
};
class person{
    public:
    string name;
    int age;
    person(){}
    person(string n,int a){
        name=n;
        age=a;
    }
};
void print_int(MyArray<int>&arr){
    for(int i=0;i<arr.get_size();i++){
        cout<<arr[i]<<endl;
    }
}
void print_person(MyArray<person>&arr){
    for(int i=0;i<arr.get_size();i++){
        cout<<"姓名"<<arr[i].name<<" 年龄"<<arr[i].age<<endl;
    }
}
void test01(){
    MyArray<int>arr1(5);
    for(int i=0;i<5;i++){
        arr1.push_back(i);
    }
    print_int(arr1);
    cout<<arr1.get_capacity()<<endl;
    cout<<arr1.get_size()<<endl;
    MyArray<int>arr2(arr1);
    arr2.pop_back();
    cout<<arr2.get_capacity()<<endl;
    cout<<arr2.get_size()<<endl;
    //MyArray<int>arr3(100);
    //arr3=arr1;
}
void test02(){
    MyArray<person>arr(10);
    person p1("张三",1);
    person p2("李四",2);
    person p3("王五",3);
    person p4("赵六",4);
    person p5("孙琪",5);
    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    arr.push_back(p4);
    arr.push_back(p5);
    print_person(arr);
    cout<<arr.get_capacity()<<endl;
    cout<<arr.get_size()<<endl;
}
int main(){
    //test01();
    test02();
    return 0;
}