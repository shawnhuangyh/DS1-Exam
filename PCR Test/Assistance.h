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

enum State{Negative, Positive, Suspicious, Pending, InQueue, NotInQueue};

void ShowMenu();

string GenerateSampleNo(int sampleNo, int category);



#endif //PCR_TEST_ASSISTANCE_H
