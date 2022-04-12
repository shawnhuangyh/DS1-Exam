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


