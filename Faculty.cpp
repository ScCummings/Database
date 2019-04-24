#include "Faculty.h"
#include <iostream>

using namespace std;

//Default Constructor
Faculty::Faculty(){
    id = 0;
    name = "N/A";
    rank = -1;
    specialization = "N/A";
    //advisees = new GenDoubleLinkedList<int>();
}

//Overloaded Constructor: Accepts params for all members except advisees
Faculty::Faculty(int id, string name, short rank, string specialization){
    this->id = id;
    this->name = name;
    this->rank = rank;
    this->specialization = specialization;
    //this->advisees = new GenDoubleLinkedList<int>();
}

//Overloaded Constructor: Accepts params for all members
Faculty::Faculty(int id, string name, short rank, string specialization, GenDoubleLinkedList<int> advisees){
    this->id = id;
    this->name = name;
    this->rank = rank;
    this->specialization = specialization;
    //this->advisees = advisees;
}

//Destructor
Faculty::~Faculty(){
}

//Returns a complete list of Advisee ID numbers
int* Faculty::GetAdvisees(){
    int* advisees = new int[this->advisees.getSize()];

    int count = 0;
    while(this->advisees.hasNext()){
        advisees[count++] = this->advisees.getNext();
    }

    return advisees;
}

//Adds a single advisee to the list of advisees
void Faculty::AddAdvisee(int studentID){
    advisees.insertBack(studentID);
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
    
    while(this->advisees.hasNext()){
        fac += to_string(advisees.getNext()) + "\n";
        fac += "          ";
    }
    
    return fac;
}

//overlaoded stream insertion operator
ostream& operator<<(ostream& os, Faculty& f){
    os << f.ToString();
    return os;
}