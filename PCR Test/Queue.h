//
// Created by Shawn Huang on 2022/4/11.
//

#ifndef PCR_TEST_QUEUE_H
#define PCR_TEST_QUEUE_H

#include <iostream>
#include "Person.h"
#include "Assistance.h"

using namespace std;

class Queue {
private:
    int front, rear;

    int maxsize;

    Person *elems;
public:

    Queue();

    Queue(int max);

    Queue(const Queue &copy);

    Queue &operator=(const Queue &copy);

    ~Queue();

    // 入队
    bool EnQueue(Person elem);

    // 出队
    bool DeQueue(Person &elem);

    // 出队，并修改其属性
    bool DeQueue(Person &elem, string sample);

    bool IsEmpty() const;

    bool IsFull() const;

    void ShowQueue();

    // 根据指定的位置开始，根据样本编号寻找队伍序号
    int FindSample(const string &elem, int pos = 0);

    // 根据人员编号寻找队伍序号
    int FindPerson(const string &elem);

    // Type=0:混管，Type=1:单管
    // 设置阴性
    void SetNegative(int pos, int type);

    // Type=0:混管，Type=1:单管
    // 设置单管可疑或混管阳性
    void SetSuspicious(int pos, int type);

    // 设置单管阳性
    void SetPositive(int pos);

    // 设置密接属性
    void SetContact(int pos);

    // 设置核酸属性
    void SetSubContact(int pos);

    // 返回Person对象
    Person GetElem(int pos);

    // 获取队伍的末尾数字
    int GetRear();
};


#endif //PCR_TEST_QUEUE_H
