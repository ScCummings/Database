//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Name:  Scott Cummings
//Student ID#:  2317991
//Chapman Email:  scummings@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  5 - School Database

#ifndef FACULTY_H
#define FACULTY_H

#include "GenDoubleLinkedList.h"
#include "Person.h"

using namespace std;

class Faculty : public Person {
private:
	GenDoubleLinkedList<int> *advisees;
public:
	//Default Constructor
	Faculty();

	//Overloaded constuctor for the PrintFaculty function
	Faculty(int ID);

	//Overloaded Constructor: Accepts params for all members except advisees
	Faculty(int id, string name, short rank, string specialization);

	//Overloaded Constructor: Accepts params for all members
	Faculty(int id, string name, short rank, string specialization, GenDoubleLinkedList<int> *advisees);

	//Destructor
	~Faculty();

    // Returns a serialized version of the faculty object
    string Serialize();

    // Returns a Faculty object parced from a string
    static Faculty Unserialize(string str) throw (UnserializeException);

	//Returns a complete list of Advisee ID numbers
	int* GetAdvisees();

	//Returns the number of advisees that the faculty member oversees
	int GetAdviseeCount();

    //Returns true if the faculty member has the advisee passed as a parameter by id
    bool HasAdvisee(int studentID);

	//Adds a single advisee to the list of advisees
	void AddAdvisee(int studentID);

	//Adds multiple advisees to the list of advisees
	void AddAdvisees(int* studentArray, int sizeOfStudentArray);

	//Removes a student from the advisee list
	void RemoveAdvisee(int studentID);

	// accessor for rank
	string GetRank();

	// mutator for rank
	void SetRank(short rank);

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
