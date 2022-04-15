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
    Node<Person> *head, *front, *rear;
public:

    Queue();

    Queue(const Queue &copy);

    Queue &operator=(const Queue &copy);

    ~Queue();

    void Clear();

    bool EnQueue(Person elem);

    bool DeQueue(Person &elem);

    bool IsEmpty();

    void ShowQueue();

    Person FindElem(string elem);

};



#endif //PCR_TEST_QUEUE_H
