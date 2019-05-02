<<<<<<< HEAD
/*#include "Rollback.h"
#include <iostream>
=======
#include "Rollback.h"
>>>>>>> abbce76f24cb6b1035a2cea1895d208446f50970

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
    database->AddStudent((*deletedStudent), true);
}

void Rollback::UndoFacultyInsert(Database *database){
    database->DeleteFaculty(facultyID, true);
}
void Rollback::UndoStudentInsert(Database *database){
    database->DeleteStudent(studentID, true);
}

void Rollback::UndoChangeOfAdvisee(Database *database){
    database->ChangeAdvisor(studentID, facultyID, true);
}
void Rollback::UndoChangeOfAdvisor(Database *database){
<<<<<<< HEAD

}*/
=======
    database->ChangeAdvisor(studentID, facultyID, true);
}
>>>>>>> abbce76f24cb6b1035a2cea1895d208446f50970
