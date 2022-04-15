//
// Created by Shawn Huang on 2022/4/12.
//

#ifndef PCR_TEST_LINKLIST_H
#define PCR_TEST_LINKLIST_H

#include "Node.h"

template<typename T>
class LinkList {
private:
    Node<T> *head;
public:
    LinkList();

    LinkList(const LinkList<T> &copy);

    LinkList &operator=(const LinkList<T> &copy);

    ~LinkList();

    void Insert(T data);

    T GetElement(int index);

};

template<typename T>
LinkList<T>::LinkList() {
    head = nullptr;
}

template<typename T>
LinkList<T>::LinkList(const LinkList<T> &copy) {
    head = nullptr;
    for (Node<T> *i = copy.head; i != nullptr; i = i->next) {
        auto *newNode = new Node<T>(i->data, head);
        head = newNode;
    }
}

template<typename T>
LinkList<T> &LinkList<T>::operator=(const LinkList<T> &copy) {
    if (this != &copy) {
        Node<T> *i = head, *p;
        while (i != nullptr) {
            p = i;
            i = i->next;
            delete p;
        }
        head = nullptr;
        for (i = copy.head; i != nullptr; i = i->next) {
            auto *newNode = new Node<T>(i->data, head);
            head = newNode;
        }
    }
    return *this;
}

template<typename T>
LinkList<T>::~LinkList() {
    Node<T> *i = head, *p;
    while (i != nullptr) {
        p = i;
        i = i->next;
        delete p;
    }
}

template<typename T>
void LinkList<T>::Insert(T data) {
    auto *newNode = new Node<T>(data, head);
    head = newNode;
}

template<typename T>
T LinkList<T>::GetElement(int index) {
    Node<T> *i = head;
    for (int j = 0; j < index; j++) {
        i = i->next;
    }
    return i->data;
}


#endif //PCR_TEST_LINKLIST_H
