/*#include "Rollback.h"
#include <iostream>

Rollback::Rollback(Faculty *deletedFaculty){
    rollbackAction = 1;
    this->deletedFaculty = deletedFaculty;
}
Rollback::Rollback(Student *deletedStudent){
    rollbackAction = 2;
    this->deletedkStudent = deletedStudent;
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
    rollbackFaculty = nullptr;
    rollbackStudent = nullptr;
}

void Rollback::PerformRollback(){
    switch (rollbackAction)
    {
        case 1:
            UndoFacultyDelete(Database *database);
            break;
        case 2:
            UndoStudentDelete(Database *database);
            break;
        case 3:
            UndoFacultyInsert(Database *database);
            break;
        case 4:
            UndoStudentInsert(Database *database);
            break;
        case 5:
            UndoChangeOfAdvisee(Database *database);
            break;
        case 6:
            UndoChangeOfAdvisor(Database *database);
            break;
    }
}

void Rollback::UndoFacultyDelete(Database *database){

}
void Rollback::UndoStudentDelete(Database *database){

}

void Rollback::UndoFacultyInsert(Database *database){

}
void Rollback::UndoStudentInsert(Database *database){

}

void Rollback::UndoChangeOfAdvisee(Database *database){

}
void Rollback::UndoChangeOfAdvisor(Database *database){

}*/
