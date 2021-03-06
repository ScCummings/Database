//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Name:  Scott Cummings
//Student ID#:  2317991
//Chapman Email:  scummings@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  5 - School Database

#ifndef FILE_IO_H
#define FILE_IO_H

#include <fstream>
#include <iostream>

#include "Student.h"
#include "Faculty.h"
#include "GenTree.h"

using namespace std;

class FileIO{
    private:
        //file input stream
        ifstream inputStream;
        //file output stream
        ofstream outputStream;

        //Stores string for name of student data file
        const string studentData = "StudentTable.dat";
        //Stores string for name of student data dump file
        const string studentDataDump = "StudentTableDump.dat";

        //Stores string for name of faculty data file
        const string facultyData = "FacultyTable.dat";
        //Stores string for name of facluty data dump file
        const string facultyDataDump = "FacultyTableDump.dat";

        void SaveStudentRec(TreeNode<Student> *curr) throw (UnserializeException);

        void SaveFacultyRec(TreeNode<Faculty> *curr) throw (UnserializeException);

    public:
        bool CheckLoadStatus();
        void Save(BST<Student>* studentTree, BST<Faculty>* facultyTree);
        BST<Student>* LoadStudents() throw (UnserializeException);
        BST<Faculty>* LoadFaculty() throw (UnserializeException);
};

#endif //FILE_IO_H
