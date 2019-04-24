#include "Student.h"
// accessor for the student's advisor's ID
int Student::GetAdvisorID(){
    return advisorID;
}

// the accessor for the student's GPA
float Student::GetGPA(){
    return GPA;
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
short Student::GetRank(){
    return rank;
}

//accessor for the student's specialization
string Student::GetSpecialization(){
    return specialization;
}

//mutator for the student's Specialization (major)
string Student::SetSpecialization(string specialization){
    this->specialization = specialization;
}

// mutator for the student's advisor's ID
void Student::SetAdvisorID(int advisorID){
    this->advisorID = advisorID;
}

// mutator for the student's GPA
void Student::SetGPA(float GPA){
    this->GPA = GPA;
}
