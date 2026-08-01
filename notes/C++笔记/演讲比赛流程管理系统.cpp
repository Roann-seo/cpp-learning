#include<iostream>
#include "speechManager.h"
using namespace std;

int main() {
    // 设置随机种子
    srand((unsigned int)time(NULL));

    // 创建演讲比赛管理对象
    SpeechManager sm;
    
    // // 测试：打印初始选手
    //sm.printSpeaker();  // 可以在 initSpeech 被调用后使用
    // 用户交互循环
    int choice = 0;
    bool running = true;
    while (running) {
        sm.showMenu();
        cout << "请输入你的选择：";
        cin >> choice;
        switch (choice) {
        case 1:         // 开始演讲比赛
            sm.startSpeech();
            break;
        case 2:         // 查看往届记录
            sm.loadRecord();
            sm.showRecord();
            
            break;
        case 3:         // 清空比赛记录
            sm.clearRecord();
            break;
        case 0:         // 退出系统
            sm.exitSystem();
            running = false;
            break;
        default:
            cout << "输入有误，请重新输入！" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    return 0;
}
