//
// Created by Shawn Huang on 2022/4/12.
//

#ifndef PCR_TEST_PCRTEST_H
#define PCR_TEST_PCRTEST_H

#include <fstream>
#include "Person.h"
#include "Queue.h"
#include "LinkList.h"
#include "Assistance.h"

using namespace std;

class PCRTest {
private:
    Queue mixed, single;

    int mixed_count, single_count;

    LinkList<string> sub_close;

    // 入队辅助程序，根据选择的类型入对应的队伍，并设置人员排队中
    void EnQueue(const string &elem, int select);

    // 出队辅助程序，根据选择的类型出对应的队伍，并设置人员等待上传结果
    void DeQueue(string &elem, int select);

public:
    PCRTest();

    // 从文件读取人员信息，并将人员信息放入对应的队伍中
    void ImportQueueData();

    // 从文件读取完成核酸检测的人数，进行出队操作
    void ImportCheckedData();

    // 命令行入队
    void EnQueue();

    // 命令行出队
    void DeQueue();

    // 显示当前排队
    void ShowQueue();

    // 进行PCR测试
    void PerformTest();

    // 选择0为混合队列，选择1为单队列
    // 获取样本编号
    string GetSampleNo(int select);

    // 确认输入的混合检测样本序号是否正确
    bool CheckSampleNo(const string &sample_no);

    // 标记密接
    void MarkClose(int pos);

    // 标记次密接
    void MarkSubClose();

    // 按类型查询人员
    void CategoryQuery();

    void StateQuery(int select);

    void ContactQuery(int select);

    // 按编号查询人员
    void PersonQuery();
};


#endif //PCR_TEST_PCRTEST_H
