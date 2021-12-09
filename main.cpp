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

    ReadData(allPatients, heartClinic, plasticSurgeryClinic, lungClinic);

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
                subMenu("Heart Clinic", allPatients);
            } else if (stoi(choice) == 2) {
                subMenu("Lung Clinic", allPatients);
            } else if (stoi(choice) == 3) {
                subMenu("Plastic Surgery Clinic", allPatients);
            } else if (stoi(choice) == 4) {
                cout<<"Goodbye!"<<endl;
                break;
            }else{
                cout<<choice<<" is an invalid option, please try again"<<endl;
            }

        }catch(invalid_argument& inputError1){
            cin.clear();
            cout<<"Invalid input, please try again"<<endl;
            continue;
        }

    }


    return 0;
}