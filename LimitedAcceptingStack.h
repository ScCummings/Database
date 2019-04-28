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

template<class T>
LimitedAcceptingStack<T>::LimitedAcceptingStack() {
	stackArray = new T[128];
	maxSize = 128;
	head = -1;
	numElements = 0;
}
template<class T>
LimitedAcceptingStack<T>::LimitedAcceptingStack(int maxSize) {
	stackArray = new T[maxSize];
	this->maxSize = maxSize;
	head = -1;
	numElements = 0;
}

template<class T>
LimitedAcceptingStack<T>::~LimitedAcceptingStack() {
	delete[] stackArray;
}

template<class T>
void LimitedAcceptingStack<T>::Push(T newElement) {
	head = (head + 1) % maxSize;
	stackArray[head] = newElement;
	numElements++;
	if (numElements > 5)
		numElements = 5;
}

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

template<class T>
T LimitedAcceptingStack<T>::Peek() throw(int) {
	if (numElements = 0)
		throw 0;
	else {
		return stackArray[head];
	}
}

template<class T>
int LimitedAcceptingStack<T>::GetSize() {
	return numElements;
}

template<class T>
bool LimitedAcceptingStack<T>::IsFull() {
	return numElements == maxSize;
}

template<class T>
bool LimitedAcceptingStack<T>::IsEmpty() {
	return numElements == 0;
}

#endif //LIMITED_ACCEPTING_STACK_H