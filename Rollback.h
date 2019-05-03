//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Name:  Scott Cummings
//Student ID#:  2317991
//Chapman Email:  scummings@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  5 - School Database

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

        //Function for undoing a faculty delete
        void UndoFacultyDelete(Database *database);

        //Function for undoing a student delete
        void UndoStudentDelete(Database *database);


        //Function for undoing a faculty insert
        void UndoFacultyInsert(Database *database);

        //Function for undoing a student insert
        void UndoStudentInsert(Database *database);


        //Function for undoing an advisee removal
        void UndoChangeOfAdvisee(Database *database);

        //Function for undoing a change of advisor
        void UndoChangeOfAdvisor(Database *database);

    public:
        //Default constructor
        Rollback();

        //Overloaded constructor for the Rollback class
        Rollback(Faculty *deletedFaculty);

        //Overloaded constructor for the Rollback class
        Rollback(Student *deletedStudent);

        //Overloaded constructor for the Rollback class
        Rollback(int insertedPersonID, bool isFaculty);

        //Overloaded constructor for the Rollback class
        Rollback(int facultyID, int studentID, bool isChangeAdvisee);

        //Default Destructor
        ~Rollback();

        //Chooses the correct function based off rollback action short
        void PerformRollback(Database *database);
};

#endif //ROLLBACK_H

