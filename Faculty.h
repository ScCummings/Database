#ifndef FACULTY_H
#define FACULTY_H

#include "GenDoubleLinkedList.h"
#include "Person.h"

class Faculty : public Person{
    private:
        GenDoubleLinkedList<int> *advisees;
    public:
        //Default Constructor
        Faculty();

        //Overloaded Constructor: Accepts params for all members except advisees
        Faculty(int id, string name, short rank, string specialization);

        //Overloaded Constructor: Accepts params for all members
        Faculty(int id, string name, short rank, string specialization, GenDoubleLinkedList<int> *advisees);

        //Destructor
        ~Faculty();

        //Returns a complete list of Advisee ID numbers
        GenDoubleLinkedList<int> GetAdvisees();

        //Adds a single advisee to the list of advisees
        void AddAdvisee(int studentID);
};

#endif //FACULTY_H
