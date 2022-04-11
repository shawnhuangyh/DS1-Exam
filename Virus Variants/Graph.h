//
// Created by Shawn Huang on 2022/4/11.
//

#ifndef VIRUS_VARIANTS_GRAPH_H
#define VIRUS_VARIANTS_GRAPH_H

#include "DisjointSet.h"

template<typename T>
class Graph {
protected:
    T **arcs;
    int vexNum;
    int arcNum;
public:
    Graph();

    Graph(int num);

    Graph(const Graph &copy);

    Graph &operator=(const Graph &copy);

    ~Graph();

    void AddArc(int v, int w);

    void FindArc(int v, int w, DisjointSet<T> &set);

    void Test();

};

template<typename T>
Graph<T>::Graph() {
    vexNum = 0;
    arcNum = 0;
    arcs = nullptr;
}

template<typename T>
Graph<T>::Graph(int num) {
    vexNum = num;
    arcNum = 0;
    arcs = new T *[vexNum];
    for (int i = 0; i < vexNum; i++) {
        arcs[i] = new T[vexNum];
        for (int j = 0; j < vexNum; ++j)
            arcs[i][j] = 0;
    }
}

template<typename T>
Graph<T>::Graph(const Graph &copy) {
    vexNum = copy.vexNum;
    arcNum = copy.arcNum;
    arcs = new T *[vexNum];
    for (int i = 0; i < vexNum; i++) {
        arcs[i] = new T[vexNum];
        for (int j = 0; j < vexNum; j++)
            arcs[i][j] = copy.arcs[i][j];
    }
}

template<typename T>
Graph<T> &Graph<T>::operator=(const Graph &copy) {
    if (this != &copy) {
        for (int i = 0; i < vexNum; i++)
            delete[] arcs[i];
        delete[] arcs;
        vexNum = copy.vexNum;
        arcNum = copy.arcNum;
        arcs = new T *[vexNum];
        for (int i = 0; i < vexNum; i++) {
            arcs[i] = new T[vexNum];
            for (int j = 0; j < vexNum; j++)
                arcs[i][j] = copy.arcs[i][j];
        }
    }
    return *this;
}

template<typename T>
Graph<T>::~Graph() {
    for (int i = 0; i < vexNum; i++)
        delete[] arcs[i];
    delete[] arcs;
    vexNum = 0;
    arcNum = 0;
}

template<typename T>
void Graph<T>::AddArc(int v, int w) {
    if (v <= 0 || v > vexNum || w <= 0 || w > vexNum)
        return;
    v--;
    w--;
    arcs[v][w] = 1;
    arcs[w][v] = 1;
    arcNum++;
}

template<typename T>
void Graph<T>::FindArc(int v, int w, DisjointSet<T> &set) {
    if (v <= 0 || v > vexNum || w <= 0 || w > vexNum)
        return;
    v--;
    w--;
    for (int i = 0; i < vexNum; ++i) {
        if (arcs[w][i] == 1 && v != i) {
            set.Union(v + 1, i + 1);
        }
    }
}

template<typename T>
void Graph<T>::Test() {
    for (int i = 0; i < vexNum; ++i) {
        for (int j = 0; j < vexNum; ++j) {
            cout << arcs[i][j] << " ";
        }
        cout << endl;
    }

}


#endif //VIRUS_VARIANTS_GRAPH_H
