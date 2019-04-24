#include "Student.h"

using namespace std;
//Student default constructor
Student::Student(){
    this->advisorID = 0;
    this->GPA = 0;
    this->id = 0;
    this->name = "0";
    this->rank = 0;
    this->specialization = "0";
}

//Student overloaded constructor
Student::Student(int advisorID, float GPA, int ID, string name, short rank, string specialization){
    this->advisorID = advisorID;
    this->GPA = GPA;
    this->id = ID;
    this->name = name;
    this->rank = rank;
    this->specialization = specialization;
}

Student::~Student(){
    //nothing needs to happen here
}




// accessor for the student's advisor's ID
int Student::GetAdvisorID(){
    return advisorID;
}

// the accessor for the student's GPA
float Student::GetGPA(){
    return GPA;
}

// mutator for the student's advisor's ID
void Student::SetAdvisorID(int advisorID){
    this->advisorID = advisorID;
}

// mutator for the student's GPA
void Student::SetGPA(float GPA){
    this->GPA = GPA;
}




// accessor for the student's ID
int Student::GetID(){
    return id;
}

//accessor for the student's name
string Student::GetName(){
    return name;
}

//accessor for the student's rank
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

//accessor for the student's specialization
string Student::GetSpecialization(){
    return specialization;
}

void Student::SetRank(short rank){
    this->rank = rank;
}

//mutator for the student's Specialization (major)
string Student::SetSpecialization(string specialization){
    this->specialization = specialization;
}

//overloaded stream insertion operator
ostream& operator<<(ostream& os, Student& s){
    os << s.ToString();
}

//Student ToString function
string Student::ToString(){
    string stu = "";
    stu += "Student: " + to_string(id) + "\n";
    stu += name + "\n";
    stu += GetRank() + " in " + GetSpecialization() + "\n";
    stu += "Advisor ID: " + GetAdvisorID();

    return stu;
}
