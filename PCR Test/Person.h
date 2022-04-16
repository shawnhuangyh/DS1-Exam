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

    Person(string pid, string sid = "Pending");

    string getPersonID();

    string getSampleID();

    string getBuildingNo();

    string getRoomNo();

    string getPersonNo();

    void setSampleID(string sid);

    void setState(State s);

    friend ostream &operator<<(ostream &out, const Person &p) {
        out << p.PersonID;
        return out;
    }

};


#endif //PCR_TEST_PERSON_H
