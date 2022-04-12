//
// Created by Shawn Huang on 2022/4/12.
//

#ifndef PCR_TEST_NODE_H
#define PCR_TEST_NODE_H

template<typename T>
class Node {
public:
    T data;
    Node<T> *next;

    Node();

    Node(T val, Node<T> *nt = nullptr);

};

template<typename T>
Node<T>::Node() {
    next = nullptr;
}

template<typename T>
Node<T>::Node(T val, Node<T> *nt) {
    data = val;
    next = nt;
}


#endif //PCR_TEST_NODE_H
