//
// Created by Shawn Huang on 2022/4/11.
//

#include "Queue.h"


Queue::Queue() {
    head = front = rear = new Node<Person>;
}

Queue::Queue(const Queue &copy) {
    head = front = rear = new Node<Person>;
    for (Node<Person> *i = copy.head; i != nullptr; i = i->next) {
        EnQueue(i->data);
    }
}

Queue &Queue::operator=(const Queue &copy) {
    if (this != &copy) {
        Clear();
        for (Node<Person> *i = copy.head; i != nullptr; i = i->next) {
            EnQueue(i->data);
        }
    }
    return *this;
}

Queue::~Queue() {
    Clear();
    delete head;
    head = front = rear = nullptr;
}

void Queue::Clear() {
    Node<Person> *p = head->next;
    while (p != nullptr) {
        Node<Person> *temp = p;
        p = p->next;
        delete temp;
    }
}

bool Queue::EnQueue(Person elem) {
    auto *newNode = new Node<Person>(elem, nullptr);
    rear->next = newNode;
    rear = newNode;
    return true;
}

bool Queue::DeQueue(Person &elem) {
    if (IsEmpty()) {
        cout << "Queue is empty" << endl;
        return false;
    } else {
        elem = front->next->data;
        front = front->next;
        return true;
    }
}

bool Queue::IsEmpty() {
    return head->next == nullptr;
}

void Queue::ShowQueue() {
    for (Node<Person> *p = front->next; p != nullptr; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;
}

Person Queue::FindElem(string elem) {
    for (Node<Person> *p = front->next; p != nullptr; p = p->next) {
        if (p->data.getSampleID() == elem) {
            return p->data;
        }
    }
}