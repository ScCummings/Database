#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "GenStack.h"
#include <iostream>
#include <string>

using namespace std;
class Student : public Person
{
    private:
        // the ID of the student's advisor
        int advisorID;

        // the student's GPA
        float GPA;

        //accessors and mutators
    public:
        //student constuctor
        Student();

        //overloaded student constructor for the PrintStudent function
        Student(int ID);

        //student overloaded constructor
        Student(int ID, float GPA, int advisorID, string name, short rank, string specialization);

        //student destructor
        ~Student();

        //returns a serialized string representation of the Student object
        string Serialize();

        // returns a Student object parced from a string
        static Student Unserialize(string str);

        // accessor for the student's advisor's ID
        int GetAdvisorID();

        // the accessor for the student's GPA
        float GetGPA();

        // mutator for the student's advisor's ID
        void SetAdvisorID(int advisorID);

        // mutator for the student's GPA
        void SetGPA(float GPA);




        //accessor for the Student's ID
        int GetID();

        //accessor for the Student's Name
        string GetName();

        //accessor for the Student's rank
        string GetRank();

        //accessor for the student's major
        string GetSpecialization();

        //mutator for the Student's rank
        void SetRank(short rank);

        //mutator for the student's specialization
        string SetSpecialization(string specialization);

        //overloaded stream insertion operator
        friend ostream& operator<<(ostream& os, Student& s);

        string ToString();

};

#endif //STUDENT_H
