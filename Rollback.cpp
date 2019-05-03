//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Name:  Scott Cummings
//Student ID#:  2317991
//Chapman Email:  scummings@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  5 - School Database

#include "Rollback.h"

Rollback::Rollback(){
    rollbackAction = 0;

    this->deletedStudent = nullptr;
    this->deletedFaculty = nullptr;

}

/*
a) Overloaded constructor for the Rollback class
b) @param: Faculty* - a pointer to a faculty object that represents the deleted faculty object
c) @return: NA
d) no exceptions thrown
*/
Rollback::Rollback(Faculty *deletedFaculty){
    rollbackAction = 1;
    this->deletedFaculty = deletedFaculty;
    this->deletedStudent = nullptr;
}

/*
a) Overloaded constructor for the Rollback class
b) @param: Faculty* - a pointer to a student object that represents the deleted student object
c) @return: NA
d) no exceptions thrown
*/
Rollback::Rollback(Student *deletedStudent){
    rollbackAction = 2;
    this->deletedStudent = deletedStudent;
    this->deletedFaculty = nullptr;
}

/*
a) Overloaded constructor for the Rollback class
b) @param: int - an int value representing the ID of the inserted person | bool - a boolean value representing whether or not the inserted person was a faculty member
c) @return: NA
d) no exceptions thrown
*/
Rollback::Rollback(int insertedPersonID, bool isFaculty){
    if(isFaculty){
        rollbackAction = 3;
        facultyID = insertedPersonID;
    }
    else{
        rollbackAction = 4;
        studentID = insertedPersonID;
    }
    this->deletedStudent = nullptr;
    this->deletedFaculty = nullptr;

}

/*
a) Overloaded constructor for the Rollback class
b) @param: int facultyID - an integer value representing the ID of the facuty member who is being accessed | int studentID - an integer value representing the ID of the student who is being accessed | bool isChangeAdvisee - a boolean value that represents whether or not the ChangeAdvisor() Function has been called
c) @return: NA
d) no exceptions thrown
*/
Rollback::Rollback(int facultyID, int studentID, bool isChangeAdvisee){
    if(isChangeAdvisee){
        rollbackAction = 5;
    }
    else{
        rollbackAction = 6;
    }
    this->facultyID = facultyID;
    this->studentID = studentID;

    this->deletedStudent = nullptr;
    this->deletedFaculty = nullptr;

}


/*
a) Rollback destructor
b) @param: none
c) @return: NA
d) no exceptions thrown
*/
Rollback::~Rollback(){
    delete deletedFaculty;
    delete deletedStudent;
}

/*
a) the input logic for the rollback class
b) @param: Database* - a pointer to the database that we are working with
c) @return: void
d) no exceptions thrown
*/
void Rollback::PerformRollback(Database *database){
    switch (rollbackAction)
    {
        case 1:
            UndoFacultyDelete(database);
            break;
        case 2:
            UndoStudentDelete(database);
            break;
        case 3:
            UndoFacultyInsert(database);
            break;
        case 4:
            UndoStudentInsert(database);
            break;
        case 5:
            UndoChangeOfAdvisee(database);
            break;
        case 6:
            UndoChangeOfAdvisor(database);
            break;
    }
}

/*
a) Function for undoing a faculty delete
b) @param: Database* - a pointer to the database that we are working with
c) @return: void
d) no exceptions thrown
*/
void Rollback::UndoFacultyDelete(Database *database){
    cout << "Rolling back student deletion" << endl;
    int* tempAdvisees = deletedFaculty->GetAdvisees();
    int tempAdviseesCount = deletedFaculty->GetAdviseeCount();


    for(int i = 0; i < tempAdviseesCount; i++){
        deletedFaculty->RemoveAdvisee(tempAdvisees[i]);
    }

    database->AddFaculty((*deletedFaculty), true);

    for(int i = 0; i < tempAdviseesCount; i++){
        database->ChangeAdvisor(tempAdvisees[i], deletedFaculty->GetID(), true);
    }
}

/*
a) Function for undoing a student delete
b) @param: Database* - a pointer to the database that we are working with
c) @return: void
d) no exceptions thrown
*/
void Rollback::UndoStudentDelete(Database *database){
    cout << "Rolling back student deletion" << endl;
    database->AddStudent((*deletedStudent), true);
}

/*
a) Function for undoing a faculty insert
b) @param: Database* - a pointer to the database that we are working with
c) @return: void
d) no exceptions thrown
*/
void Rollback::UndoFacultyInsert(Database *database){
    cout << "Rolling back faculty insertion" << endl;
    database->DeleteFaculty(facultyID, true);
}

/*
a) Function for undoing a student insert
b) @param: Database* - a pointer to the database that we are working with
c) @return: void
d) no exceptions thrown
*/
void Rollback::UndoStudentInsert(Database *database){
    cout << "Rolling back student insertion" << endl;
    database->DeleteStudent(studentID, true);
}

/*
a) Function for undoing a change of advisee
b) @param: Database* - a pointer to the database that we are working with
c) @return: void
d) no exceptions thrown
*/
void Rollback::UndoChangeOfAdvisee(Database *database){
    cout << "Rolling back change of advisee" << endl;
    database->ChangeAdvisor(studentID, facultyID, true);
}

/*
a) Function for undoing a change of advisor
b) @param: Database* - a pointer to the database that we are working with
c) @return: void
d) no exceptions thrown
*/
void Rollback::UndoChangeOfAdvisor(Database *database){
    cout << "Rolling back change of advisor" << endl;
    database->ChangeAdvisor(studentID, facultyID, true);
}

/*
a) tostring function for testing and implementing rollback
b) @param: none
c) @return: string - a string value that is printed
d) no exceptions thrown
*/
string Rollback::ToString(){
    string returnString = "Rollback!!\n Action:  ";
    returnString += to_string(rollbackAction) + "\n";
    if(deletedFaculty != nullptr){
        returnString += deletedFaculty->ToString() + "\n";
    }
    else{
        returnString += "No Faculty! \n";
    }

    if(deletedStudent != nullptr){
        returnString += deletedStudent->ToString() + "\n";
    }
    else{
        returnString += "No Student! \n";
    }

    returnString += "Faculty ID " + to_string(facultyID)  + "\n";
    returnString += "Student ID " + to_string(studentID)  + "\n";

    return returnString;

}

/*
a) operator overloading fo the Rollback class
b) @param: ostream& os - the address of the output stream that we will be working with | Rollback& r - the address of the Rollback object that we will be working with
c) @return: ostream& - the address of the outputstream that we are working with
d) no exceptions thrown
*/
ostream& operator<<(ostream& os, Rollback& r){
    os << r.ToString();
    return os;
}
