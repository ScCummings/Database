#ifndef DATABASE_H
#define DATABASE_H

//#include "GenDoubleLinkedList.h"
#include "Faculty.h"
#include "Student.h"
#include "GenTree.h"

#include <iostream>

class Database{
    private:
        BST<Student> *studentTable;
        BST<Faculty> *facultyTable;

    public:
        void PrintFaculty();
        void PrintStudents();
        void PrintFaculty(int facultyID);
        void PrintStudent(int studentID);
        void PrintAdvisor(int studentID);
        void PrintAdvisees(int facultyID);
        void AddStudent(Student newStudent);
        void DeleteStudent(int studentID);
        void AddFaculty(Faculty newFaculty);
        void DeleteFaculty(int facultyID);
        void ChangeAdvisor(int studentID,int facultyID);
        void RemoveAdvisee(int facultyID,int studentID);
        void Rollback();
};

#endif //DATABASE_H
