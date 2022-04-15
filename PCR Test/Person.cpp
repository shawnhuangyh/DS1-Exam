//
// Created by Shawn Huang on 2022/4/12.
//

#include "Person.h"

Person::Person() {
    PersonID = "Unknown";
    SampleID = "Pending";
}

Person::Person(string pid, string sid) {
    PersonID = pid;
    SampleID = sid;
}

string Person::getPersonID() {
    return PersonID;
}

string Person::getSampleID() {
    return SampleID;
}

string Person::getBuildingNo() {
    return PersonID.substr(0, 3);
}

string Person::getRoomNo() {
    return PersonID.substr(3, 4);
}

string Person::getPersonNo() {
    return PersonID.substr(7, 1);
}

void Person::setSampleID(string sid) {
    SampleID = sid;
}

