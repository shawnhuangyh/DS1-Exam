//
// Created by Shawn Huang on 2022/4/11.
//

#ifndef PCR_TEST_QUEUE_H
#define PCR_TEST_QUEUE_H

#include <iostream>
#include "Node.h"
#include "Person.h"

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

    bool IsEmpty() const;

    bool IsFull() const;

    void ShowQueue();

    Person FindElem(const string& elem);

};


#endif //PCR_TEST_QUEUE_H
