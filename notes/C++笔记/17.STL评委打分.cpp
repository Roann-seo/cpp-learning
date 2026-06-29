#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;
class person{
    public:
    string m_name;
    int m_score;
    person(string name,int score){
        m_name=name;
        m_score=score;
    }
};
void createperson(vector<person>&v){
    string nameseed="ABCDE";
    for(int i=0;i<5;i++){
        string name="选手";
        name+=nameseed[i];
        int score=0;
        person p(name,score);
        v.push_back(p);
    }
}
void setscore(vector<person>&v){
    for(vector<person>::iterator it=v.begin();it!=v.end();it++){
        deque<int>d;
        for(int i=0;i<10;i++){
            int score=rand()%41+60;
            d.push_back(score);  
        }
        sort(d.begin(),d.end());
            d.pop_back();
            d.pop_front();
            int sum=0;
            for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
                sum+=*dit;
            }
            int avg=sum/d.size();
            it->m_score=avg;
    }
}
void show(vector<person>&v){
    for(vector<person>::iterator it=v.begin();it!=v.end();it++){
        cout<<"姓名 "<<it->m_name<<" 成绩"<<it->m_score<<endl;
    }
}
int main(){
    srand((unsigned int)time(NULL));
    //创建五名选手
    vector<person>p;
    createperson(p);
    //给五名选手打分
    setscore(p);
    //创建的分
    show(p);
    return 0;
}