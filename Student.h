#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
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

        //student overloaded constructor
        Student(int advisorID, float GPA, int ID, string name, short rank, string specialization);




        // accessor for the student's advisor's ID
        int GetAdvisorID();

        // the accessor for the student's GPA
        float GetGPA();

        // mutator for the student's advisor's ID
        void SetAdvisorID(int advisorID);

        // mutator for the student's GPA
        void SetGPA(float GPA);




        //accessor for the Student's ID
        int GetID() const;

        //accessor for the Student's Name
        string GetName() const;

        //accessor for the Student's rank
        string GetRank() const;

        //accessor for the student's major
        string GetSpecialization() const;

        //mutator for the Student's rank
        void SetRank(short rank);

        //mutator for the student's specialization
        string SetSpecialization(string specialization);
};

#endif //STUDENT_H
