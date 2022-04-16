//
// Created by Shawn Huang on 2022/4/12.
//

#ifndef PCR_TEST_PCRTEST_H
#define PCR_TEST_PCRTEST_H

#include <fstream>
#include "Person.h"
#include "Queue.h"
#include "LinkList.h"
#include "Assistance.h"

using namespace std;

class PCRTest {
private:
    Queue mixed, single;

    int mixed_count, single_count;

    LinkList<string> close, sub_close;

    void EnQueue(const string &elem, int select);

    void DeQueue(string &elem, int select);

public:
    PCRTest();

    void ImportQueueData();

    void ImportCheckedData();

    void EnQueue();

    void DeQueue();

    void ShowQueue();

    void PerformTest();

    // 选择0为混合队列，选择1为单队列
    string GetSampleNo(int select);

    // 确认输入的混合检测样本序号是否正确
    bool CheckSampleNo(const string &sample_no);

    //TODO  按类别查询

    void PersonQuery();
};


#endif //PCR_TEST_PCRTEST_H
