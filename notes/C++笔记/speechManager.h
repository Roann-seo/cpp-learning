#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<string>
#include<algorithm>
#include<functional>
#include<numeric>
#include<ctime>
#include<fstream>
using namespace std;
// 选手类
class Speaker {
public:
    string m_name;                                  // 选手姓名
    double m_score[2];                              // 两轮分数（最多两轮比赛，每轮取一个平均分）
};

// 演讲比赛管理类
class SpeechManager {
public:
    bool fileIsEmpty;
    // 保存第一轮所有选手编号及其选手信息12人
    vector<int> m_v1;

    // 第一轮晋级选手编号，放入vector v2中6人
    vector<int> m_v2;

    // 前三名选手编号，放入vector vVictory中3人
    vector<int> m_vVictory;

    // 存放编号和具体选手信息的容器（map 的 key=编号, value=选手对象）
    map<int, Speaker> m_speaker;

    // 比赛轮数（当前进行到第几轮）
    int m_index;

    //存放往届记录的容器
    map<int,vector<string>>m_record;

    // ************************************
    // 私有成员函数 — 你来实现
    // ************************************

    // 初始化比赛（创建12名选手，初始化 m_speaker 和 m_v1）
    void initSpeech();

    //创建选手信息
    void createSpeaker();

    // 打印所有选手信息
    void printSpeaker();

    // 抽签（对指定 vector 中的选手编号进行随机排序）
    void speechDraw();

    // 比赛流程（对指定 vector 中的选手进行比赛，每组成绩前3名晋级）
    // 传入本轮参赛选手编号，返回晋级选手编号
    // 评委打分用 deque 存储，去掉最高分和最低分后取平均
    void speechContest();

    // 打印晋级结果
    void printPromotionResult();

    // 保存比赛记录到 CSV 文件
    void saveRecord();

    // 加载历史比赛记录
    void loadRecord();


    // 构造函数 — 你来实现
    SpeechManager();

    // 析构函数 — 你来实现
    ~SpeechManager();

    // 显示菜单
    void showMenu();

    // 退出系统
    void exitSystem();

    // ************************************
    // 公开接口 — 你来实现
    // ************************************

    // 开始演讲比赛（整个流程控制：抽签 → 第一轮 → 晋级 → 抽签 → 第二轮 → 最终结果 → 保存）
    void startSpeech();

    // 查看往届比赛记录
    void showRecord();

    // 清空比赛记录
    void clearRecord();
};
