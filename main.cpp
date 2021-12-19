//Ethan Wharton
//Quinn Caton
//Tony Lacio Sandoval
//Sarah Ogent
//Salma Omar

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "functions.h"
#include "Patient.h"

using namespace std;

int main() {
    //declaring Patient object and vector of Patient objects
    Patient hospitalPatient;
    vector<vector<Patient>>allPatients;
    vector<Patient>heartClinic;
    vector<Patient>plasticSurgeryClinic;
    vector<Patient>lungClinic;
    vector<vector<string>> transactionLog(4);

    ReadData(allPatients, heartClinic, plasticSurgeryClinic, lungClinic, transactionLog);

    // Main Menu
    while (true){
        // Print out Main Menu
        cout << "\n Welcome to Research Hospital" << endl;
        cout << "1: Heart Clinic" << endl;
        cout << "2: Lung Clinic" << endl;
        cout << "3: Plastic Surgery Clinic" << endl;
        cout << "4: Quit" << endl;

        try {
            string choice;
            cout << "Please enter the clinic of interest: ";
            cin >> choice;
            cout << endl;

            if (stoi(choice) == 1) {
                subMenu("Heart Clinic", allPatients, transactionLog);
            } else if (stoi(choice) == 2) {
                subMenu("Lung Clinic", allPatients, transactionLog);
            } else if (stoi(choice) == 3) {
                subMenu("Plastic Surgery Clinic", allPatients, transactionLog);
            } else if (stoi(choice) == 4) {
                cout << "Transaction and Error logs have been printed for your convenience." << endl << endl;
                cout<<"Goodbye!"<<endl;
                printAllTransactionsAndErrors(transactionLog, allPatients);
                break;
            }else{
                cout<<choice<<" is an invalid option, please try again"<<endl;
            }

        }catch(invalid_argument& inputError1){
            cin.clear();
            cout<<"Invalid input, please try again"<<endl;
            continue;
        }
        catch (runtime_error &except){
            cout << except.what();
            transactionLog.at(3).push_back(except.what());
        }
    }


    return 0;
}