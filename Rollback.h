#ifndef ROLLBACK_H
#define ROLLBACK_H

#include "Database.h"
#include <iostream>

public class Rollback{
    private:
        bool isDelete;
        bool isFaculty;
        
        Faculty *rollbackFaculty;
        Student *rollbackStudent;

        void UndoFacultyDelete(Database *database);
        void UndoFacultyInsert(Database *database);

        void UndoStudentDelete(Database *database);
        void UndoStudentInsert(Database *database);

    public:
        Rollback(bool isDelete, Faculty *rollbackFaculty);
        Rollback(bool isDelete, Student *rollbackStudent);

        ~Rollback();

        
}

#endif //ROLLBACK_H