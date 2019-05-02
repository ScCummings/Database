//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Name:  Scott Cummings
//Student ID#:  2317991
//Chapman Email:  scummings@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  5 - School Database

#ifndef DATABASE_H
#define DATABASE_H

class Database;

#include "Faculty.h"
#include "Student.h"
#include "Rollback.h"
#include "FileIO.h"
#include "GenTree.h"
#include "LimitedAcceptingStack.h"

#include <iostream>

class Database {
private:
	BST<Student> *studentTable;
	BST<Faculty> *facultyTable;

    FileIO fileIO;

	LimitedAcceptingStack<Rollback*> *rollbackStack;

	//Tries to load files with trees
	//If it succedes it returns true
	bool LoadFiles();
	

public:
	Database();
	Database(BST<Student> *studentTable, BST<Faculty> *facultyTable);
	~Database();

	void PrintFaculty();
	void PrintStudents();
	void PrintFaculty(int facultyID);
	void PrintStudent(int studentID);
	void PrintAdvisor(int studentID);
	void PrintAdvisees(int facultyID);
	void AddStudent(Student newStudent, bool isRollback);
	void DeleteStudent(int studentID, bool isRollback);
	void AddFaculty(Faculty newFaculty, bool isRollback);
	void DeleteFaculty(int facultyID, bool isRollback);
	void ChangeAdvisor(int studentID, int facultyID, bool isRollback);
	void RemoveAdvisee(int facultyID, int studentID, bool isRollback);
	void PerformRollback();
    void Quit();

    BST<Student>* GetStudentTable();
	BST<Faculty>* GetFacultyTable();
};

#endif //DATABASE_H
