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

	//LimitedAcceptingStack<Rollback> *rollbackStack;

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
};

#endif //DATABASE_H
