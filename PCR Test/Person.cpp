//
// Created by Shawn Huang on 2022/4/12.
//

#include "Person.h"

Person::Person() {
    PersonID = "Unknown";
    SampleID = "Unknown";
    state = IN_QUEUE;
    contact = NORMAL;
}

Person::Person(string pid, string sid) {
    PersonID = pid;
    SampleID = sid;
    state = IN_QUEUE;
    contact = NORMAL;
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

void Person::ShowPerson() {
    cout << PersonID << " ";
}

void Person::setSampleID(string sid) {
    SampleID = sid;
}

void Person::setState(State s) {
    state = s;
}

State Person::getState() {
    return state;
}


