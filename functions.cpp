#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "functions.h"
#include "Patient.h"
#include <iomanip>

//include global static variable to keep track of number of each kind of patient
static int patientCount[3]= {0, 0, 0};
//patientCount[0] = number of Heart Clinic Patients
//patientCount[1] = number of Lung Clinic Patients
//patientCount[2] = number of Plastic Surgery Patients

using namespace std;



void ReadData(vector<vector<Patient>>& allPatients, vector<Patient>& heartClinic, vector<Patient>& plasticSurgeryClinic, vector<Patient>& lungClinic, vector<vector<string>>& log) {
    ifstream fin;
    string testChar, tempStr, firstName, lastName, SocSecNum;
    fin.open("/Users/sogent/CLionProjects/Program5/patient.csv");
    string line;
    vector<string>row;
    Patient hospitalPatient;

    while (fin.good()) {
        getline(fin, line);
        testChar = line.substr(0, 2);

        if (testChar == "Q") {
            break;
        }

        row.clear();
        stringstream inSS(line);
        while (getline(inSS, tempStr, ',')) {
            row.push_back(tempStr);
        }

        if (testChar == "PC") {
            //patient clinic--where lung clinic patients go? PC==Pulminary Clinic
            firstName = row[1];
            lastName = row[2];
            SocSecNum = row[3];
            hospitalPatient.setType("Lung");
            hospitalPatient.setFName(firstName);
            hospitalPatient.setLName(lastName);
            hospitalPatient.setSSN(stoi(SocSecNum));
            hospitalPatient.setCritNo();
            log.at(0).push_back("Patient added: " + firstName + " " + lastName + " " + SocSecNum); //added

            lungClinic.push_back(hospitalPatient);
            patientCount[1] += 1;

        }
        else if (testChar == "HC") {
            //heart clinic
            firstName = row[1];
            lastName = row[2];
            SocSecNum = row[3];
            hospitalPatient.setType("Heart");
            hospitalPatient.setFName(firstName);
            hospitalPatient.setLName(lastName);
            hospitalPatient.setSSN(stoi(SocSecNum));
            hospitalPatient.setCritNo();
            log.at(1).push_back("Patient added: " + firstName + " " + lastName + " " + SocSecNum);//added

            heartClinic.push_back(hospitalPatient);
            patientCount[0] += 1;

        }
        else if (testChar == "PS") {
            //plastic surgery
            firstName = row[1];
            lastName = row[2];
            SocSecNum = row[3];
            hospitalPatient.setType("Plastic");
            hospitalPatient.setFName(firstName);
            hospitalPatient.setLName(lastName);
            hospitalPatient.setSSN(stoi(SocSecNum));
            hospitalPatient.setCritNo();
            log.at(2).push_back("Patient added: " + firstName + " " + lastName + " " + SocSecNum);//added

            plasticSurgeryClinic.push_back(hospitalPatient);
            patientCount[2] += 1;

        }
        else {
            log.at(3).push_back("Error! unknown status!");
        }
    }

    //Push onto vector of vectors here
    allPatients.push_back(lungClinic);
    allPatients.push_back(heartClinic);
    allPatients.push_back(plasticSurgeryClinic);
}


//subMenu
void subMenu (string department, vector<vector<Patient>>& allPatients, vector<vector<string>>& transactionLog){

    cout << "Welcome to the " << department << endl;
    cout <<"1: - Add Patient" << endl;
    cout <<"2: - Add Critical Patient" << endl;
    cout <<"3: - Take out Patient for Operation" << endl;
    cout <<"4: - Cancel Patient" << endl;
    cout <<"5: - List Patients in Queue" << endl;
    cout <<"6: - Change Department or exit" << endl;

    int option;
    cout << "Enter your choice: ";
    cin >> option;
    cout << endl;

    switch (option){
        case 1:
            //Add Patient
            if(department=="Heart Clinic"){
                addPatient(allPatients, transactionLog, department);
            }else if(department=="Lung Clinic"){
                addPatient(allPatients, transactionLog, department);
            }else if(department=="Plastic Surgery Clinic"){
                addPatient(allPatients, transactionLog, department);
            }
            break;
        case 2:
            //Add Critical Patient
            if(department=="Heart Clinic"){
                addCriticalPatient(allPatients, transactionLog, department);
            }else if(department=="Lung Clinic"){
                addCriticalPatient(allPatients, transactionLog, department);
            }else if(department=="Plastic Surgery Clinic"){
                addCriticalPatient(allPatients, transactionLog, department);
            }

            break;
        case 3:
            //Ethan - 12/10/21 2:14p
            takeOutPatient(allPatients, transactionLog, department);
            break;
        case 4:
            //Ethan - 12/10/21 2:14p
            cancelPatient(allPatients, transactionLog, department);
            break;
        case 5:
            //List Patients in Queue
            if(department=="Heart Clinic"){
                cout<<"Patients in the Heart Clinic:"<<endl;
                cout<<"First Name"<<setw(12)<<"Last Name"<<setw(5)<<"SSN"<<setw(8)<<"Status"<<endl;
                for(int i=0;i<allPatients.size();++i){
                    for(int j=0;j<allPatients.at(i).size();++j){
                        if(allPatients[i][j].getType()=="Heart"){
                            cout<<left<<setw(13)<<allPatients[i][j].getFName();
                            cout<<setw(11)<<allPatients[i][j].getLName();
                            if(allPatients[i][j].getSSN()<10){
                                cout<<"00"<<setw(3)<<allPatients[i][j].getSSN();
                            }else if(allPatients[i][j].getSSN()>=10&&allPatients[i][j].getSSN()<100){
                                cout<<"0"<<setw(4)<<allPatients[i][j].getSSN();
                            }else if(allPatients[i][j].getSSN()>=100){
                                cout<<setw(4)<<allPatients[i][j].getSSN()<<" ";
                            }

                            if(allPatients[i][j].isCrit()){
                                cout<<"CRITICAL";
                            }else{
                                cout<<"reg";
                            }
                            cout<<endl;
                        }
                    }
                }
            }

            if(department=="Lung Clinic"){
                cout<<"Patients in the Lung Clinic:"<<endl;
                cout<<"First Name"<<setw(12)<<"Last Name"<<setw(5)<<"SSN"<<setw(8)<<"Status"<<endl;
                for(int i=0;i<allPatients.size();++i){
                    for(int j=0;j<allPatients.at(i).size();++j){
                        if(allPatients[i][j].getType()=="Lung"){
                            cout<<left<<setw(13)<<allPatients[i][j].getFName();
                            cout<<setw(11)<<allPatients[i][j].getLName();
                            if(allPatients[i][j].getSSN()<10){
                                cout<<"00"<<setw(3)<<allPatients[i][j].getSSN();
                            }else if(allPatients[i][j].getSSN()>=10&&allPatients[i][j].getSSN()<100){
                                cout<<"0"<<setw(4)<<allPatients[i][j].getSSN();
                            }else if(allPatients[i][j].getSSN()>=100){
                                cout<<setw(4)<<allPatients[i][j].getSSN()<<" ";
                            }

                            if(allPatients[i][j].isCrit()){
                                cout<<"CRITICAL";
                            }else{
                                cout<<"reg";
                            }
                            cout<<endl;
                        }
                    }
                }
            }

            if(department=="Plastic Surgery Clinic"){
                cout<<"Patients in the Plastic Surgery Clinic:"<<endl;
                cout<<"First Name"<<setw(12)<<"Last Name"<<setw(5)<<"SSN"<<setw(8)<<"Status"<<endl;
                for(int i=0;i<allPatients.size();++i){
                    for(int j=0;j<allPatients.at(i).size();++j){
                        if(allPatients[i][j].getType()=="Plastic"){
                            cout<<left<<setw(13)<<allPatients[i][j].getFName();
                            cout<<setw(11)<<allPatients[i][j].getLName();
                            if(allPatients[i][j].getSSN()<10){
                                cout<<"00"<<setw(3)<<allPatients[i][j].getSSN();
                            }else if(allPatients[i][j].getSSN()>=10&&allPatients[i][j].getSSN()<100){
                                cout<<"0"<<setw(4)<<allPatients[i][j].getSSN();
                            }else if(allPatients[i][j].getSSN()>=100){
                                cout<<setw(4)<<allPatients[i][j].getSSN()<<" ";
                            }

                            if(allPatients[i][j].isCrit()){
                                cout<<"CRITICAL";
                            }else{
                                cout<<"reg";
                            }
                            cout<<endl;
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

//pre: takes a vector<vector>> of Patient objects, a string for department name, and vector<vector>> of strings for transactions/errors.
//post: adds a new Patient object to correct vector based on dept name and user input, and prints any transactions/errors to screen and translog
void addPatient(vector<vector<Patient>>& allPatients, vector<vector<string>>& log, string HospDepartment){

    Patient hospitalPatient;
    vector<Patient> tempHeartClinic;
    vector<Patient> tempLungClinic;
    vector<Patient> tempPlasticSurgeryClinic;
    string firstName, lastName, type, socSecNum;
    string transaction;
    cin.exceptions(istream::failbit | istream::badbit);
    int checkVal;

    //following 3 if statements set value to check for full capacity clinic
    if(HospDepartment == "Heart Clinic"){
        checkVal = patientCount[0];
    }
    if(HospDepartment == "Lung Clinic"){
        checkVal = patientCount[1];
    }
    if(HospDepartment == "Plastic Surgery Clinic"){
        checkVal = patientCount[2];
    }

    try{
        if(checkVal >= 10){ //if clinic is full, this is last statement in function
            cout<<"Sorry, clinic is at full capacity. Please try again later."<<endl;
        }
        else {
            cin.ignore();
            cout << "First Name: ";
            getline(cin, firstName);

            cout << "Last Name: ";
            getline(cin, lastName);

            cout << "SSN: ";
            getline(cin, socSecNum);
            transaction = "Patient added manually: " + firstName + " " + lastName + " added to " +
                          HospDepartment + " queue.";

            if (socSecNum == "") {
                cout << "New patient entry cancelled." << endl;

            } else {
                //adds patient to correct vector, increment count for clinic
                //output statement and add to transaction log
                if (HospDepartment == "Heart Clinic") {
                    hospitalPatient.setType("Heart");
                    hospitalPatient.setLName(lastName);
                    hospitalPatient.setFName(firstName);
                    hospitalPatient.setSSN(stoi(socSecNum));
                    hospitalPatient.setCritNo();
                    allPatients.at(1).push_back(hospitalPatient);
                    patientCount[0] += 1;
                    cout << transaction << endl;
                    log[0].push_back(transaction);

                } else if (HospDepartment == "Lung Clinic") {
                    hospitalPatient.setType("Lung");
                    hospitalPatient.setLName(lastName);
                    hospitalPatient.setFName(firstName);
                    hospitalPatient.setSSN(stoi(socSecNum));
                    hospitalPatient.setCritNo();
                    allPatients.at(0).push_back(hospitalPatient);
                    patientCount[1] += 1;
                    cout << transaction << endl;
                    log[1].push_back(transaction);

                } else if (HospDepartment == "Plastic Surgery Clinic") {
                    hospitalPatient.setType("Plastic");
                    hospitalPatient.setLName(lastName);
                    hospitalPatient.setFName(firstName);
                    hospitalPatient.setSSN(stoi(socSecNum));
                    hospitalPatient.setCritNo();
                    allPatients.at(2).push_back(hospitalPatient);
                    patientCount[2] += 1;
                    cout << transaction << endl;
                    log[2].push_back(transaction);
                }
            }
        }
    }
    catch (...) {
        //catch all for errors, adds to trans log
        transaction = "Error occured trying to add patient " + firstName + " " + lastName;
        cout << transaction << endl;
        log[3].push_back(transaction);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

//pre: takes a vector<vector>> of Patient objects, a string for department name, and vector<vector>> of strings for transactions/errors.
//post: adds a new critical Patient object to correct vector based on dept name and user input, and prints any transactions/errors to screen and translog
//NOTE: In future, the addPatient() function could be overloaded with crit stat, as most of this code is identical
void addCriticalPatient(vector<vector<Patient>>& allPatients, vector<vector<string>>& log, string HospDepartment){
    int checkVal;
    Patient hospitalPatient;
    vector<Patient> tempHeartClinic;
    vector<Patient> tempLungClinic;
    vector<Patient> tempPlasticSurgeryClinic;
    string firstName, lastName, type, socSecNum;
    string transaction;
    cin.exceptions(istream::failbit | istream::badbit);

    //following 3 if statements set value to check for full capacity clinic
    if(HospDepartment == "Heart Clinic"){
        checkVal = patientCount[0];
    }
    if(HospDepartment == "Lung Clinic"){
        checkVal = patientCount[1];
    }
    if(HospDepartment == "Plastic Surgery Clinic"){
        checkVal = patientCount[2];
    }
    try{
        if(checkVal >= 10){ //if clinic is full, this is last statement in function
            cout<<"Sorry, clinic is at full capacity. Please try again later."<<endl;
        }else {
            cin.ignore();
            cout << "First Name: ";
            getline(cin, firstName);

            cout << "Last Name: ";
            getline(cin, lastName);

            cout << "SSN: ";
            getline(cin, socSecNum);
            transaction = "Critical patient added to front of queue: " + firstName + " " + lastName + " added to " +
                          HospDepartment + " queue.";
            if (socSecNum == "") {
                cout << "New patient entry cancelled." << endl;

            } else {
                //adds patient to correct vector, increment count for clinic
                //output statement and add to transaction log
                if (HospDepartment == "Heart Clinic") {
                    hospitalPatient.setType("Heart");
                    hospitalPatient.setLName(lastName);
                    hospitalPatient.setFName(firstName);
                    hospitalPatient.setSSN(stoi(socSecNum));
                    hospitalPatient.setCritYes();
                    allPatients.at(1).push_back(hospitalPatient);
                    sortPatient(allPatients.at(1));
                    patientCount[0] += 1;
                    cout << transaction << endl;
                    log[0].push_back(transaction);

                } else if (HospDepartment == "Lung Clinic") {
                    hospitalPatient.setType("Lung");
                    hospitalPatient.setLName(lastName);
                    hospitalPatient.setFName(firstName);
                    hospitalPatient.setSSN(stoi(socSecNum));
                    hospitalPatient.setCritYes();
                    allPatients.at(0).push_back(hospitalPatient);
                    sortPatient(allPatients.at(0));
                    patientCount[1] += 1;
                    cout << transaction << endl;
                    log[1].push_back(transaction);

                } else if (HospDepartment == "Plastic Surgery Clinic") {
                    hospitalPatient.setType("Plastic");
                    hospitalPatient.setLName(lastName);
                    hospitalPatient.setFName(firstName);
                    hospitalPatient.setSSN(stoi(socSecNum));
                    hospitalPatient.setCritYes();
                    allPatients.at(2).push_back(hospitalPatient);
                    sortPatient(allPatients.at(2));
                    patientCount[2] += 1;
                    cout << transaction << endl;
                    log[2].push_back(transaction);
                }
            }
        }
    }
    catch (...) {
        transaction = "Error occured trying to add patient " + firstName + " " + lastName;
        cout << transaction << endl;
        log[3].push_back(transaction);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

//Ethan - 12/10/21 2:14p
//Pre : Takes in vectors containing Patient objects, vectors conatining error and transaction messages, and a string indicating which clinic we need to modify.
//Post: Prints message to terminal, and adds messages to propper vecter within log vector. Decriments counter for aforementioned clinic.
void takeOutPatient(vector<vector<Patient>>& v, vector<vector<string>>& t, string s) {
    int index;
    if (s == "Lung Clinic") {
        index = 0;
    }
    else if (s == "Heart Clinic") {
        index = 1;
    }
    else if (s == "Plastic Surgery Clinic") {
        index = 2;
    }
    else
        throw runtime_error("Clinic Type not found!"); // I don't know when this would be possible as the clinic types are hard coded into the functions, but hey who knows.
    //There are only 3 clinics, clinic type error catch is erroneous/not possible due to
    //structure of project -Sarah

    if (v.at(index).empty()){
        cout << "Error: No patients found in queue" << endl;
        throw runtime_error("Error: No patients found in queue!");
    }
    cout << "Patient: " << v.at(index).at(0).getFName() << " " << v.at(index).at(0).getLName() << " has been taken out for operation." << endl;
    t.at(index).push_back("Patient: " + v.at(index).at(0).getFName() + " " + v.at(index).at(0).getLName() + " has been taken out for operation.");
    v.at(index).erase(v.at(index).begin());
    patientCount[index]--;
}

//Ethan - 12/10/21 2:14p
//Pre : Takes in vectors containing Patient objects, vectors conatining error and transaction messages, and a string indicating which clinic we need to modify.
//Post: Prints message to terminal, and adds messages to propper vecter within log vector. Decriments counter for aforementioned clinic.
void cancelPatient(vector<vector<Patient>>& v, vector<vector<string>>& t, string s) {
    int index;
    int index2 = -1;
    if (s == "Lung Clinic") {
        index = 0;
    }
    else if (s == "Heart Clinic") {
        index = 1;
    }
    else if (s == "Plastic Surgery Clinic") {
        index = 2;
    }
    else
        throw runtime_error("Clinic Type not found!"); // I don't know when this would be possible as the clinic types are hard coded into the functions, but hey who knows.

    if (v.at(index).empty()){
        cout << "Error: No patients found in queue" << endl;
        throw runtime_error("Error: No patients found in queue!");
    }

    string ssn;

    cout << "Please enter the social security number associated with the appointment you wish to cancel." << endl;
    cout << "SSN: ";
    cin.ignore();
    getline(cin, ssn);
    cout << endl;

    while (index2 == -1) {
        for (int i = 0; i < v.at(index).size(); i++) {
            if (v.at(index).at(i).getSSN() == stoi(ssn)) {
                index2 = i;
            }
        }

        if (index2 == -1) {
            cout << endl << "Oops, we could not find a patient associated with that social security number, please check your input and try again." << endl << endl;
            cout << "Please enter the social security number associated with the appointment you wish to cancel." << endl;
            cout << "SSN: ";
            cin.ignore();
            getline(cin, ssn);
            cout << endl;
        }
    }
    cout << "Appointment for: " << v.at(index).at(index2).getFName() << " " << v.at(index).at(index2).getLName() << " has been canceled." << endl;
    t.at(index).push_back("Appointment for: " + v.at(index).at(index2).getFName() + " " + v.at(index).at(index2).getLName() + " has been canceled.");
    v.at(index).erase(v.at(index).begin() + index2);
    patientCount[index]--;
}

void sortPatient(vector<Patient>& patientQueue){
    vector<Patient> newPatientQueue(0);
    //Copies crit patients to front of new queue
    for(int i = 0; i < patientQueue.size(); ++i){
        if(patientQueue.at(i).isCrit()){
            newPatientQueue.push_back(patientQueue.at(i));
        }
    }
    //Copies general patients to back of new queue
    for(int j = 0; j < patientQueue.size(); ++j){
        if(!patientQueue.at(j).isCrit()){
            newPatientQueue.push_back(patientQueue.at(j));
        }
    }
    //Copies patients back to queue passed into function
    for(int n = 0; n < patientQueue.size(); ++n){
        patientQueue.at(n) = newPatientQueue.at(n);
    }
}

//Pre : Takes in vectors containing patients and error/transaction messages
//Post: Prints data to output files
void printAllTransactionsAndErrors(vector<vector<string>> v, vector<vector<Patient>>& p) {
    ofstream t; //Transaction log
    ofstream e; //Error log

    t.open("TransactionLog.txt");
    e.open("errorLog.txt");
    if (!t.is_open() || !e.is_open())
        throw runtime_error("Error opening output files!");

    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            t << "Lung Clinic: " << endl  << "-----------------------------" << endl;
        }
        else if (i == 1) {
            t << endl << "Heart Clinic: " << endl << "-----------------------------" << endl;
        }
        else {
            t << endl << "Plastic Surgery Clinic" << endl << "-----------------------------" << endl;
        }
        for (int j = 0; j < v.at(i).size(); j++) {
            t << v.at(i).at(j) << endl;
        }
    }
    t << endl;
    t << "--------------------------------------" << endl;
    t << "     PATIENTS REMAINING IN QUEUE: "  << endl;//"NEEDED FOR A RESCHEDULE" could be added?
    t << "(Please reschedule these clients ASAP)" << endl; // Good call.
    t << "--------------------------------------" << endl;

    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            t << "Lung Clinic: " << endl  << "-----------------------------" << endl;
        }
        else if (i == 1) {
            t << endl << "Heart Clinic: " << endl << "-----------------------------" << endl;
        }
        else {
            t << endl << "Plastic Surgery Clinic" << endl << "-----------------------------" << endl;
        }
        for (int j = 0; j < p.at(i).size(); j++) {
            t << p.at(i).at(j).getFName() << " " << p.at(i).at(j).getLName() <<  endl;
        }
    }

    for (string s : v.at(3)) {
        e << s << endl;
    }
}