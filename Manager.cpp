//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Name:  Scott Cummings
//Student ID#:  2317991
//Chapman Email:  scummings@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  5 - School Database

#include "Manager.h"
/*
a) Constructor for the DatabaseManager class
b) @param: none
c) @return: NA
d) no exceptions thrown
*/
DatabaseManager::DatabaseManager(){
    schoolDatabase = new Database();
}

/*
a) destructor for the DatabaseManager class
b) @param: none
c) @return: NA
d) no exceptions thrown
*/
DatabaseManager::~DatabaseManager(){
    delete schoolDatabase;
}

/*
a) function that runs the main implementation of the program
b) @param: none
c) @return: void
d) invalid_argument & out_of_range exceptions thrown
*/
void DatabaseManager::RunManager(){
    cin.clear();
    cin.ignore(1, EOF);
    cout << "----------------DATABASE----------------" << endl;
    int optionNumber;
    do{
        while(true){
            cout << "->";

            string temp;
            getline(cin, temp);

            if(temp == ""){
                continue;
            }

            try{
                optionNumber = stoi(temp);

                if((optionNumber >= 0) && (optionNumber <= 14)){
                    break;
                }
            }
            catch(invalid_argument e){
                cout << "**Command not recognized: enter 0 for help**" << endl;
                continue;
            }
            catch(out_of_range e){
                cout << "**Command not recognized: enter 0 for help**" << endl;
                continue;
            }

            cout << "**Command not recognized: enter 0 for help**" << endl;
        }
    }while(PickOption(optionNumber));
}

/*
a) Basic logic for what functions to call when a user picks an option
b) @param: int optionNumber - the number that the user chose
c) @return: bool - returns whether or not their request was successfully carried out
d) no exceptions thrown
*/
bool DatabaseManager::PickOption(int optionNumber){
    switch(optionNumber){
        //Prints help screen
        case 0: {
            PrintHelp();
            return true;
        }
        break;

        //Print students
        case 1: {
            cout << "Printing students:" << endl << endl;
            schoolDatabase->PrintStudents();

            return true;
        }
        break;

        //Print faculty

        case 2: {
            cout << "Printing faculty:" << endl << endl;
            schoolDatabase->PrintFaculty();

            return true;
        }
        break;

        //Print specific student
        case 3: {
            cout << "Printing single student:" << endl;
            cout << "What is the ID of the student you want to print" << endl;
            int studentID = GetStudentID();
            schoolDatabase->PrintStudent(studentID);
            cout << endl;
            return true;
        }
        break;

        //Print specific faculty member
        case 4: {
            cout << "Printing single faculty member:" << endl;
            cout << "What is the ID of the faculty member you want to print?" << endl;
            int facultyID = GetFacultyID();
            schoolDatabase->PrintFaculty(facultyID);
            cout << endl;
            return true;
        }
        break;

        //Print student's advisor
        case 5: {
            cout << "Printing a student's advisor:" << endl;
            cout << "What is the ID of the student whose advisor you want to print?" << endl;
            int studentID = GetStudentID();
            schoolDatabase->PrintAdvisor(studentID);
            cout << endl;
            return true;
        }
        break;

        //Print faculty member's advisees
        case 6: {
            cout << "Printing all a faculty member's advisees:" << endl;
            cout << "What is the ID of the faculty member whose advisees you want to print?" << endl;
            int facultyID = GetFacultyID();
            schoolDatabase->PrintAdvisees(facultyID);
            return true;
        }
        break;

        //Add a new student
        case 7: {
            cout << "Adding new student:" << endl;
            Student newStudent = GetNewStudent();
            schoolDatabase->AddStudent(newStudent, false);

            return true;
        }
        break;

        //Delete a student
        case 8: {
            cout << "Deleting student:" << endl;
            cout << "What is the ID of the student you want to delete?" << endl;
            int studentID = GetStudentID();
            schoolDatabase->DeleteStudent(studentID, false);

            return true;
        }
        break;

        //Add a new faculty member
        case 9: {
            cout << "Adding new faculty member:" << endl;
            Faculty newFaculty = GetNewFaculty();
            schoolDatabase->AddFaculty(newFaculty, false);
            cout << "Made it past add faculty" << endl;

            return true;
        }
        break;

        //Delete a faculty member
        case 10: {
            cout << "Deleting faculty member:" << endl;
            cout << "What is the ID of the faculty memeber you want to delete?" << endl;
            int facultyID = GetFacultyID();
            schoolDatabase->DeleteFaculty(facultyID, false);

            return true;
        }
        break;

        //Change advisor
        case 11: {
            cout << "Changing student's advisor:" << endl;
            cout << "What is the ID of the student whose advisor you want to change?" << endl;
            int studentID = GetStudentID();
            cout << "What is the ID of the faculty who will be the new advisor for student " << studentID << " ?" << endl;
            int facultyID = GetFacultyID();
            schoolDatabase->ChangeAdvisor(studentID, facultyID, false);

            return true;
        }
        break;

        //Remove Advisee
        case 12: {
            cout << "Removing a faculty member's advisee:" << endl;
            cout << "WARNING: THIS WILL LEAVE THE STUDENT WITHOUT AN ADVISOR" << endl;
            cout << "What is the ID of the faculty member you wish to remove from?" << endl;
            int facultyID = GetFacultyID();
            cout << "What is the ID of the advisee you wish to remove?" << endl;
            int studentID = GetStudentID();
            schoolDatabase->RemoveAdvisee(facultyID, studentID, false);
            return true;
        }
        break;

        //rollback
        case 13: {
            cout << "Rolling back previous change\n";
            schoolDatabase->PerformRollback();
            return true;
        }
        break;

        //exit
        default: {
            cout << "Exiting...\n";
            schoolDatabase->Quit();
            return false;
        }
    }
}

/*
a) input function that has the user enter in information for the new Student's ID number
b) @param: none
c) @return: int - the ID number of the student
d) invalid_argument & out_of_range exceptions caught
*/
int DatabaseManager::GetStudentID(){
    int studentID;
    while(true){
        bool keepGoing = true;
        while(keepGoing){
            cout << "Please enter an existing student id number\n";
            string sIDString;
            getline(cin, sIDString);

            try{
                studentID = stoi(sIDString);
                if(studentID <= 0){
                    cout << "Invalid ID number\n";
                }
                else{
                    Student stuTemp(studentID);
                    if(database.GetStudentTable().contains(studentID)){
                        keepGoing = false;
                    }
                    else{
                        cerr << "Student ID was not found." << endl;
                    }
                }
            }
            catch(invalid_argument e){
                cout << "Invalid ID number\n";
            }
            catch(out_of_range e){
                cout << "Invalid ID number\n";
            }
        }

        //Test to see if student ID is valid and contained in the tree
        bool isContained = true;

        if(isContained){
            return studentID;
        }
    }
}
/*
a) input function that has the user enter in information for the new Faculty member's ID number
b) @param: none
c) @return: int - the ID number of the faculty member
d) invalid_argument & out_of_range exceptions caught
*/
int DatabaseManager::GetFacultyID(){
    while(true){
        int facultyID;
        bool keepGoing = true;
        while(keepGoing){
            cout << "Please enter an existing faculty id number\n";
            string fIDString;
            getline(cin, fIDString);

            try{
                facultyID = stoi(fIDString);
                if(facultyID <= 0){
                    cout << "Invalid ID number\n";
                }
                else{
                    Faculty facTemp(facultyID);
                    if(database.GetFacultyTable().contains(facultyID)){
                        keepGoing = false;
                    }
                    else{
                        cerr << "Faculty ID was not found." << endl;
                    }
                }
            }
            catch(invalid_argument e){
                cout << "Invalid ID number\n";
            }
            catch(out_of_range e){
                cout << "Invalid ID number\n";
            }
        }

        //Test to see if faculty ID is valid and contained in the tree
        bool isContained = true;

        if(isContained){
            return facultyID;
        }
    }
}

/*
a) input function that has the user enter in information for the new Student object
b) @param: none
c) @return: Student - the student object that is created by the user
d) invalid_argument & out_of_range exceptions caught
*/
Student DatabaseManager::GetNewStudent(){
    int studentID;
    float studentGPA;
    string studentName;
    string studentMajor;
    short studentYear;
    int advisorID;

    bool keepGoing = true;

    //Getting student ID
    while(keepGoing){
        cout << "What is the new student's ID number?\n";
        string sIDString;
        getline(cin, sIDString);

        try{
            studentID = stoi(sIDString);
            if(studentID <= 0){
                cout << "Invalid ID number\n";
            }
            else{
                keepGoing = false;
            }
        }
        catch(invalid_argument e){
            cout << "Invalid ID number\n";
        }
        catch(out_of_range e){
            cout << "Invalid ID number\n";
        }

    }

    keepGoing = true;

    //Getting student Name
    while(keepGoing){
        cout << "What is the new student's name?\n";
        getline(cin, studentName);

        //add input protection if you get around to it!

        keepGoing = false;
    }

    keepGoing = true;

    //Getting student's specialization
    while(keepGoing){
        cout << "What is the new student's specialization/major?\n";
        getline(cin, studentMajor);

        //add input protection if you get around to it!

        keepGoing = false;
    }

    keepGoing = true;

    //Getting student's GPA
    while(keepGoing){
        cout << "What is the new student's GPA?\n";
        string sGPAString;
        getline(cin, sGPAString);

        try{
            studentGPA = stoi(sGPAString);

            if(0 <= studentGPA && studentGPA <= 5.0){
                keepGoing = false;
            }
            else{
                cout << "Invalid GPA, please enter a decimal between 0.0 and 5.0\n";
            }
        }
        catch(invalid_argument e){
            cout << "Invalid GPA, please enter a decimal between 0.0 and 5.0\n";
        }
        catch(out_of_range e){
            cout << "Invalid GPA, please enter a decimal between 0.0 and 5.0\n";
        }
    }

    keepGoing = true;

    //Get student's year
    while(keepGoing){
        cout << "What is the student's year?\n";

        string sYearString;
        getline(cin, sYearString);

        try{
            studentYear = stoi(sYearString);

            if(1 <= studentYear && studentYear <= 4){
                studentYear--;
                keepGoing = false;
            }
            else{
                cout << "Invalid year, only years 1-4 are supported\n";
            }
        }
        catch(invalid_argument e){
            cout << "Invalid year, only years 1-4 are supported\n";
        }
        catch(out_of_range e){
            cout << "Invalid year, only years 1-4 are supported\n";
        }
    }

    advisorID = GetFacultyID();

    Student returnStudent(studentID, studentGPA, advisorID, studentName, studentYear, studentMajor);
    return returnStudent;
}

/*
a) input function that has the user enter in information for the new Faculty object
b) @param: none
c) @return: Faculty - the faculty object that is created by the user
d) invalid_argument & out_of_range exceptions caught
*/
Faculty DatabaseManager::GetNewFaculty(){
    int facultyID;
    string name;
    short rank;
    string specialization;

    bool keepGoing = true;

    //Getting faculty ID
    while(keepGoing){
        cout << "What is the new faculty member's ID number?\n";
        string fIDString;
        getline(cin, fIDString);

        try{
            facultyID = stoi(fIDString);
            if(facultyID <= 0){
                cout << "Invalid ID number\n";
            }
            else{
                keepGoing = false;
            }
        }
        catch(invalid_argument e){
            cout << "Invalid ID number\n";
        }
        catch(out_of_range e){
            cout << "Invalid ID number\n";
        }

    }

    keepGoing = true;

    //Getting faculty member Name
    while(keepGoing){
        cout << "What is the new faculty member's name?\n";
        getline(cin, name);

        //add input protection if you get around to it!

        keepGoing = false;
    }

    keepGoing = true;

    //Getting faculty member's specialization
    while(keepGoing){
        cout << "What is the new faculty member's specialization/department?\n";
        getline(cin, specialization);

        //add input protection if you get around to it!
        keepGoing = false;
    }

    keepGoing = true;

    //Get faculty member's year
    while(keepGoing){
        cout << "What is the faculty member's rank?\n";

        string fRankString;
        getline(cin, fRankString);

        try{
            rank = stoi(fRankString);

            if(0 <= rank && rank <= 5){
                keepGoing = false;
            }
            else{
                cout << "Invalid rank, only ranks 0-5 are supported\n";
            }
        }
        catch(invalid_argument e){
            cout << "Invalid rank, only ranks 0-5 are supported\n";
        }
        catch(out_of_range e){
            cout << "Invalid rank, only ranks 0-5 are supported\n";
        }

    }

    Faculty returnFaculty(facultyID, name, rank, specialization);

    return returnFaculty;
}

void DatabaseManager::PrintHelp(){
    cout << "Please choose an action (type the number and press enter)" << endl;
    cout << "0 ) Prints help screen" << endl;
    cout << "1 ) Print all students" << endl;
    cout << "2 ) Print all faculty members" << endl;
    cout << "3 ) Print a specific student" << endl;
    cout << "4 ) Print a specific faculty member" << endl;
    cout << "5 ) Print a student's advisor" << endl;
    cout << "6 ) Print a faculty member's advisees" << endl;
    cout << "7 ) Add a new student" << endl;
    cout << "8 ) Delete a student" << endl;
    cout << "9 ) Add a new faculty member" << endl;
    cout << "10) Delete a faculty member" << endl;
    cout << "11) Change a student's advisor" << endl;
    cout << "12) Remove an advisee from an advisor" << endl;
    cout << "13) Rollback a change" << endl;
    cout << "14) Exit" << endl << endl;
}
