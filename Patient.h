//
// Created by Sarah Ogent on 12/2/21.
//

#ifndef PROGRAM5_PATIENT_H
#define PROGRAM5_PATIENT_H


#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class Patient {
public:
    Patient();
    Patient(string, string, string, int, bool);
    string getType()   { return type; }
    string getLName()  { return lName; }
    string getFName()  {return  fName; }
    int    getSSN()    { return SSN; }
    bool   isCrit()    { return crit; }

    void setType(string t)  { type  = t; }
    void setLName(string l) { lName = l; }
    void setFName(string f) { fName = f; }
    void setSSN(int s)      { SSN   = s; }
    void setCritYes()       { crit  = true; }
    void setCritNo()        {crit   = false; }

private:
    string type;
    string fName;
    string lName;
    int SSN;
    bool crit;
};

#endif //PROGRAM5_PATIENT_H
