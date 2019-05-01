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

        void SaveStudentRec(TreeNode<Student> *curr);

        void SaveFacultyRec(TreeNode<Faculty> *curr);

    public:
        bool CheckLoadStatus();
        void Save(BST<Student>* studentTree, BST<Faculty>* facultyTree);
        BST<Student>* LoadStudents();
        BST<Faculty>* LoadFaculty();
};

#endif //FILE_IO_H
