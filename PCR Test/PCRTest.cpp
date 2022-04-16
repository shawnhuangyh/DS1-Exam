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
                    mixed.SetNegative(temp, 0);
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
        cout << endl << "请输入结果" << endl << "0：阴性 ; 1：阳性 ; 2：可疑" << endl << "请输入(0-2)：";
        cin >> result;
        switch (result) {
            case 0:
                temp = single.FindSample(SampleNo);
                single.SetNegative(temp, 1);
                break;
            case 1:
                temp = single.FindSample(SampleNo);
                single.SetPositive(temp);
                MarkClose(temp);
                MarkSubClose();
                break;
            case 2:
                temp = single.FindSample(SampleNo);
                single.SetSuspicious(temp, 1);
                break;
            default:
                cout << endl << "输入错误，请重新输入！" << endl << endl;
                break;
        }
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

void PCRTest::MarkClose(int pos) {
    // 寻找同一栋楼的 将其全部设置为密接
    string building = single.GetElem(pos).getBuildingNo();
    Person temp;
    // 在单管队列中寻找同一栋楼的
    for (int i = 0; i < single.GetRear(); i++) {
        temp = single.GetElem(i);
        if (temp.getBuildingNo() == building) {
            single.SetContact(i);
        }
    }
    // 在混管队列中寻找同一栋楼的
    for (int i = 0; i < mixed.GetRear(); i++) {
        temp = mixed.GetElem(i);
        if (temp.getBuildingNo() == building) {
            mixed.SetContact(i);
        }
    }
    // 队伍前面10人及后面的所有人设置为密接
    for (int i = pos - 10; i < single.GetRear(); i++) {
        if (i >= 0 && i != pos) {
            temp = single.GetElem(i);
            single.SetContact(i);
            building = single.GetElem(i).getBuildingNo();
            sub_close.Insert(building);
        }
    }
}

void PCRTest::MarkSubClose() {
    string building;
    while (!sub_close.IsEmpty()) {
        sub_close.Pop(building);
        // 单管队伍中找次密接
        for (int i = 0; i < single.GetRear(); i++) {
            if (single.GetElem(i).getBuildingNo() == building) {
                single.SetSubContact(i);
            }
        }
        // 混管队伍中找次密接
        for (int i = 0; i < mixed.GetRear(); i++) {
            if (mixed.GetElem(i).getBuildingNo() == building) {
                mixed.SetSubContact(i);
            }
        }
    }
}

void PCRTest::CategoryQuery() {
    cout << "==========分类查询==========" << endl;
    cout << "阴性：";
    StateQuery(0);
    cout << endl << "阳性：";
    StateQuery(1);
    cout << endl << "可疑：";
    StateQuery(2);
    cout << endl << "密接：";
    ContactQuery(0);
    cout << endl << "次密接：";
    ContactQuery(1);
    cout << endl << "待上传：";
    StateQuery(3);
    cout << endl << "在排队：";
    StateQuery(4);
    cout << endl;
}

void PCRTest::StateQuery(int select) {
    State state;
    switch (select) {
        case 0:
            state = NEGATIVE;
            break;
        case 1:
            state = POSITIVE;
            break;
        case 2:
            state = SUSPICIOUS;
            break;
        case 3:
            state = PENDING;
            break;
        case 4:
            state = IN_QUEUE;
            break;
    }
    for (int i = 0; i < single.GetRear(); i++) {
        if (single.GetElem(i).getState() == state) {
            single.GetElem(i).ShowPerson();
        }
    }
    for (int i = 0; i < mixed.GetRear(); i++) {
        if (mixed.GetElem(i).getState() == state) {
            mixed.GetElem(i).ShowPerson();
        }
    }
}

void PCRTest::ContactQuery(int select) {
    Contact contact;
    switch (select) {
        case 0:
            contact = CONTACT;
            break;
        case 1:
            contact = SUB_CONTACT;
            break;
    }
    for (int i = 0; i < single.GetRear(); i++) {
        if (single.GetElem(i).getContact() == contact) {
            single.GetElem(i).ShowPerson();
        }
    }
    for (int i = 0; i < mixed.GetRear(); i++) {
        if (mixed.GetElem(i).getContact() == contact) {
            mixed.GetElem(i).ShowPerson();
        }
    }
}

void PCRTest::PersonQuery() {
    cout << "==========个人查询==========" << endl;
    string id;
    cout << "请输入个人编号：";
    cin >> id;
    State state = NEGATIVE;
    Contact contact = NORMAL;
    string sample, status, contact_status;
    Person temp;
    int index = mixed.FindPerson(id);
    if (index != -1) {
        temp = mixed.GetElem(index);
        state = temp.getState();
        sample = temp.getSampleID();
        contact = temp.getContact();
    } else {
        index = single.FindPerson(id);
        if (index != -1) {
            temp = single.GetElem(index);
            state = temp.getState();
            sample = temp.getSampleID();
            contact = temp.getContact();
        } else {
            sample = "Unknown";
            state = NOT_IN_QUEUE;
        }
    }
    if (state == NEGATIVE) {
        status = "阴性";
    } else if (state == POSITIVE) {
        status = "阳性";
    } else if (state == SUSPICIOUS) {
        status = "可疑";
    } else if (state == PENDING) {
        status = "待上传";
    } else if (state == IN_QUEUE) {
        status = "在排队";
    } else {
        status = "未检测";
    }
    if (contact == CONTACT) {
        contact_status = "密接";
    } else if (contact == SUB_CONTACT) {
        contact_status = "次密接";
    } else if (contact == NORMAL) {
        contact_status = "正常";
    } else {
        contact_status = "N/A";
    }
    cout << "个人编号：" << id << endl << "样本编号：" << sample << endl << "核酸检测结果：" << status
         << endl << "密接结果：" << contact_status << endl << endl;
}
