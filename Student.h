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
        short GetRank();

        //accessor for the student's major
        string GetSpecialization();

        //mutator for the student's specialization
        string SetSpecialization(string specialization);
};

#endif //STUDENT_H
