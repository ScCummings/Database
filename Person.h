#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person{
    protected:
        // the ID number of the person
        int id;
        // the name of the person
        string name;
        // the rank of the person (Year for student and rank for faulty)
        short rank;
        // the Specialization of the person (major for student and department for faculty)
        string specialization;

    public:
        // accessor for rank
        virtual string GetRank() const = 0;

        // mutator for rank
        virtual void SetRank() = 0;

        // accessor for name
        virtual string GetName() const = 0;

        // accessor for ID
        virtual int GetID() const = 0;

        // accessor for specialization
        virtual string GetSpecialization() const = 0;

        //overloaded comparison operator for Person objects
        bool operator ==(const Person& p) const;

        //overloaded less than comparison operator for Person objects
        bool operator >(const Person& p) const;

        //overloaded greater than comparison operator for Person objects
        bool operator <(const Person& p) const;
};

bool Person::operator ==(const Person& p) const{
    if(p.id == this->id){
        return true;
    }
    return false;
}

bool Person::operator >(const Person& p) const{
    if(p.id > this->id){
        return true;
    }
    return false;
}

bool Person::operator <(const Person& p) const{
    if(p.id < this->id){
        return true;
    }
    return false;
}

#endif //PERSON_H