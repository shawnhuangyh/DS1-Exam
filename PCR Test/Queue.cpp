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
        cout << "队列为空！" << endl;
        return false;
    } else {
        elem = elems[front++];
        return true;
    }
}

bool Queue::DeQueue(Person &elem, string sample) {
    if (IsEmpty()) {
        cout << "队列为空！" << endl;
        return false;
    } else {
        elems[front].setState(PENDING);
        elems[front].setSampleID(sample);
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
        elems[i].ShowPerson();
    }
    cout << endl;
}

int Queue::FindSample(const string &elem, int pos) {
    for (int i = pos; i < rear; i++) {
        if (elems[i].getSampleID() == elem) {
            return i;
        }
    }
    return -1;
}

int Queue::FindPerson(const string &elem) {
    for (int i = 0; i < rear; i++) {
        if (elems[i].getPersonID() == elem) {
            return i;
        }
    }
    return -1;
}

void Queue::SetNegative(int pos, int type) {
    if (type == 0) {
        for (int i = 0; i < 10; i++) {
            elems[pos + i].setState(NEGATIVE);
        }
    } else {
        elems[pos].setState(NEGATIVE);
    }
}

void Queue::SetSuspicious(int pos, int type) {
    if (type == 0) {
        for (int i = 0; i < 10; i++) {
            elems[pos + i].setState(SUSPICIOUS);
        }
    } else {
        elems[pos].setState(SUSPICIOUS);
    }
}

void Queue::SetPositive(int pos) {
    elems[pos].setState(POSITIVE);
}

void Queue::SetContact(int pos) {
    elems[pos].setContact(CONTACT);
}

Person Queue::GetElem(int pos) {
    return elems[pos];
}

int Queue::GetRear() {
    return rear;
}
