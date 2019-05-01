#include <iostream>
#include <string>
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
#include "GenDoubleLinkedList.h"
using namespace std;

Student GetNewStudent();
Faculty GetNewFaculty();
int GetStudentID();
int GetFaculutID();
/*
int main(){
    string someString = "{\"id\":1,\"name\":\"Queenie\",\"rank\":2,\"specialization\":\"Sci\",\"GPA\":4.0,\"advisorID\":4432}";
    string someStringF = "{\"id\":4432,\"name\":\"Urdu\",\"rank\":0,\"specialization\":\"Queso Studies\",\"advisees\":[]}";


    Student bitchface = Student::Unserialize(someString);
    cout << bitchface << endl << endl;
    cout << "someString:  " << someString << endl;
    cout << "bitchface.:  " << bitchface.Serialize() << endl << endl;
    cout << "**********************************" << endl << endl;
    Faculty someFaculty = Faculty::Unserialize(someStringF);
    cout << someFaculty << endl << endl;
    cout << "someStringF:  " << someStringF << endl;
    cout << "someFaculty:  " << someFaculty.Serialize() << endl << endl;
    cout << "**********************************" << endl << endl;
    Student s = GetNewStudent();
    cout << s << endl << endl;
    cout << s.Serialize() << endl << endl;
    cout << "**********************************" << endl << endl;
    Faculty f = GetNewFaculty();
    cout << f << endl << endl;
    cout << f.Serialize() << endl;
    return 0;
}
*/
int GetStudentID(){
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

int GetFacultyID(){
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

        //Test to see if student ID is valid and contained in the tree
        bool isContained = true;

        if(isContained){
            return facultyID;
        }
    }
}

Student GetNewStudent(){
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

Faculty GetNewFaculty(){
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

    Faculty returnFaculty(facultyID, name, rank, specialization);
    return returnFaculty;
}