#include "Faculty.h"
#include <iostream>

using namespace std;

//Default Constructor
Faculty::Faculty(){
    id = 0;
    name = "N/A";
    rank = -1;
    specialization = "N/A";
    advisees = new GenDoubleLinkedList<int>();
}

/*
Faculty::Faculty(Faculty that){
    this->id = that.id;
    this->name = that.name;
    this->rank = that.name;
    this->specialization = that.specialization;
    this->advisees = that.advisees;
}
*/

//Overloaded Constructor for the PrintFaculty Function
Faculty::Faculty(int ID){
    id = ID;
    name = "N/A";
    rank = -1;
    specialization = "N/A";

}

//Overloaded Constructor: Accepts params for all members except advisees
Faculty::Faculty(int id, string name, short rank, string specialization){
    this->id = id;
    this->name = name;
    this->rank = rank;
    this->specialization = specialization;
    this->advisees = new GenDoubleLinkedList<int>();
}

//Overloaded Constructor: Accepts params for all members
Faculty::Faculty(int id, string name, short rank, string specialization, GenDoubleLinkedList<int> *advisees){
    this->id = id;
    this->name = name;
    this->rank = rank;
    this->specialization = specialization;
    this->advisees = advisees;
}

//Destructor
Faculty::~Faculty(){
}

//Returns a complete list of Advisee ID numbers
int* Faculty::GetAdvisees(){
    int* adv = new int[advisees->getSize()];

    advisees->resetIterator();
    int count = 0;
    while(advisees->hasNext()){
        adv[count++] = advisees->getNext();
    }

    return adv;
}

//Returns the number of advisees that the faculty member oversees
int Faculty::GetAdviseeCount(){
    return advisees->getSize();
}

//Adds a single advisee to the list of advisees
void Faculty::AddAdvisee(int studentID){
    advisees->insertBack(studentID);
}

//Removes a student from the advisee list
void Faculty::RemoveAdvisee(int studentID){
    advisees->remove(studentID);
}

// accessor for rank
string Faculty::GetRank(){
    switch(rank){
        case 0:
            return "Lecturer";
        case 1:
            return "Assistant Professor";
        case 2:
            return "Adjunct Professor";
        case 3:
            return "Associate Professor";
        case 4:
            return "Tenure Professor";
        case 5:
            return "Professor Emeritus";
        default:
            return "N/A";
    }
}

// mutator for rank
void Faculty::SetRank(short rank){
    this->rank = rank;
}

// accessor for name
string Faculty::GetName(){
    return name;
}

// accessor for ID
int Faculty::GetID(){
    return id;
}

// accessor for specialization
string Faculty::GetSpecialization(){
    return specialization;
}

//Returns a string representation of the Faculty member in question
string Faculty::ToString(){
    string fac = "";
    fac += "Faculty Member: " + to_string(id) + "\n";
    fac += name + "\n";
    fac += GetRank() + " in " + GetSpecialization() + "\n";
    fac += "Advisees: ";
    advisees->resetIterator();
    while(advisees->hasNext()){
        //cout << "Makes it into while loop" << endl;
        fac += to_string(advisees->getNext());
        if(advisees->hasNext()){
            //cout << "if statement happens" << endl;
            fac += "\n          ";
        }
    }
    return fac;
}

//overlaoded stream insertion operator
ostream& operator<<(ostream& os, Faculty& f){
    os << f.ToString();
    //cout << "Makes it to return" << endl;
    return os;
}
