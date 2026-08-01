#include "speechManager.h"
#include<string>
#include<algorithm>
// ****************************************************
// 构造函数
// 初始化：设置随机种子，初始化容器，加载历史记录
// ****************************************************
SpeechManager::SpeechManager() {
    initSpeech();
    createSpeaker();
    loadRecord();
}

// ****************************************************
// 析构函数
// ****************************************************
SpeechManager::~SpeechManager() {
    // TODO: 你的代码
}

// ****************************************************
// 显示菜单
// 输出菜单选项供用户选择
// ****************************************************
void SpeechManager::showMenu() {
    cout<<"**********************************"<<endl;
    cout<<"********欢迎参加演讲比赛***********"<<endl;
    cout<<"*********1.开始演讲比赛************"<<endl;
    cout<<"*********2.查看往届记录************"<<endl;
    cout<<"*********3.清空比赛记录************"<<endl;
    cout<<"*********0.退出比赛程序************"<<endl;
    cout<<"**********************************"<<endl;
    system("pause");
}

// ****************************************************
// 退出系统
// ****************************************************
void SpeechManager::exitSystem() {
    cout<<"欢迎下次使用"<<endl;
    system("pause");
}

// ****************************************************
// 初始化比赛
// 1. 容器清空
// 2. 创建12名选手，编号 10001~10012
// 3. 将选手信息存入 m_speaker
// 4. 将选手编号存入 m_v1
// ****************************************************
void SpeechManager::initSpeech() {
    m_v1.clear();
    m_v2.clear();
    m_vVictory.clear();
    m_speaker.clear();
    m_index=1;
    //将记录容器清空
    m_record.clear();
}
void SpeechManager::createSpeaker(){
    string nameseed="ABCDEFGHIJKL";
    for(int i=0;i<nameseed.size();i++){
        Speaker sp;
        sp.m_name="选手";
        sp.m_name+=nameseed[i];
        for(int j=0;j<2;j++){
            sp.m_score[j]=0;
        }
        m_v1.push_back(i+10001);
        m_speaker.insert(make_pair(i+10001,sp));
    }
}
// ****************************************************
// 打印所有选手信息
// 遍历 m_speaker，使用迭代器输出每个选手的姓名和编号
// ****************************************************
void SpeechManager::printSpeaker() {
    for(map<int,Speaker>::iterator it=m_speaker.begin();it!=m_speaker.end();it++){
        cout<<"编号: "<<it->first
        <<" 姓名: "<<it->second.m_name
        <<" 成绩1: "<<it->second.m_score[0]
        <<" 成绩2: "<<it->second.m_score[1]<<endl;
    }
}

// ****************************************************
// 抽签 — 随机打乱选手出场顺序
// 使用 random_shuffle 对传入的 vector 进行乱序
// ****************************************************
void SpeechManager::speechDraw() {
    cout<<"第"<<m_index<<"次比赛选手正在抽签"<<endl;
    if(m_index==1){
        cout<<"初赛抽签"<<endl;
        random_shuffle(m_v1.begin(),m_v1.end());
        for(vector<int>::iterator it=m_v1.begin();it!=m_v1.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"决赛抽签"<<endl;
        random_shuffle(m_v2.begin(),m_v2.end());
        for(vector<int>::iterator it=m_v2.begin();it!=m_v2.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

// ****************************************************
// 比赛流程
// 参数：
//   v_input  — 本轮参赛选手编号
//   v_output — 存放本轮晋级选手编号
//
// 流程：
//   1. 将 v_input 中的选手每6人一组
//   2. 每组选手依次"上台演讲"
//   3. 用 deque 存储10个评委的随机打分 (60~100)
//   4. sort 排序，去掉最高分和最低分
//   5. accumulate 求平均分，存入 m_speaker[编号].m_score[m_index]
//   6. 每组按平均分排序，取前3名放入 v_output
// ****************************************************
void SpeechManager::speechContest() {
    multimap<double,int,greater<double>>groupscore;//临时容器 存放小组成绩
    int num=0;
    cout<<"第"<<m_index<<"轮演讲比赛开始"<<endl;
    vector<int>src;//判断是第几轮
    if(m_index==1){
        src=m_v1;//初赛，一共12个人
    }else{
        src=m_v2;//决赛，一共6个人
    }
    for(vector<int>::iterator it=src.begin();it!=src.end();it++){
        //遍历选手的for循环
        deque<double>d;//评委打分，10个评委给每个人打的分数
        for(int i=0;i<10;i++){
            double score=(rand()%401+600)/10.f;
            //cout<<score<<" ";
            d.push_back(score);
        }
        //cout<<endl;
        sort(d.begin(),d.end(),greater<double>());
        d.pop_back();//去掉最低分
        d.pop_front();//去掉最高分
        double sum=accumulate(d.begin(),d.end(),0.0f);
        double avg=sum/(double)d.size();
        m_speaker[*it].m_score[m_index-1]=avg;
        // cout<<"编号: "<<*it
        // <<" 姓名: "<<m_speaker[*it].m_name
        // <<" 平均分: "<<avg<<endl;
        num++;//每遍历一个选手，num个数就加一，将其分成两组
        groupscore.insert(make_pair(avg,*it));
        if(num%6==0){
            if(num/6==1){
                cout<<"第一演讲小组"<<endl;
                for(multimap<double,int>::iterator mit=groupscore.begin();
            mit!=groupscore.end();mit++){
                cout<<"编号:"<<mit->second
                <<" 姓名: "<<m_speaker[mit->second].m_name
                <<" 成绩："<<mit->first<<endl;
                
                //m_v2.push_back((*mit).second);
                }
            }
            else{
                cout<<"第二演讲小组"<<endl;
                for(multimap<double,int>::iterator mit=groupscore.begin();
            mit!=groupscore.end();mit++){
                cout<<"编号:"<<mit->second
                <<" 姓名: "<<m_speaker[mit->second].m_name
                <<" 成绩："<<mit->first<<endl;
                }
            }
            //每个小组选前三名晋级
            int count=0;
            for(multimap<double,int>::iterator mit=groupscore.begin();
        mit!=groupscore.end()&&count<3;mit++,count++){
                if(m_index==1){
                //     cout<<"进入初赛的选手:"<<endl;
                //     cout<<"编号:"<<mit->second
                // <<" 姓名: "<<m_speaker[mit->second].m_name
                // <<" 成绩："<<mit->first<<endl;
                m_v2.push_back((*mit).second);
                }else{
                //     cout<<"进入决赛的选手:"<<endl;
                //     cout<<"编号:"<<mit->second
                // <<" 姓名: "<<m_speaker[mit->second].m_name
                // <<" 成绩："<<mit->first<<endl;
                m_vVictory.push_back((*mit).second);
                }
        }
            groupscore.clear();
        }
    }
    cout<<"--------第"<<m_index<<"轮比赛结束----------"<<endl;
    system("pause");
}


// ****************************************************
// 打印晋级结果
// 遍历 v，输出第 round 轮晋级选手的姓名和分数
// ****************************************************
void SpeechManager::printPromotionResult() {
    vector<int>v;
    if(m_index==1){
        v=m_v2;
    }else{
        v=m_vVictory;
    }
    cout<<"晋级结果"<<endl;
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<"编号:"<<*it
        <<" 姓名: "<<m_speaker[*it].m_name
        <<" 成绩: "<<m_speaker[*it].m_score[m_index-1];
        cout<<endl;
    }
}

// ****************************************************
// 开始演讲比赛 — 整个流程控制
// 1. 第一轮比赛
//    a. 抽签 (speechDraw)
//    b. 比赛 (speechContest) → m_v2
//    c. 打印晋级结果
// 2. 第二轮比赛
//    a. 抽签
//    b. 比赛 → m_vVictory
//    c. 打印晋级结果
// 3. 打印最终前三名
// 4. 保存记录
// ****************************************************
void SpeechManager::startSpeech() {
    //第一轮比赛开始
    //1.抽签
    speechDraw();
    //2.比赛
    speechContest();
    //3.显示晋级结果
    printPromotionResult();
    //第二轮比赛开始
    m_index++;
    //4.抽签
    speechDraw();
    //5.比赛
    speechContest();
    //6.显示最终结果
    printPromotionResult();
    //7.保存
    saveRecord();
    initSpeech();
    createSpeaker();
    loadRecord();
    cout<<"比赛结束"<<endl;
}

// ****************************************************
// 查看往届比赛记录
// 从 CSV 文件读取历史记录并显示
// ****************************************************
void SpeechManager::showRecord() {
    // cerr << "[DEBUG] showRecord() 被调用了, m_record.size = " << m_record.size() << endl;
    // cout << "调试:m_record容器大小 = " << m_record.size() << endl;
    cout.flush();
    //system("pause");
    if(fileIsEmpty){
        cout<<"文件为空或者文件不存在"<<endl;
    }
    else{
        for(map<int,vector<string>>::iterator it=m_record.begin();it!=m_record.end();it++){
        cout<<"第"<<it->first<<"轮"<<endl;
        cout<<"冠军编号:"<<it->second[0]<<" 冠军成绩: "<<it->second[1]
        <<"亚军编号:"<<it->second[2]<<" 亚军成绩: "<<it->second[3]
        <<"季军编号:"<<it->second[4]<<" 季军成绩: "<<it->second[5];
        }
    }
    cout<<endl;
    system("pause");
    system("cls");
}

// ****************************************************
// 保存比赛记录到文件
// 格式：第x届, 冠军姓名, 亚军姓名, 季军姓名
// ****************************************************
void SpeechManager::saveRecord() {
    ofstream ofs;
    ofs.open("speech.csv",ios::out|ios::app);//用追加的方式写文件
    for(vector<int>::iterator it=m_vVictory.begin();it!=m_vVictory.end();it++){
        ofs<<*it<<","<<m_speaker[*it].m_score[1]<<",";
    }
    ofs<<endl;
    ofs.close();
    cout<<"记录已保存"<<endl;
    fileIsEmpty=false;
}

// ****************************************************
// 加载历史比赛记录
// ****************************************************
void SpeechManager::loadRecord() {
    ifstream ifs("speech.csv",ios::in);//读文件
    if(!ifs.is_open()){
        cout<<"文件打不开"<<endl;
        this->fileIsEmpty=true;
        ifs.close();
        return;
    }
    //文件清空
    char ch;
    ifs>>ch;//先读走一个字符
    if(ifs.eof()){
        cout<<"文件为空"<<endl;
        fileIsEmpty=true;
        ifs.close();
        return ;
    }
    fileIsEmpty=false;
    ifs.putback(ch);//将上面的单个字符读回来
    string data;
    int index=1;
    while(ifs>>data){
        int start=0;//每行重置start
        int pos=-1;//位置变量
        vector<string>v;//每行一个新的vector，存放六个字符串
        //cout<<data<<endl;
        while(true){
            pos=data.find(",",start);
            if(pos==-1){
                // 处理最后一段数据（最后一个逗号后面的部分）
                string temp=data.substr(start);
                v.push_back(temp);
                break;
            }
            string temp=data.substr(start,pos-start);
            //cout<<temp<<" ";
            v.push_back(temp);
            start=pos+1;
        }
        m_record.insert(make_pair(index,v));
        index++;
    }
    ifs.close();
    // for(map<int,vector<string>>::iterator it=m_record.begin();it!=m_record.end();it++){
    //     cout<<"冠军"<<it->first<<"编号"<<it->second[0]<<"成绩"<<it->second[1];
    // }
    // cout<<endl;
}

// ****************************************************
// 清空比赛记录
// 清空文件内容
// ****************************************************
void SpeechManager::clearRecord() {
    cout<<"确认清空?"<<endl;
    cout<<"1.确认"<<endl;
    cout<<"2.返回"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        ofstream ofs("speech.csv",ios::trunc);
        //ios::trunc 如果存在删除文件并重新创建
        initSpeech();
        createSpeaker();
        loadRecord();
        cout<<"清空成功"<<endl;
    }
    system("pause");
    system("cls");
}
