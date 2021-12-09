#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "functions.h"
#include "Patient.h"

//include global static variable to keep track of number of each kind of patient
static int patientCount[3]= {0, 0, 0};
//patientCount[0] = number of Heart Clinic Patients
//patientCount[1] = number of Lung Clinic Patients
//patientCount[2] = number of Plastic Surgery Patients

using namespace std;


void ReadData(vector<vector<Patient>>& allPatients, vector<Patient>& heartClinic, vector<Patient>& plasticSurgeryClinic, vector<Patient>& lungClinic){
    ifstream fin;
    string testChar, tempStr, firstName, lastName, SocSecNum;
    fin.open("/Users/sogent/CLionProjects/Program5/patient.csv");
    string line;
    vector<string>row;
    Patient hospitalPatient;

    while(fin.good()){
        getline(fin, line);
        testChar=line.substr(0, 2);

        if(testChar=="Q"){
            break;
        }

        row.clear();
        stringstream inSS(line);
        while(getline(inSS, tempStr, ',')){
            row.push_back(tempStr);
        }

        if(testChar=="PC"){
            //patient clinic--where lung clinic patients go?
            firstName= row[1];
            lastName= row[2];
            SocSecNum= row[3];
            hospitalPatient.setType("Lung");
            hospitalPatient.setFName(firstName);
            hospitalPatient.setLName(lastName);
            hospitalPatient.setSSN(stoi(SocSecNum));
            hospitalPatient.setCritNo();

            lungClinic.push_back(hospitalPatient);
            patientCount[1]+=1;

        }else if(testChar=="HC") {
            //heart clinic
            firstName= row[1];
            lastName= row[2];
            SocSecNum= row[3];
            hospitalPatient.setType("Heart");
            hospitalPatient.setFName(firstName);
            hospitalPatient.setLName(lastName);
            hospitalPatient.setSSN(stoi(SocSecNum));
            hospitalPatient.setCritNo();

            heartClinic.push_back(hospitalPatient);
            patientCount[0]+=1;

        }else if(testChar=="PS") {
            //plastic surgery
            firstName= row[1];
            lastName= row[2];
            SocSecNum= row[3];
            hospitalPatient.setType("Plastic");
            hospitalPatient.setFName(firstName);
            hospitalPatient.setLName(lastName);
            hospitalPatient.setSSN(stoi(SocSecNum));
            hospitalPatient.setCritNo();

            plasticSurgeryClinic.push_back(hospitalPatient);
            patientCount[2]+=1;

        }else{
            //error log
        }
    }

    //Push onto vector of vectors here
    allPatients.push_back(lungClinic);
    allPatients.push_back(heartClinic);
    allPatients.push_back(plasticSurgeryClinic);
}


//subMenu
void subMenu (string department, vector<vector<Patient>>& allPatients){

    cout << "Welcome to the " << department << endl;
    cout <<"1: - Add Patient" << endl;
    cout <<"2: - Add Critical Patient" << endl;
    cout <<"3: - Take out Patient for Operation" << endl;
    cout <<"4: - Cancel Patient" << endl;
    cout <<"5: - List Patients in Queue" << endl;
    cout <<"6: - Change Department or exist" << endl;

    int option;
    cout << "Enter your choice: ";
    cin >> option;
    cout << endl;

    switch (option){
        case 1:
            //Add Patient
            if(department=="Heart Clinic"){
                addPatient(allPatients, department);
            }else if(department=="Lung Clinic"){
                addPatient(allPatients, department);
            }else if(department=="Plastic Surgery Clinic"){
                addPatient(allPatients, department);
            }
            break;
        case 2:
            //Add Critical Patient
            if(department=="Heart Clinic"){
                addCriticalPatient(allPatients, department);
            }else if(department=="Lung Clinic"){
                addCriticalPatient(allPatients, department);
            }else if(department=="Plastic Surgery Clinic"){
                addCriticalPatient(allPatients, department);
            }

            break;
        case 3:
            //Take out Patient for Operation
            break;
        case 4:
            //cancel Patient
            break;
        case 5:
            //List Patients in Queue
            if(department=="Heart Clinic"){
                for(int i=0;i<allPatients.size();++i){
                    for(int j=0;j<allPatients.at(i).size();++j){
                        if(allPatients[i][j].getType()=="Heart"){
                            cout<<allPatients[i][j].getFName()<<" ";
                            cout<<allPatients[i][j].getLName()<<endl;
                        }
                    }
                }
            }

            if(department=="Lung Clinic"){
                for(int i=0;i<allPatients.size();++i){
                    for(int j=0;j<allPatients.at(i).size();++j){
                        if(allPatients[i][j].getType()=="Lung"){
                            cout<<allPatients[i][j].getFName()<<" ";
                            cout<<allPatients[i][j].getLName()<<endl;
                        }
                    }
                }
            }

            if(department=="Plastic Surgery Clinic"){
                for(int i=0;i<allPatients.size();++i){
                    for(int j=0;j<allPatients.at(i).size();++j){
                        if(allPatients[i][j].getType()=="Plastic"){
                            cout<<allPatients[i][j].getFName()<<" ";
                            cout<<allPatients[i][j].getLName()<<endl;
                        }
                    }
                }


            }
            break;
        case 6:
            //Change Department or Exist
            break;
        default:
            cout << "Invalid entry, please try again." << endl;

    }
}

void addPatient(vector<vector<Patient>>& allPatients, string HospDepartment){

    Patient hospitalPatient;
    vector<Patient> tempHeartClinic;
    vector<Patient> tempLungClinic;
    vector<Patient> tempPlasticSurgeryClinic;
    string firstName, lastName, type, socSecNum;
    ///Checking each clinic amount
    ///Delete when finished
    cout<<"Heart"<<endl;
    cout<<patientCount[0]<<endl;
    cout<<"Lung"<<endl;
    cout<<patientCount[1]<<endl;
    cout<<"Plastic"<<endl;
    cout<<patientCount[2]<<endl;

    if(patientCount[0]>=10||patientCount[1]>=10||patientCount[2]>=10){
        cout<<"Sorry, clinic is at full capacity. Please try again later."<<endl;

    }else {
        cin.ignore();
        cout << "First Name: ";
        getline(cin, firstName);

        cout << "Last Name: ";
        getline(cin, lastName);

        cout << "SSN: ";
        getline(cin, socSecNum);

        if (socSecNum == "") {
            cout << "New patient entry cancelled." << endl;

        } else {
            if (HospDepartment == "Heart Clinic") {
                hospitalPatient.setType("Heart");
                hospitalPatient.setLName(lastName);
                hospitalPatient.setFName(firstName);
                hospitalPatient.setSSN(stoi(socSecNum));
                hospitalPatient.setCritNo();

                tempHeartClinic.push_back(hospitalPatient);
                allPatients.push_back(tempHeartClinic);
                patientCount[0] += 1;

            } else if (HospDepartment == "Lung Clinic") {
                hospitalPatient.setType("Lung");
                hospitalPatient.setLName(lastName);
                hospitalPatient.setFName(firstName);
                hospitalPatient.setSSN(stoi(socSecNum));
                hospitalPatient.setCritNo();


                tempLungClinic.push_back(hospitalPatient);
                allPatients.push_back(tempLungClinic);
                patientCount[1] += 1;

            } else if (HospDepartment == "Plastic Surgery Clinic") {
                hospitalPatient.setType("Plastic");
                hospitalPatient.setLName(lastName);
                hospitalPatient.setFName(firstName);
                hospitalPatient.setSSN(stoi(socSecNum));
                hospitalPatient.setCritNo();

                tempPlasticSurgeryClinic.push_back(hospitalPatient);
                allPatients.push_back(tempPlasticSurgeryClinic);
                patientCount[2] += 1;
            }
        }
    }

}

void addCriticalPatient(vector<vector<Patient>>& allPatients, string HospDepartment){

    Patient hospitalPatient;
    vector<Patient> tempHeartClinic;
    vector<Patient> tempLungClinic;
    vector<Patient> tempPlasticSurgeryClinic;
    string firstName, lastName, type, socSecNum;
    ///Checking each clinic amount
    ///Delete when finished
    cout<<"Heart"<<endl;
    cout<<patientCount[0]<<endl;
    cout<<"Lung"<<endl;
    cout<<patientCount[1]<<endl;
    cout<<"Plastic"<<endl;
    cout<<patientCount[2]<<endl;

    if(patientCount[0]>=10||patientCount[1]>=10||patientCount[2]>=10){
        cout<<"Sorry, clinic is at full capacity. Please try again later."<<endl;

    }else {
        cin.ignore();
        cout << "First Name: ";
        getline(cin, firstName);

        cout << "Last Name: ";
        getline(cin, lastName);

        cout << "SSN: ";
        getline(cin, socSecNum);

        if (socSecNum == "") {
            cout << "New patient entry cancelled." << endl;

        } else {
            if (HospDepartment == "Heart Clinic") {
                hospitalPatient.setType("Heart");
                hospitalPatient.setLName(lastName);
                hospitalPatient.setFName(firstName);
                hospitalPatient.setSSN(stoi(socSecNum));
                hospitalPatient.setCritYes();

                tempHeartClinic.push_back(hospitalPatient);
                allPatients.push_back(tempHeartClinic);
                patientCount[0] += 1;

            } else if (HospDepartment == "Lung Clinic") {
                hospitalPatient.setType("Lung");
                hospitalPatient.setLName(lastName);
                hospitalPatient.setFName(firstName);
                hospitalPatient.setSSN(stoi(socSecNum));
                hospitalPatient.setCritYes();


                tempLungClinic.push_back(hospitalPatient);
                allPatients.push_back(tempLungClinic);
                patientCount[1] += 1;

            } else if (HospDepartment == "Plastic Surgery Clinic") {
                hospitalPatient.setType("Plastic");
                hospitalPatient.setLName(lastName);
                hospitalPatient.setFName(firstName);
                hospitalPatient.setSSN(stoi(socSecNum));
                hospitalPatient.setCritYes();

                tempPlasticSurgeryClinic.push_back(hospitalPatient);
                allPatients.push_back(tempPlasticSurgeryClinic);

                for(int i=0;i<allPatients.size();++i){
                    for(int j=0;j<allPatients.at(i).size();++j){
                        if(allPatients[i][j].getType()=="Plastic"){
                            cout<<allPatients[i][j].getFName()<<" ";
                            cout<<allPatients[i][j].getLName()<<endl;
                        }
                    }
                }


                patientCount[2] += 1;
            }
        }
    }
}


