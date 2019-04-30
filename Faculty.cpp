#include "Faculty.h"
#include <iostream>

using namespace std;

/*
a) default constructor for the Faculty class
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
Faculty::Faculty() {
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

/*
a) overloaded constructor for the Faculty class
b) @param: int ID - an integer value that represents the Faculty's ID number
c) @return: NA
d) no exceptions thrown
*/
Faculty::Faculty(int ID) {
	id = ID;
	name = "N/A";
	rank = -1;
	specialization = "N/A";
	advisees = new GenDoubleLinkedList<int>();
}

/*
a) overloaded constructor for the Faculty class, accepts all the variables for the Faculty object except for advisees
b) @param: int id - an integer value that represents the faculty member's ID number | string name - a string value that represents the faculty member's name | short rank - a short variable that represents the Faculty's rank at the university | string specialization - a string value that represents the department that the faculty member is in
c) @return: NA
d) no exceptions thrown
*/
Faculty::Faculty(int id, string name, short rank, string specialization) {
	this->id = id;
	this->name = name;
	this->rank = rank;
	this->specialization = specialization;
	this->advisees = new GenDoubleLinkedList<int>();
}

/*
a) overloaded constructor for the Faculty class, accepts all the variables for the Faculty object
b) @param: int id - an integer value that represents the faculty member's ID number | string name - a string value that represents the faculty member's name | short rank - a short variable that represents the Faculty's rank at the university | string specialization - a string value that represents the department that the faculty member is in | GenDoubleLinkedList<int> *advisees - a double linked list that holds the int id values for each of the Faculty member's advisees
c) @return: NA
d) no exceptions thrown
*/Faculty::Faculty(int id, string name, short rank, string specialization, GenDoubleLinkedList<int> *advisees) {
	this->id = id;
	this->name = name;
	this->rank = rank;
	this->specialization = specialization;
	this->advisees = advisees;
}

/*
a) destructor for the faculty class
b) @param: none
c) @return: NA
d) no exceptions thrown
*/
Faculty::~Faculty() {
	//nothing needs to go here
}

/*
a) Returns a complete list of Advisee ID numbers
b) @param: none
c) @return: int* - an array of int value that are the ID's of each of the Faculty member's advisees
d) no exceptions thrown
*/
int* Faculty::GetAdvisees() {
	int* adv = new int[advisees->getSize()];

	advisees->resetIterator();
	int count = 0;
	while (advisees->hasNext()) {
		adv[count++] = advisees->getNext();
	}

	return adv;
}

/*
a) Returns the number of advisees that the faculty member oversees
b) @param: none
c) @return: int - an integer value that represents the number of advisees that the faculty member has
d) no exceptions thrown
*/
int Faculty::GetAdviseeCount() {
	return advisees->getSize();
}

/*
a) Adds a single advisee to the list of advisees
b) @param: int studentID - an integer value that represents the ID of the student who is becoming an advisee to the faculty member
c) @return: void
d) no exceptions thrown
*/
void Faculty::AddAdvisee(int studentID) {
	advisees->insertBack(studentID);
}

/*
a) Adds multiple advisees to the list of advisees
b) @param: int* studentArray - an arrays of the faculty's advisee's id numbers | int sizeOfStudentArray - the size of the student array
c) @return: void
d) no exceptions thrown
*/
void Faculty::AddAdvisees(int* studentArray,int sizeOfStudentArray) {
	for (int i = 0; i < sizeOfStudentArray; ++i) {
		advisees->insertBack(studentArray[i]);
	}
}

/*
a) Removes a student from the advisee list
b) @param: int studentID - the id of the student whom you want to remove from the faculty's advisee list
c) @return: void
d) no exceptions thrown
*/
void Faculty::RemoveAdvisee(int studentID) {
	advisees->remove(studentID);
}

/*
a) accessor for rank
b) @param: none
c) @return: string - a string value representing the faculty member's rank at the university
d) no exceptions thrown
*/
string Faculty::GetRank() {
	switch (rank) {
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

/*
a) mutator for rank
b) @param: short rank - a short value representing the faculty member's rank at the university
c) @return: void
d) no exceptions thrown
*/
void Faculty::SetRank(short rank) {
	this->rank = rank;
}

/*
a) accessor for name
b) @param: none
c) @return: string - a string value representing the faculty member's name
d) no exceptions thrown
*/
string Faculty::GetName() {
	return name;
}

/*
a) accessor for ID
b) @param: none
c) @return: int - an int value representing the faculty member's ID
d) no exceptions thrown
*/
int Faculty::GetID() {
	return id;
}

//
/*
a) accessor for specialization
b) @param: none
c) @return: string - a string value representing the faculty member's department
d) no exceptions thrown
*/
string Faculty::GetSpecialization() {
	return specialization;
}

/*
a) Returns a string representation of the Faculty member in question
b) @param: none
c) @return: string - a string value representing important information in the faculty object
d) no exceptions thrown
*/
string Faculty::ToString() {
	string fac = "";
	fac += "Faculty Member: " + to_string(id) + "\n";
	fac += name + "\n";
	fac += GetRank() + " in " + GetSpecialization() + "\n";
	fac += "Advisees: ";
	advisees->resetIterator();
	while (advisees->hasNext()) {
		//cout << "Makes it into while loop" << endl;
		fac += to_string(advisees->getNext());
		if (advisees->hasNext()) {
			//cout << "if statement happens" << endl;
			fac += "\n          ";
		}
	}
	return fac;
}

/*
a) overlaoded stream insertion operator
b) @param: ostream& os - the address of an ostream, the object we use to print out the faculty member | Faculty& - the address of the faculty object that we are printing out
c) @return: ostream& os - the address of the ostream that we used to print out the faculty objecy
d) no exceptions thrown
*/
ostream& operator<<(ostream& os, Faculty& f) {
	os << f.ToString();
	//cout << "Makes it to return" << endl;
	return os;
}
