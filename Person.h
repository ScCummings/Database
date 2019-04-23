#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person{
    private:
        // the ID number of the person
        int id;
        // the name of the person
        string name;
        // the rank of the person (Year for student and rank for faulty)
        string rank;
        // the Specialization of the person (major for student and department for faculty)
        string specialization;

    public:
        // accessor for rank
        virtual string GetRank() = 0;

        // accessor for name
        virtual string GetName() = 0;

        // accessor for ID
        virtual int GetID() = 0;

        // accessor for specialization
        virtual string GetSpecialization() = 0;

        // mutator for specialization
        virtual void SetRank(string specialization) = 0;
};

#endif //PERSON_H
