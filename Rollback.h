#ifndef ROLLBACK_H
#define ROLLBACK_H

class Rollback;

#include "Database.h"
#include <iostream>

class Rollback{
    private:
        //1-Deleted Faculty
        //2-Deleted Student
        //3-Inserted Faculty
        //4-Inserted Student
        //5-Changed Advisee
        //6-Changed Advisor
        short rollbackAction;

        Faculty *deletedFaculty;
        Student *deletedStudent;
        int studentID = 0;
        int facultyID = 0;


        void UndoFacultyDelete(Database *database);
        void UndoStudentDelete(Database *database);

        void UndoFacultyInsert(Database *database);
        void UndoStudentInsert(Database *database);

        void UndoChangeOfAdvisee(Database *database);
        void UndoChangeOfAdvisor(Database *database);

    public:
        Rollback();
        Rollback(Faculty *deletedFaculty);
        Rollback(Student *deletedStudent);
        Rollback(int insertedPersonID, bool isFaculty);
        Rollback(int facultyID, int studentID, bool isChangeAdvisee);

        ~Rollback();

        void PerformRollback(Database *database);

        string ToString();

        //overloaded stream insertion operator
        friend ostream& operator<<(ostream& os, Rollback& r);
};

#endif //ROLLBACK_H
