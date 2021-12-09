//
// Created by Sarah Ogent on 12/2/21.
//
#include <iostream>
#include "Patient.h"

using namespace std;

#ifndef PROGRAM5_FUNCTIONS_H
#define PROGRAM5_FUNCTIONS_H

#pragma once
void ReadData(vector<vector<Patient>>& allPatients, vector<Patient>& heartClinic, vector<Patient>& plasticSurgeryClinic, vector<Patient>& lungClinic);
void subMenu (string department, vector<vector<Patient>>& allPatients);
void addPatient(vector<vector<Patient>>& allPatients, string HospDepartment);
void addCriticalPatient(vector<vector<Patient>>& allPatients, string HospDepartment);

#endif //PROGRAM5_FUNCTIONS_H
