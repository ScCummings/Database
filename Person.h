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
        virtual string GetRank() = 0;

        // mutator for rank
        void SetRank(short rank);

        // accessor for name
        virtual string GetName() = 0;

        // accessor for ID
        virtual int GetID() = 0;

        // accessor for specialization
        virtual string GetSpecialization() = 0;

        //Returns a string representation of the person in question
        virtual string ToString() = 0;

        //overlaoded stream insertion operator
        friend ostream& operator<<(ostream& os, Person& p);

        //overloaded comparison operator for Person objects
<<<<<<< HEAD
        bool operator ==(const Person& p) const{
            if(this->id == p.id){
                return true;
            }
            return false;
        }

        //overloaded not equal to operator for Person objects
        bool operator !=(const Person& p) const{
            if(this->id != p.id){
=======
        bool operator ==(Person& p) {
            if(p.id == this->id){
>>>>>>> c4e5ce9474c3ad1cb8fd5105a6134577befc1c2f
                return true;
            }
            return false;
        }

        //overloaded less than comparison operator for Person objects
        bool operator >(Person& p) {
            if(this->id > p.id){
                return true;
            }
            return false;
        }

        //overloaded greater than comparison operator for Person objects
        bool operator <(Person& p) {
            if(this->id < p.id){
                return true;
            }
            return false;
        }
};

#endif //PERSON_H
