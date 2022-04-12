//
// Created by Shawn Huang on 2022/4/12.
//

#ifndef PCR_TEST_PCRTEST_H
#define PCR_TEST_PCRTEST_H

#include <fstream>
#include "Person.h"
#include "Queue.h"
#include "DataBase.h"

using namespace std;

class PCRTest {
private:
    Queue<Person> mixed, single;
    int mixed_count, single_count;

    void EnQueue(const string &elem, int select);

    void DeQueue(string &elem, int select);

public:
    PCRTest();

    void ImportQueueData();

    void ImportCheckedData();

    void EnQueue();

    void DeQueue();

    void ShowQueue();
};


#endif //PCR_TEST_PCRTEST_H
