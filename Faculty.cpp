#include "Faculty.h"
#include <iostream>
using namespace std;

//Default Constructor
Faculty::Faculty(){
    id = 0;
}

//Overloaded Constructor: Accepts params for all members except advisees
Faculty::Faculty(int id, string name, short rank, string specialization){
    this.id = id;
    this.name = name;
    this.rank = rank;
    this.specialization = specialization;
    this.advisees = new GenDoubleLinkedList<int>();
}

//Overloaded Constructor: Accepts params for all members
Faculty::Faculty(int id, string name, short rank, string specialization, GenDoubleLinkedList<int> advisees){
    this.id = id;
    this.name = name;
    this.rank = rank;
    this.specialization = specialization;
    this.advisees = advisees;
}

//Destructor
Faculty::~Faculty(){
    delete advisees;
}

//Returns a complete list of Advisee ID numbers
int* Faculty::GetAdvisees(){
    int* advisees = new int[this.advisees->getSize()];

    int count = 0;
    while(this.advisees->hasNext()){
        advisees[count++] = this.advisees->getNext();
    }

    return advisees;
}

//Adds a single advisee to the list of advisees
void Faculty::AddAdvisee(int studentID){

}

// accessor for rank
string Faculty::GetRank(){
    return "";
}

// mutator for rank
void Faculty::SetRank(){

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