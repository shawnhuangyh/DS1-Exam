#include "Assistance.h"
#include "PCRTest.h"

int main() {
    PCRTest PCR;
    PCR.ImportQueueData();
    PCR.ImportCheckedData();
    bool flag = true;
    string test;
    while (flag) {
        char choice;
        ShowMenu();
        cin >> choice;
        switch (choice) {
            case '1':
                PCR.EnQueue();
                break;
            case '2':
                PCR.DeQueue();
                break;
            case '3':
                PCR.ShowQueue();
                break;
            case '4':
                PCR.PerformTest();
                break;
            case '5':
                PCR.CategoryQuery();
                break;
            case '6':
                PCR.PersonQuery();
                break;
            case '0':
                flag = false;
                break;
            default:
                cout << "Wrong choice!" << endl;
                break;
        }
    }


    return 0;
}
