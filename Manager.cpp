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
            schoolDatabase->PrintStudents();
            break;
        case 2: //Print faculty
            schoolDatabase->PrintFaculty();
            break;

        case 3: //Print specific student
            int studentID = GetStudentID();
            schoolDatabase->PrintStudent(studentID);
            break;
        case 4: //Print specific faculty member
            int facultyID = GetFacultyID();
            schoolDatabase->PrintFaculty(facultyID);
            break;
        case 5: //Print student's advisor
            int studentID = GetStudentID();
            schoolDatabase->PrintAdvisor(studentID);
            break;
        case 6: //Print faculty member's advisees
            int facultyID = GetFacultyID();
            schoolDatabase->PrintAdvisees(facultyID);
            break;
        case 7: //Add a new student
            Student newStudent = GetNewStudent();
            schoolDatabase->AddStudent(newStudent);
            break;
        case 8: //Delete a student
            int studentID = GetStudentID();
            schoolDatabase->DeleteStudent(studentID);
            break;
        case 9: //Add a new faculty member
            Faculty newFaculty = GetNewFaculty();
            schoolDatabase->AddFaculty(newFaculty);
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

        //Test to see if student ID is valid and contained in the tree
        bool isContained = true;

        if(isContained){
            return studentID;
        }
    }
}

int DatabaseManager::GetFacultyID(){
    while(true){
        cout << "Please enter an existing faculty id number\n\t";
        int facultyID;
        cin >> facultyID;

        //Test to see if student ID is valid and contained in the tree
        bool isContained = true;

        if(isContained){
            return facultyID;
        }
    }
}

Student DatabaseManager::GetNewStudent(){
    int studentID;
    float studentGPA;
    string studentName;
    string studentMajor;
    short studentYear;
    int advisorID;

    bool keepGoing = true;

    //Getting student ID
    while(keepGoing){
        cout << "What is the new student's ID number?\n";
        cin >> studentID;

        if(studentID <= 0){
            cout << "Invalid ID number\n";
        }
        else{
            keepGoing = false;
        }
    }

    keepGoing = true;

    //Getting student Name
    while(keepGoing){
        cout << "What is the new student's name?\n";
        cin >> studentName;

        //add input protection if you get around to it!

        keepGoing = false;
    }

    keepGoing = true;

    //Getting student's specialization
    while(keepGoing){
        cout << "What is the new student's specialization/major?\n";
        cin >> studentMajor;

        //add input protection if you get around to it!

        keepGoing = false;
    }

    keepGoing = true;

    //Getting student's GPA
    while(keepGoing){
        cout << "What is the new student's GPA?\n";
        cin >> studentGPA;

        if(0 <= studentGPA && studentGPA <= 5.0){
            keepGoing = false;
        }
        else{
            cout << "Invalid GPA, please enter a decimal between 0.0 and 5.0\n";
        }
    }

    keepGoing = true;

    //Get student's year
    while(keepGoing){
        cout << "What is the student's year?\n";
        cin >> studentYear;

        if(1 <= studentYear && studentYear <= 4){
            studentYear--;
            keepGoing = false;
        }
        else{
            cout << "Invalid year, only years 1-4 are supported\n";
        }
    }

    advisorID = GetFacultyID();

    Student returnStudent(studentID, studentGPA, advisorID, studentName, studentYear, studentMajor);
    return returnStudent;
}

Faculty DatabaseManager::GetNewFaculty(){
    int facultyID;
    string name;
    short rank;
    string specialization;

}
