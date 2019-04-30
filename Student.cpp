#include "Student.h"

using namespace std;
/*
a) default student constuctor
b) @param: none
c) @return: NA
d) no exceptions thrown
*/
Student::Student(){
    this->advisorID = 0;
    this->GPA = -1;
    this->id = 0;
    this->name = "N/A";
    this->rank = -1;
    this->specialization = "N/A";
}

/*
a) student overloaded constructor for the PrintStudent function
b) @param: int id - an integer value representing the student's ID number
c) @return: NA
d) no exceptions thrown
*/
Student::Student(int id){
    this->id = id;
    this->GPA = -1;
    this->advisorID = 0;
    this->name = "N/A";
    this->rank = -1;
    this->specialization = "N/A";
}

/*
a) Student overloaded constructor
b) @param: int ID - an int value representing the student's ID number | float GPA - a float value representing the student's GPA | int advisorID - an int value representing the student's advisor's ID | string name - a string value representing the student's name | short rank - a short value representing the student's year at the university | string specialization - a string value representing the student's major
c) @return: NA
d) no exceptions thrown
*/
Student::Student(int ID, float GPA, int advisorID, string name, short rank, string specialization){
    this->advisorID = advisorID;
    this->GPA = GPA;
    this->id = ID;
    this->name = name;
    this->rank = rank;
    this->specialization = specialization;
}

/*
a) Student destructor
b) @param: none
c) @return: NA
d) no exceptions thrown
*/
Student::~Student(){
    //nothing needs to happen here
}

/*
a) accessor for the student's advisor's ID
b) @param: none
c) @return: int - an integer value representing the student's advisor's ID
d) no exceptions thrown
*/
int Student::GetAdvisorID(){
    return advisorID;
}

/*
a) the accessor for the student's GPA
b) @param: none
c) @return: float - a float value representing the student's GPA
d) no exceptions thrown
*/
float Student::GetGPA(){
    return GPA;
}

/*
a) mutator for the student's advisor's ID
b) @param: int advisorID - an integer value representing the new advisor's ID
c) @return: void
d) no exceptions thrown
*/
void Student::SetAdvisorID(int advisorID){
    this->advisorID = advisorID;
}

/*
a) mutator for the student's GPA
b) @param: float GPA - a float value representing the student's new GPA
c) @return: void
d) no exceptions thrown
*/
void Student::SetGPA(float GPA){
    this->GPA = GPA;
}

/*
a) accessor for the student's ID
b) @param: none
c) @return: int - an integer value representing the student's ID
d) no exceptions thrown
*/
int Student::GetID(){
    return id;
}

/*
a) accessor for the student's name
b) @param: None
c) @return: string - a string value representing the students name
d) no exceptions thrown
*/
string Student::GetName(){
    return name;
}
/*
a) accessor for the student's rank
b) @param: none
c) @return: string - a string value representing the student's year at the university
d) no exceptions thrown
*/
string Student::GetRank(){
    switch (rank){
        case 0:
            return "First Year";
            break;
        case 1:
            return "Second Year";
            break;
        case 2:
            return "Third Year";
            break;
        case 3:
            return "Fourth Year";
            break;
        default:
            return "Short did not equate to a string value";
            break;
    }
}

/*
a) accessor for the student's specialization
b) @param: None
c) @return: string - a string that represents the student's major
d) no exceptions thrown
*/
string Student::GetSpecialization(){
    return specialization;
}

/*
a) mutator for the student's year at the university
b) @param: short rank - a short value representing the student's year at the university
c) @return: void
d) no exceptions thrown
*/
void Student::SetRank(short rank){
    this->rank = rank;
}

/*
a) mutator for the student's Specialization (major)
b) @param: string specialization - a string value representing the student's new major
c) @return: void
*/
void Student::SetSpecialization(string specialization){
    this->specialization = specialization;
}

/*
a) overloaded stream insertion operator
b) @param: ostream& os - the address of an ostream, the object we use to print out the student | Student& - the address of the student object that we are printing out
c) @return: ostream& os - the address of the ostream that we used to print out the student objecy
d) no exceptions thrown
*/
ostream& operator<<(ostream& os, Student& s){
    os << s.ToString();
    return os;
}

/*
a) Student ToString function
b) @param: none
c) @return: string - a string value that has the most important aspects of the student object
d) no exceptions thrown
*/
string Student::ToString(){
    string stu = "";
    stu += "Student: " + to_string(id) + "\n";
    stu += name + "\n";
    stu += GetRank() + " in " + GetSpecialization() + "\n";
    stu += "Advisor ID: " + GetAdvisorID();

    return stu;
}
