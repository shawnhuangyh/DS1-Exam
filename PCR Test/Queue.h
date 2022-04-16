//
// Created by Shawn Huang on 2022/4/11.
//

#ifndef PCR_TEST_QUEUE_H
#define PCR_TEST_QUEUE_H

#include <iostream>
#include "Person.h"
#include "Assistance.h"

using namespace std;

class Queue {
private:
    int front, rear;

    int maxsize;

    Person *elems;
public:

    Queue();

    Queue(int max);

    Queue(const Queue &copy);

    Queue &operator=(const Queue &copy);

    ~Queue();

    bool EnQueue(Person elem);

    bool DeQueue(Person &elem);

    bool DeQueue(Person &elem, string sample);

    bool IsEmpty() const;

    bool IsFull() const;

    void ShowQueue();

    int FindSample(const string &elem, int pos = 0);

    int FindPerson(const string &elem);

    void SetNegative(int pos);

    // Type=0:混管，Type=1:单管
    void SetSuspicious(int pos, int type);

    Person GetElem(int pos);
};


#endif //PCR_TEST_QUEUE_H
