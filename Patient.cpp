#include "Patient.h"
#include <iostream>

using namespace std;

Patient::Patient(){
    type = "";
    lName = "";
    fName = "";
    SSN = 0;
    crit = false;
}

Patient::Patient(string t, string l, string f, int s, bool c = false){
    type = t;
    fName = f;
    lName = l;
    SSN = s;
    crit = c;
}
