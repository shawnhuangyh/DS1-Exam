//
// Created by Shawn Huang on 2022/4/11.
//

#ifndef PCR_TEST_QUEUE_H
#define PCR_TEST_QUEUE_H

#include <iostream>

using namespace std;

template<typename T>
class Queue {
private:
    T *elems = nullptr;
    int front, rear;
    int capacity;
public:

    Queue();

    Queue(int num);

    Queue(const Queue &copy);

    Queue &operator=(const Queue &copy);

    ~Queue();

    bool EnQueue(T elem);

    bool DeQueue(T &elem);

    bool IsEmpty();

    bool IsFull();

    void ShowQueue();

};

template<typename T>
Queue<T>::Queue() {
    elems = nullptr;
    front = 0;
    rear = 0;
    capacity = 0;
}

template<typename T>
Queue<T>::Queue(int num) {
    elems = new T[capacity];
    front = 0;
    rear = 0;
    capacity = num;
}

template<typename T>
Queue<T>::Queue(const Queue &copy) {
    front = copy.front;
    rear = copy.rear;
    capacity = copy.capacity;
    elems = new T[capacity];
    for (int i = 0; i < capacity; i++) {
        elems[i] = copy.elems[i];
    }
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue &copy) {
    if (this != &copy) {
        delete[] elems;
        front = copy.front;
        rear = copy.rear;
        capacity = copy.capacity;
        elems = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            elems[i] = copy.elems[i];
        }
    }
    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    delete[] elems;
    front = rear = capacity = 0;
}

template<typename T>
bool Queue<T>::EnQueue(T elem) {
    if (IsFull()) {
        cout << "Queue is full" << endl;
        return false;
    } else {
        elems[rear] = elem;
        rear = (rear + 1) % capacity;
        return true;
    }
}

template<typename T>
bool Queue<T>::DeQueue(T &elem) {
    if (IsEmpty()) {
        cout << "Queue is empty" << endl;
        return false;
    } else {
        elem = elems[front];
        front = (front + 1) % capacity;
        return true;
    }
}

template<typename T>
bool Queue<T>::IsEmpty() {
    return rear == front;
}

template<typename T>
bool Queue<T>::IsFull() {
    return (rear + 1) % capacity == front;
}

template<typename T>
void Queue<T>::ShowQueue() {
    int r = rear, f = front;
    while((r + 1) % capacity != f){
        cout << elems[f] << " ";
        f = (f + 1) % capacity;
    }
    cout << endl;
}


#endif //PCR_TEST_QUEUE_H
