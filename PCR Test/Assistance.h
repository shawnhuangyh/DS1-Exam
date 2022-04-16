//
// Created by Shawn Huang on 2022/4/12.
//

#ifndef PCR_TEST_ASSISTANCE_H
#define PCR_TEST_ASSISTANCE_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

enum Contact{CONTACT, SUB_CONTACT, NORMAL};

enum State{NEGATIVE, POSITIVE, SUSPICIOUS, PENDING, IN_QUEUE, NOT_IN_QUEUE};

void ShowMenu();




#endif //PCR_TEST_ASSISTANCE_H
