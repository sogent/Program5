//
// Created by Sarah Ogent on 12/2/21.
//
#include <iostream>
#include "Patient.h"

using namespace std;

#ifndef PROGRAM5_FUNCTIONS_H
#define PROGRAM5_FUNCTIONS_H

#pragma once
void ReadData(vector<vector<Patient>>& allPatients, vector<Patient>& heartClinic, vector<Patient>& plasticSurgeryClinic, vector<Patient>& lungClinic, vector<vector<string>>& log);
void subMenu(string department, vector<vector<Patient>>& allPatients, vector<vector<string>>& transactionLog);
void addPatient(vector<vector<Patient>>& allPatients, vector<vector<string>>& log, string HospDepartment);
void addCriticalPatient(vector<vector<Patient>>& allPatients, vector<vector<string>>& log, string HospDepartment);
void sortPatient(vector<Patient>& patientQueue);
void takeOutPatient(vector<vector<Patient>>& v, vector<vector<string>>& t, string s);
void cancelPatient(vector<vector<Patient>>& v, vector<vector<string>>& t, string s);
void printAllTransactionsAndErrors(vector<vector<string>> t, vector<vector<Patient>>&);
#endif //PROGRAM5_FUNCTIONS_H
