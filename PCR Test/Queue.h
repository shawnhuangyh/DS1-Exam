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

    // Type=0:混管，Type=1:单管
    void SetNegative(int pos, int type);

    // Type=0:混管，Type=1:单管
    // 设置单管可疑或混管阳性
    void SetSuspicious(int pos, int type);

    void SetPositive(int pos);

    void SetContact(int pos);

    void SetSubContact(int pos);

    Person GetElem(int pos);

    int GetRear();
};


#endif //PCR_TEST_QUEUE_H
