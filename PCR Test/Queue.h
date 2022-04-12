//
// Created by Shawn Huang on 2022/4/11.
//

#ifndef PCR_TEST_QUEUE_H
#define PCR_TEST_QUEUE_H

#include <iostream>
#include "Node.h"

using namespace std;

template<typename T>
class Queue {
private:
    Node<T> *head, *front, *rear;
public:

    Queue();

    Queue(const Queue &copy);

    Queue &operator=(const Queue &copy);

    ~Queue();

    void Clear();

    bool EnQueue(T elem);

    bool DeQueue(T &elem);

    bool IsEmpty();

    void ShowQueue();

};

template<typename T>
Queue<T>::Queue() {
    head = front = rear = new Node<T>;
}

template<typename T>
Queue<T>::Queue(const Queue &copy) {
    head = front = rear = new Node<T>;
    for (Node<T> i = copy.head; i != nullptr; i = i->next) {
        EnQueue(i->data);
    }
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue &copy) {
    if (this != &copy) {
        Clear();
        for (Node<T> i = copy.head; i != nullptr; i = i->next) {
            EnQueue(i->data);
        }
    }
    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    Clear();
    delete head;
    head = front = rear = nullptr;
}

template<typename T>
void Queue<T>::Clear() {
    Node<T> *p = head->next;
    while (p != nullptr) {
        Node<T> *temp = p;
        p = p->next;
        delete temp;
    }
}

template<typename T>
bool Queue<T>::EnQueue(T elem) {
    auto *newNode = new Node<T>(elem, nullptr);
    rear->next = newNode;
    rear = newNode;
    return true;
}

template<typename T>
bool Queue<T>::DeQueue(T &elem) {
    if (IsEmpty()) {
        cout << "Queue is empty" << endl;
        return false;
    } else {
        elem = front->next->data;
        front = front->next;
        return true;
    }
}

template<typename T>
bool Queue<T>::IsEmpty() {
    return head->next == nullptr;
}

template<typename T>
void Queue<T>::ShowQueue() {
    for (Node<T> *p = front->next; p != nullptr; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;
}


#endif //PCR_TEST_QUEUE_H
