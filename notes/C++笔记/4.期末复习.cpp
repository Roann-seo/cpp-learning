#include<iostream>
#include<string>
using namespace std;
class student{
    private:
    string name;
    double score;
    public:
    student(string n,double s){
        name=n;
        score=s;
    }
    void display(){
        cout<<"name:"<<name<<" score:"<<score<<endl;
    }
    static double getaverage(student arr[],int n){
        double sum=0.0;
        for(int i=0;i<n;i++){
            sum+=arr[i].score;
        }
        return sum/n;
    }
};
int main(){
    student arr[3]={student("Alice",90),student("Bob",80),student("Charlie",85)};
    for(int i=0;i<3;i++){
        arr[i].display();
    }cout<<"average score"<<student::getaverage(arr,3)<<endl;
    return 0;
}