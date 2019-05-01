#include "Rollback.h"
#include <iostream>

Rollback::Rollback(Faculty *deletedFaculty){
    rollbackAction = 1;
    this->deletedFaculty = deletedFaculty;
}
Rollback::Rollback(Student *deletedStudent){
    rollbackAction = 2;
    this->deletedStudent = deletedStudent;
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
    //database
}
void Rollback::UndoStudentDelete(Database *database){
    database->AddStudent((*deletedStudent));
}

void Rollback::UndoFacultyInsert(Database *database){
    database->DeleteFaculty(facultyID);
}
void Rollback::UndoStudentInsert(Database *database){
    database->DeleteStudent(studentID);
}

void Rollback::UndoChangeOfAdvisee(Database *database){

}
void Rollback::UndoChangeOfAdvisor(Database *database){

}
