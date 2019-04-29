#include "Manager.h"

DatabaseManager::DatabaseManager(){
    schoolDatabase = new schoolDatabase();
}

DatabaseManager::~DatabaseManager(){
    delete schoolDatabase;
}

bool DatabaseManager::PickOption(int option){
    switch(option){
        case 1: //Print students

            break;
        case 2: //Print faculty

            break;
        
        case 3: //Print specific student

            break;
        case 4: //Print specific faculty member

            break;
        case 5: //Print student's advisor

            break;
        case 6: //Print faculty member's advisees

            break;
        case 7: //Add a new student

            break;
        case 8: //Delete a student

            break;
        case 9: //Add a new faculty member

            break;
        case 10: //Delete a faculty member

            break;
        case 11: //Change advisor

            break;
        case 12: //Remove Advisee

            break;

    }
}

int DatabaseManager::GetStudentID(){
    while(true){
        cout << "Please enter an existing student id number\n\t";
        int studentID;
        cin >> studentID;
    }
}