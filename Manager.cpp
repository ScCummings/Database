#include "Manager.h"

DatabaseManager::DatabaseManager(){
    schoolDatabase = new Database();
}

DatabaseManager::~DatabaseManager(){
    delete schoolDatabase;
}

void DatabaseManager::RunManager(){
    cin.clear();
    cout << "----------------DATABASE----------------" << endl;
    int optionNumber;
    do{
        while(true){
            cout << "Please choose an action (type the number and press enter)" << endl;
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

            string temp;
            getline(cin, temp);

            try{
                optionNumber = stoi(temp);

                if((optionNumber >= 1) && (optionNumber <= 14)){
                    break;
                }
            }
            catch(invalid_argument e){
                cout << "**Command not recognized**" << endl;
            }
            catch(out_of_range e){
                cout << "**Command not recognized**" << endl;
            }

            cout << "**Command not recognized**" << endl;
        }
    }while(PickOption(optionNumber));
}

bool DatabaseManager::PickOption(int optionNumber){
    switch(optionNumber){
        //Print students
        case 1: {
            cout << "Printing students:" << endl;
            schoolDatabase->PrintStudents();

            return true;
        }
        break;

        //Print faculty

        case 2: {
            cout << "Printing faculty:" << endl;
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

            return true;
        }
        break;

        //Print specific faculty member
        case 4: {
            cout << "Printing single faculty member:" << endl;
            cout << "What is the ID of the faculty member you want to print?" << endl;
            int facultyID = GetFacultyID();
            schoolDatabase->PrintFaculty(facultyID);

            return true;
        }
        break;

        //Print student's advisor
        case 5: {
            cout << "Printing a student's advisor:" << endl;
            cout << "What is the ID of the student whose advisor you want to print?" << endl;
            int studentID = GetStudentID();
            schoolDatabase->PrintAdvisor(studentID);

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
            schoolDatabase->AddStudent(newStudent);
            
            return true;
        }
        break;

        //Delete a student
        case 8: {
            cout << "Deleting student:" << endl;
            cout << "What is the ID of the student you want to delete?" << endl;
            int studentID = GetStudentID();
            schoolDatabase->DeleteStudent(studentID);

            return true;
        }
        break;

        //Add a new faculty member
        case 9: {
            cout << "Adding new faculty member:" << endl;
            Faculty newFaculty = GetNewFaculty();
            schoolDatabase->AddFaculty(newFaculty);

            return true;
        }
        break;

        //Delete a faculty member
        case 10: {
            cout << "Deleting faculty member:" << endl;
            cout << "What is the ID of the faculty memeber you want to delete?" << endl;
            int facultyID = GetFacultyID();
            schoolDatabase->DeleteFaculty(facultyID);

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
            schoolDatabase->ChangeAdvisor(studentID, facultyID);

            return true;
        }
        break;

        //Remove Advisee
        case 12: {

            return true;
        }
        break;

        //rollback
        case 13: {
            return true;
        }
        break;

        //exit
        default: {
            return false;
        }
    }
}

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

        //Test to see if student ID is valid and contained in the tree
        bool isContained = true;

        if(isContained){
            return studentID;
        }
    }
}

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

        //Test to see if faculty ID is valid and contained in the tree
        bool isContained = true;

        if(isContained){
            return facultyID;
        }
    }
}

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

    //Get student's year
    while(keepGoing){
        cout << "What is the student's year?\n";

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
