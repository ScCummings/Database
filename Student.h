#ifndef STUDENT_H
#define STUDENT_H

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
};

#endif //STUDENT_H