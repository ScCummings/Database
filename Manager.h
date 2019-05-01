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

        int GetStudentID();
        int GetFacultyID();

        Student GetNewStudent();
        Faculty GetNewFaculty();
};

#endif //MANAGER_H
