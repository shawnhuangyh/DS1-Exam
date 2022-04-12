//
// Created by Shawn Huang on 2022/4/12.
//

#include "Assistance.h"

string GetBuildingNo(const string &PersonNo) {
    return PersonNo.substr(0, 3);
}

string GetRoomNo(const string &PersonNo) {
    return PersonNo.substr(3, 4);
}

string GetPersonNo(const string &PersonNo) {
    return PersonNo.substr(7, 1);
}

void ImportQueueData(Queue<string> &mixed, Queue<string> &single) {
    int n, m;
    ifstream infile;
    infile.open("Test Cases/Queue.txt");
    infile >> n >> m;
    for (int i = 0; i < n; ++i) {
        string x;
        infile >> x;
        mixed.EnQueue(x);
    }
    for (int i = 0; i < m; ++i) {
        string x;
        infile >> x;
        single.EnQueue(x);
    }
    infile.close();
}

void ImportCheckedData(Queue<string> &mixed, Queue<string> &single) {
    int n, m;
    ifstream infile;
    infile.open("Test Cases/Checked.txt");
    infile >> n >> m;
    for (int i = 0; i < n; ++i) {
        string temp;
        mixed.DeQueue(temp);
    }
    for (int i = 0; i < m; ++i) {
        string temp;
        single.DeQueue(temp);
    }
    infile.close();
}

void ShowMenu() {
    cout << "==========核酸检测系统==========" << endl;
    cout << "1. 排队" << endl;
    cout << "2. 检测" << endl;
    cout << "3. 查看排队" << endl;
    cout << "4. 登记测试管" << endl;
    cout << "5. 各类人员查询" << endl;
    cout << "6. 个人查询" << endl;
    cout << "0. 退出系统" << endl;
    cout << "请选择(0-6)：" << endl;
}


