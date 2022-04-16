//
// Created by Shawn Huang on 2022/4/11.
//

#include "Queue.h"


Queue::Queue() {
    front = rear = maxsize = 0;
    elems = nullptr;
}

Queue::Queue(int max) {
    front = rear = 0;
    maxsize = max;
    elems = new Person[maxsize];
}

Queue::Queue(const Queue &copy) {
    front = copy.front;
    rear = copy.rear;
    maxsize = copy.maxsize;
    elems = new Person[maxsize];
    for (int i = 0; i < maxsize; i++) {
        elems[i] = copy.elems[i];
    }
}

Queue &Queue::operator=(const Queue &copy) {
    if (this != &copy) {
        delete[] elems;
        front = copy.front;
        rear = copy.rear;
        maxsize = copy.maxsize;
        elems = new Person[maxsize];
        for (int i = 0; i < maxsize; i++) {
            elems[i] = copy.elems[i];
        }
    }
    return *this;
}

Queue::~Queue() {
    delete[] elems;
    front = rear = maxsize = 0;
}

bool Queue::EnQueue(Person elem) {
    if (IsFull()) {
        cout << "队列已满！" << endl;
        return false;
    } else {
        elems[rear++] = elem;
        return true;
    }
}

bool Queue::DeQueue(Person &elem) {
    if (IsEmpty()) {
        cout << "Queue is empty" << endl;
        return false;
    } else {
        elem = elems[front++];
        return true;
    }
}

bool Queue::IsEmpty() const {
    return rear == front;
}

bool Queue::IsFull() const {
    return rear == maxsize;
}

void Queue::ShowQueue() {
    for (int i = front; i < rear; i++) {
        cout << elems[i++] << " ";
    }
    cout << endl;
}

Person Queue::FindElem(const string& elem) {
    for (int i = 0; i < rear; i++) {
        if (elems[i].getSampleID() == elem) {
            return elems[i];
        }
    }
    return {};
}