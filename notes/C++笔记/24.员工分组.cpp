#include<iostream>
#include<vector>
#include<map>
#include<ctime>
#define CEHUA 0;
#define MEISHU 1;
#define YANFA 2;
using namespace std;
class worker{
    public:
    string m_name;
    int m_salary;
};
void createworker(vector<worker>&v){
    string nameseed="ABCDEFGHIJ";
    for(int i=0;i<10;i++){
        worker w;
        w.m_name="员工";
        w.m_name+=nameseed[i];
        w.m_salary=rand()%10000+10000;
        v.push_back(w);
    }
}
void setgroup(vector<worker>&v,multimap<int,worker>&w){
    for(vector<worker>::iterator it=v.begin();it!=v.end();it++){
        int depid=rand()%3;
        w.insert(pair<int,worker>(depid,*it));
    }
}
void showworkerbygroup(multimap<int,worker>&mworker){
    for(multimap<int,worker>::iterator it=mworker.begin();it!=mworker.end();it++){
        if(it->first==0){
            cout<<"策划部门";
            cout<<"name:"<<it->second.m_name<<" salary: "<<it->second.m_salary<<endl;
        }
        if(it->first==1){
            cout<<"美术部门";
            cout<<"name:"<<it->second.m_name<<" salary: "<<it->second.m_salary<<endl;
        }
        if(it->first==2){
            cout<<"研发部门";
            cout<<"name:"<<it->second.m_name<<" salary: "<<it->second.m_salary<<endl;
        }
    }
}
int main(){
    srand((unsigned int)time(NULL));
    vector<worker>vworker;
    //创建员工
    createworker(vworker);
    //员工分组
    multimap<int,worker>mworker;
    setgroup(vworker,mworker);
    showworkerbygroup(mworker);
    return 0;
}