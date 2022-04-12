//
// Created by Shawn Huang on 2022/4/12.
//

#ifndef PCR_TEST_PCRTEST_H
#define PCR_TEST_PCRTEST_H

#include <fstream>
#include "Queue.h"
#include "DataBase.h"

using namespace std;

class PCRTest {
private:
    Queue<string> mixed, single;
    int mixed_count, single_count;
public:
    PCRTest();

    void ImportQueueData();

    void ImportCheckedData();

    void EnQueue();

    void ShowQueue();
};


#endif //PCR_TEST_PCRTEST_H
