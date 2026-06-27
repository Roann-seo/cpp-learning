#include<iostream>
using namespace std;
#include<string>
//查找
void test01(){
    string str1;
    str1.assign("abcdefde");
    // find 是从左往右查找，返回值是 size_t（无符号类型）
    // npos 是一个静态常量，值为 -1（无符号时是最大值），表示未找到
    size_t pos = str1.find("de");
    if(pos == string::npos){  // 判断是否找到，用 string::npos 而不是 -1
        cout << "未找到" << endl;
    }
    else{
        cout << "找到了" << pos << endl;  // 找到了 3
    }
    pos = str1.rfind("de");  // rfind 是从右往左查，返回的还是从左往右的下标
    cout << pos << endl;  // 6
}
//2.替换
void test02(){
    string str2="abcdef";
    str2.replace(1,3,"1111");
    //从1号位置起3个字符 替换为“1111”
    cout<<str2<<endl;
}
//3.比较
void test03(){
    string str3="hello";
    string str4="xello";
    int ret=str3.compare(str4);
    if(ret==0){
        cout<<"str3等于str4"<<endl;
    }
    else if(ret>0){
        cout<<"str3大于str4"<<endl;
    }
    else{
        cout<<"str3小于str4"<<endl;
    }
}
//4.存取
void test04(){
    string str5="hello";
    for(int i=0;i<str5.size();i++){
        cout<<str5[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<str5.size();i++){
        cout<<str5.at(i)<<" ";
    }
    cout<<endl;
    str5[0]='x';
    cout<<str5<<endl;
    str5.at(0)='x';
    cout<<str5<<endl;
}
//插入和删除
void test05(){
    string str6="hello";
    str6.insert(1,"111");
    cout<<str6<<endl;
    str6.erase(1,3);
    cout<<str6<<endl;
}
//子串
void test06(){
    string str7="zhangsan@outlook.com";
    int pos=str7.find("@");
    string username=str7.substr(0,pos);
    cout<<username<<endl;
}
int main(){
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    return 0;
}