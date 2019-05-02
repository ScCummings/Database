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
    this->deletedStudent = nullptr;

}

Rollback::Rollback(Faculty *deletedFaculty){
    rollbackAction = 1;
    this->deletedFaculty = deletedFaculty;
    this->deletedStudent = nullptr;
}
Rollback::Rollback(Student *deletedStudent){
    rollbackAction = 2;
    this->deletedStudent = deletedStudent;
    this->deletedFaculty = nullptr;
}
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

Rollback::~Rollback(){
    delete deletedFaculty;
    delete deletedStudent;
}

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
void Rollback::UndoStudentDelete(Database *database){
    cout << "Rolling back student deletion" << endl;
    database->AddStudent((*deletedStudent), true);
}

void Rollback::UndoFacultyInsert(Database *database){
    cout << "Rolling back faculty insertion" << endl;
    database->DeleteFaculty(facultyID, true);
}
void Rollback::UndoStudentInsert(Database *database){
    cout << "Rolling back student insertion" << endl;
    database->DeleteStudent(studentID, true);
}

void Rollback::UndoChangeOfAdvisee(Database *database){
    cout << "Rolling back change of advisee" << endl;
    database->ChangeAdvisor(studentID, facultyID, true);
}
void Rollback::UndoChangeOfAdvisor(Database *database){
    cout << "Rolling back change of advisor" << endl;
    database->ChangeAdvisor(studentID, facultyID, true);
}

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


ostream& operator<<(ostream& os, Rollback& r){
    os << r.ToString();
    return os;
}
