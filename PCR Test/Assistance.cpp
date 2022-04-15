//
// Created by Shawn Huang on 2022/4/12.
//

#include "Assistance.h"

void ShowMenu() {
    cout << "========核酸检测系统========" << endl;
    cout << "1. 排队" << endl;
    cout << "2. 采样" << endl;
    cout << "3. 查看排队" << endl;
    cout << "4. 登记测试管" << endl;
    cout << "5. 各类人员查询" << endl;
    cout << "6. 个人查询" << endl;
    cout << "0. 退出系统" << endl;
    cout << "请选择(0-6)：" << endl;
}

string GenerateSampleNo(int sampleNo, int category) {
    int num = 4;
    string new_string = to_string(category) + string(num - to_string(sampleNo).length(), '0') + to_string(sampleNo);
    return new_string;
}


