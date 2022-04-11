//
// Created by Shawn Huang on 2022/4/11.
//

#ifndef VIRUS_VARIANTS_DISJOINTSET_H
#define VIRUS_VARIANTS_DISJOINTSET_H

#include <iostream>

using namespace std;


template<typename T>
class DisjointSet {
private:
    T *sets;
    int size;
public:
    DisjointSet();

    DisjointSet(int n);

    DisjointSet(const DisjointSet &copy);

    DisjointSet &operator=(const DisjointSet &copy);

    ~DisjointSet();

    int FindRoot(int i);

    int FindRootHelper(int i);

    void Union(int i, int j);

    int GetCount();

};

template<typename T>
DisjointSet<T>::DisjointSet() {
    size = 0;
    sets = nullptr;
}

template<typename T>
DisjointSet<T>::DisjointSet(int n) {
    size = n;
    sets = new T[size];
    for (int i = 0; i < size; i++) {
        sets[i] = -1;
    }
}

template<typename T>
DisjointSet<T>::DisjointSet(const DisjointSet &copy) {
    size = copy.size;
    sets = new T[size];
    for (int i = 0; i < size; i++)
        sets[i] = copy.sets[i];

}

template<typename T>
DisjointSet<T>::~DisjointSet() {
    delete[] sets;
    size = 0;
}

template<typename T>
DisjointSet<T> &DisjointSet<T>::operator=(const DisjointSet &copy) {
    if (this != &copy) {
        delete[] sets;
        size = copy.size;
        sets = new T[size];
        for (int i = 0; i < size; i++)
            sets[i] = copy.sets[i];
    }
    return *this;
}

template<typename T>
int DisjointSet<T>::FindRoot(int i) {
    if (i <= 0 || i > size) {
        cout << "Range Error!" << endl;
        return -1;
    }
    int root = FindRootHelper(--i);
    return root;
}

template<typename T>
int DisjointSet<T>::FindRootHelper(int i) {
    if (sets[i] < 0) {
        return i;
    } else {
        return FindRootHelper(sets[i]);
    }
}

template<typename T>
void DisjointSet<T>::Union(int i, int j) {
    if (i <= 0 || i > size || j <= 0 || j > size) {
        cout << "Range Error!" << endl;
        return;
    }
    int root_i = FindRoot(i);
    int root_j = FindRoot(j);
    if (root_i >= 0 && root_j >= 0 && root_i != root_j) {
        sets[root_i] += sets[root_j];
        sets[root_j] = root_i;
    }
}

template<typename T>
int DisjointSet<T>::GetCount() {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (sets[i] < 0)
            count++;
    }
    return count;
}



#endif //VIRUS_VARIANTS_DISJOINTSET_H
