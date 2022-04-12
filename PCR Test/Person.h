//
// Created by Shawn Huang on 2022/4/12.
//

#ifndef PCR_TEST_PERSON_H
#define PCR_TEST_PERSON_H

#include <iostream>

using namespace std;


class Person {
private:
    string PersonID;
    string SampleID;
public:
    Person();

    Person(string pid, string sid = "Pending");

    string getPersonID();

    string getSampleID();

    string GetBuildingNo();

    string GetRoomNo();

    string GetPersonNo();

    friend ostream &operator<<(ostream &out, const Person &p) {
        out << p.PersonID;
        return out;
    }

};


#endif //PCR_TEST_PERSON_H
