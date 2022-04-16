//
// Created by Shawn Huang on 2022/4/12.
//

#ifndef PCR_TEST_PERSON_H
#define PCR_TEST_PERSON_H

#include <iostream>
#include"Assistance.h"

using namespace std;


class Person {
private:
    string PersonID;
    string SampleID;
    State state;
    Contact contact;
public:
    Person();

    Person(string pid, string sid = "Unknown");

    string getPersonID();

    string getSampleID();

    string getBuildingNo();

    string getRoomNo();

    string getPersonNo();

    void ShowPerson();

    void setSampleID(string sid);

    void setState(State s);

    void setContact(Contact c);

    State getState();

    Contact getContact();
};


#endif //PCR_TEST_PERSON_H
