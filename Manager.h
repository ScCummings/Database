#include "Database.h"
#include <iostream>

using namespace std;

class DatabaseManager{
    public:
        DatabaseManager();
        ~DatabaseManager();

        bool PickOption(int option);

    private:
        Database *schoolDatabase;

        int GetStudentID();
        int GetFacultyID();
}
