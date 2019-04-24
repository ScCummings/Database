#ifndef FACULTY_H
#define FACULTY_H

#include "GenDoubleLinkedList.h"
#include "Person.h"
#include <iostream>

using namespace std;

class Faculty : public Person{
    private:
        GenDoubleLinkedList<int> advisees;
    public:
        //Default Constructor
        Faculty();

        //Overloaded Constructor: Accepts params for all members except advisees
        Faculty(int id, string name, short rank, string specialization);

        //Overloaded Constructor: Accepts params for all members
        Faculty(int id, string name, short rank, string specialization, GenDoubleLinkedList<int> advisees);

        //Destructor
        ~Faculty();

        //Returns a complete list of Advisee ID numbers
        int* GetAdvisees();

        //Adds a single advisee to the list of advisees
        void AddAdvisee(int studentID);

        // accessor for rank
        string GetRank();

        // mutator for rank
        void SetRank();

        // accessor for name
        string GetName();

        // accessor for ID
        int GetID();

        // accessor for specialization
        string GetSpecialization();

        //Returns a string representation of the Faculty member in question
        string ToString();

        //overlaoded stream insertion operator
        friend ostream& operator<<(ostream& os, Faculty& f);
};

#endif //FACULTY_H
