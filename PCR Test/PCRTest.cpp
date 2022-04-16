//
// Created by Shawn Huang on 2022/4/12.
//

#include "PCRTest.h"

PCRTest::PCRTest() : mixed_count(0), single_count(0), mixed(10000), single(10000) {}

void PCRTest::ImportQueueData() {
    int n, m;
    ifstream infile;
    infile.open("Test Cases/Queue.txt");
    infile >> n >> m;
    for (int i = 0; i < n; ++i) {
        string x;
        infile >> x;
        EnQueue(x, 0);
    }
    for (int i = 0; i < m; ++i) {
        string x;
        infile >> x;
        EnQueue(x, 1);
    }
    infile.close();
}

void PCRTest::ImportCheckedData() {
    int n, m;
    ifstream infile;
    infile.open("Test Cases/Checked.txt");
    infile >> n >> m;
    for (int i = 0; i < n; ++i) {
        string temp;
        DeQueue(temp, 0);
    }
    for (int i = 0; i < m; ++i) {
        string temp;
        DeQueue(temp, 1);
    }
    infile.close();
}

void PCRTest::EnQueue(const string &elem, int select) {
    if (select == 0) {
        Person temp(elem);
        mixed.EnQueue(temp);
        temp.setState(IN_QUEUE);
    } else {
        Person temp(elem);
        single.EnQueue(temp);
        temp.setState(IN_QUEUE);
    }
}

void PCRTest::EnQueue() {
    string PersonID;
    char type;
    cout << "===========排队===========" << endl;
    cout << "请输入检测人的人员编号：" << endl;
    cin >> PersonID;
    cout << endl << "请选择检测类型" << endl << "0：10人混合检测 ; 1：单人单管检测" << endl << "请输入(0/1)：";
    cin >> type;
    if (type == '0') {
        EnQueue(PersonID, 0);
        cout << endl << "排队成功！" << endl << endl;
    } else if (type == '1') {
        EnQueue(PersonID, 1);
        cout << endl << "排队成功！" << endl << endl;
    } else {
        cout << endl << "输入错误，请重新输入！" << endl << endl;
    }
}

void PCRTest::DeQueue(string &elem, int select) {
    Person temp;
    if (select == 0) {
        string sample = GetSampleNo(0);
        mixed.DeQueue(temp, sample);
        elem = temp.getPersonID();
        mixed_count++;
    } else {
        string sample = GetSampleNo(1);
        single.DeQueue(temp, sample);
        elem = temp.getPersonID();
        single_count++;
    }
}

void PCRTest::DeQueue() {
    char type;
    string temp;
    cout << "===========采样===========" << endl;
    cout << endl << "请选择检测类型" << endl << "0：10人混合检测 ; 1：单人单管检测" << endl << "请输入(0/1)：";
    cin >> type;
    if (type == '0') {
        DeQueue(temp, 0);
        cout << endl << temp << "混合检测完成！" << endl << endl;
    } else if (type == '1') {
        DeQueue(temp, 1);
        cout << endl << temp << "单管检测完成！" << endl << endl;
    } else {
        cout << endl << "输入错误，请重新输入！" << endl << endl;
    }
}

void PCRTest::ShowQueue() {
    cout << "==========排队情况==========" << endl;
    cout << "10人混合检测：" << endl;
    mixed.ShowQueue();
    cout << "单人单管检测：" << endl;
    single.ShowQueue();
    cout << endl;
}

void PCRTest::PerformTest() {
    string SampleNo;
    int result;
    cout << "==========检测登记管==========" << endl;
    cout << "请输入采样编号：" << endl;
    cin >> SampleNo;
    int temp;
    if (SampleNo[0] == '0') {
        if (CheckSampleNo(SampleNo)) {
            cout << endl << "请输入结果" << endl << "0：阴性 ; 1：阳性 ; 2：可疑" << endl << "请输入(0-2)：";
            cin >> result;
            switch (result) {
                case 0:
                    temp = mixed.FindSample(SampleNo);
                    mixed.SetNegative(temp);
                    break;
                case 1:
                case 2:
                    temp = mixed.FindSample(SampleNo);
                    mixed.SetSuspicious(temp, 0);
                    break;
                default:
                    cout << endl << "输入错误，请重新输入！" << endl << endl;
                    break;
            }
        } else {
            cout << "当前试管还没有到10人，请混检到10人后再进行检测！" << endl;
            return;
        }
    } else {
        //TODO 单管检测
    }
}

string PCRTest::GetSampleNo(int select) {
    string output;
    int num = 4;
    int sampleNo;
    if (select == 0) {
        sampleNo = mixed_count / 10;
    } else {
        sampleNo = single_count;
    }
    output = to_string(select) + string(num - to_string(sampleNo).length(), '0') + to_string(sampleNo);
    return output;
}

bool PCRTest::CheckSampleNo(const string &sample_no) {
    int sample = stoi(sample_no.substr(1, 4));
    if (mixed_count / 10 > sample || mixed.IsEmpty()) {
        return true;
    } else {
        return false;
    }
}

void PCRTest::PersonQuery() {
    cout << "==========个人查询==========" << endl;
    string id;
    cout << "请输入个人编号：" << endl;
    cin >> id;
    State state;
    string sample;
    Person temp;
    int index = mixed.FindPerson(id);
    if (index != -1) {
        temp = mixed.GetElem(index);
        state = temp.getState();
        sample = temp.getSampleID();
        cout << endl << "个人编号：" << id << endl << "样本编号：" << sample << endl << "结果是：" << state << endl;
    } else {
        index = single.FindPerson(id);
        if (index != -1) {
            temp = single.GetElem(index);
            state = temp.getState();
            sample = temp.getSampleID();
            cout << endl << "个人编号：" << id << endl << "样本编号：" << sample << endl << "结果是：" << state << endl;
        }
    }
}
