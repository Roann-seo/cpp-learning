#include<iostream>
using namespace std;
template<class T>
class MyArray{
    private:
    T* pAddress;
    int m_capacity;
    int m_size;
    public:
    MyArray(int capacity){
        cout<<"有参构造调用"<<endl;
        this->m_capacity=capacity;
        this->m_size=0;
        this->pAddress=new T[capacity];
    }
    MyArray(const MyArray&p){
        cout<<"拷贝构造调用"<<endl;
        this->m_capacity=p.m_capacity;
        this->m_size=p.m_size;
        //深拷贝
        this->pAddress=new T[p.m_capacity];
        for(int i=0;i<p.m_size;i++){
            this->pAddress[i]=p.pAddress[i];
        }
    }
    //operator=重载 防止浅拷贝
    MyArray& operator=(const MyArray& arr){
        cout<<"operator=构造调用"<<endl;
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
    ~MyArray(){
        if(this->pAddress!=NULL){
            delete[] this->pAddress;
            this->pAddress=NULL;
        }
    }
};
void test01(){
    MyArray<int>arr1(5);
    MyArray<int>arr2(arr1);
    MyArray<int>arr3(100);
    arr3=arr1;
}
int main(){
    test01();
    return 0;
}