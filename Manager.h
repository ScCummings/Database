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
		DatabaseManager();
		~DatabaseManager();

        void RunManager();

	private:
		Database *schoolDatabase;

		bool PickOption(int option);

        void PrintHelp();

        int GetStudentID();
        int GetFacultyID();

        Student GetNewStudent();
        Faculty GetNewFaculty();
};

#endif //MANAGER_H
