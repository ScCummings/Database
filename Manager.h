#include "Database.h"
#include <iostream>

using namespace std;

class DatabaseManager{
	public:
		DatabaseManager();
		~DatabaseManager();

		bool PickOption();

	private:
		Database *schoolDatabase;

        int GetStudentID();
        int GetFacultyID();
        
        Student GetNewStudent();
        Faculty GetNewFaculty();
};
