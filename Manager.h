//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Name:  Scott Cummings
//Student ID#:  2317991
//Chapman Email:  scummings@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  5 - School Database

#ifndef MANAGER_H
#define MANAGER_H

#include "Database.h"
#include <iostream>

using namespace std;

class DatabaseManager{
	public:
        //Constructor for the DatabaseManager class
		DatabaseManager();

        //destructor for the DatabaseManager class
		~DatabaseManager();

        //function that runs the main implementation of the program
        void RunManager();

	private:
		Database *schoolDatabase;

        //Basic logic for what functions to call when a user picks an option
		bool PickOption(int option);
        
        //prints each of the available options for users
        void PrintHelp();


        //input function that has the user enter in information for the new Student object
        int GetStudentID() throw (int);

        //input function that has the user enter in information for the new Faculty member's ID number
        int GetFacultyID() throw (int);


        //input function that has the user enter in information for the new Student object
        Student GetNewStudent() throw (int);

        //input function that has the user enter in information for the new Faculty object
        Faculty GetNewFaculty() throw (int);


        //Calls PrintStudentIDs on the root
        void PrintStudentIDs();

        //Preorder traversal to print each of the student's ID's
		void PrintStudentIDs(TreeNode<Student> *current);

        //Calls PrintFacultyIDs on the root
		void PrintFacultyIDs();

        //Preorder traversal to print each of the faculty's ID's
		void PrintFacultyIDs(TreeNode<Faculty> *current);
};

#endif //MANAGER_H
