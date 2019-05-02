//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Name:  Scott Cummings
//Student ID#:  2317991
//Chapman Email:  scummings@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  5 - School Database

#ifndef LIMITED_ACCEPTING_STACK_H
#define LIMITED_ACCEPTING_STACK_H

#include <iostream>

using namespace std;

template<class T>
class LimitedAcceptingStack {
public:
	//Default Constructor: Max Size will be 128
	LimitedAcceptingStack();

	//Overloaded Constructor: Max Size chosen by parameter
	LimitedAcceptingStack(int maxSize);

	//Destructor
	~LimitedAcceptingStack();

	//Adds a new element to the stack.
	//If the stack is full, the first
	//inserted element is deleted
	void Push(T newElement);

	//Removes the top element of the stack and returns it
	T Pop() throw(int);

	//Returns the top element of the stack without removing it
	T Peek() throw(int);

	//Returns the current number of elements stored in the stack
	int GetSize();

	//Returns true if the number of elements contained in the stack
	//is equivilant to the maximum size of the stack
	bool IsFull();

	//Returns true if no elements are contained in the stack
	bool IsEmpty();

private:
	int head;
	int maxSize;
	int numElements;

	T* stackArray;
};

/*
a) Default Constructor: Max Size will be 128
b) @param: none
c) @return: NA
d) no exceptions thrown
*/
template<class T>
LimitedAcceptingStack<T>::LimitedAcceptingStack() {
	stackArray = new T[128];
	maxSize = 128;
	head = -1;
	numElements = 0;
}

/*
a) Overloaded Constructor: Max Size chosen by parameter
b) @param: int maxSize - the max size that the LimitedAcceptingStack can have
c) @return: NA
d) no exceptions thrown
*/
template<class T>
LimitedAcceptingStack<T>::LimitedAcceptingStack(int maxSize) {
	stackArray = new T[maxSize];
	this->maxSize = maxSize;
	head = -1;
	numElements = 0;
}

/*
a) LimitedAcceptingStack destructor
b) @param: none
c) @return: NA
d) no exceptions thrown
*/
template<class T>
LimitedAcceptingStack<T>::~LimitedAcceptingStack() {
	delete[] stackArray;
}

/*
a) a function for adding a new T object to the LimitedAcceptingStack
b) @param: T newElement - the new object that you wish to add to the LimitedAcceptingStack
c) @return: void
d) no exceptions thrown
*/
template<class T>
void LimitedAcceptingStack<T>::Push(T newElement) {
	head = (head + 1) % maxSize;
	stackArray[head] = newElement;
	numElements++;
	if (numElements > 5){
        numElements = 5;
    }
}

/*
a) removes the head of the funtion and then moves the head back, like a heap
b) @param: none
c) @return: T - the T object removed from the LimitedAcceptingStack
d) int error may be thrown
*/
template<class T>
T LimitedAcceptingStack<T>::Pop() throw(int) {
	if (numElements == 0)
		throw 0;
	else {
		T temp = stackArray[head];
		head--;
		if (head == -1)
			head = maxSize - 1;
		numElements--;
		return temp;
	}
}

/*
a) shows the head of the LimitedAcceptingStack
b) @param: none
c) @return: T - the head of the LimitedAcceptingStack
d) int error may be thrown
*/
template<class T>
T LimitedAcceptingStack<T>::Peek() throw(int) {
	if (numElements = 0)
		throw 0;
	else {
		return stackArray[head];
	}
}

/*
a) size accessor function
b) @param: none
c) @return: int - an int value that represents the size of the LimitedAcceptingStack
d) no exceptions thrown
*/
template<class T>
int LimitedAcceptingStack<T>::GetSize() {
	return numElements;
}

/*
a) a function that determines whether or not the LimitedAcceptingStack is Full
b) @param: none
c) @return: bool - whether or not the LimitedAcceptingStack is Full
d) no exceptions thrown
*/
template<class T>
bool LimitedAcceptingStack<T>::IsFull() {
	return numElements == maxSize;
}

/*
a) a function that determines whther or not the LimitedAcceptingStack is empty
b) @param: none
c) @return: bool - whether or not the LimitedAcceptingStack is empty
d) no exceptions thrown
*/
template<class T>
bool LimitedAcceptingStack<T>::IsEmpty() {
	return numElements == 0;
}

#endif //LIMITED_ACCEPTING_STACK_H