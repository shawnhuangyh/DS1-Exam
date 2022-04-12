//
// Created by Shawn Huang on 2022/4/12.
//

#ifndef PCR_TEST_ASSISTANCE_H
#define PCR_TEST_ASSISTANCE_H

#include <fstream>
#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

string GetBuildingNo(const string &PersonNo);

string GetRoomNo(const string &PersonNo);

string GetPersonNo(const string &PersonNo);

void ImportQueueData(Queue<string> &mixed, Queue<string> &single);

void ImportCheckedData(Queue<string> &mixed, Queue<string> &single);

void ShowMenu();



#endif //PCR_TEST_ASSISTANCE_H
