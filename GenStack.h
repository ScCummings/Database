//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Name:  Scott Cummings
//Student ID#:  2317991
//Chapman Email:  scummings@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  5 - School Database

#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include "StackException.h"
using namespace std;

template<class T>
class GenStack{
    public:
        //Default Constructor: array initialzies to 128 elements
        GenStack(); 

        //Overloaded Constructor: array initialzies to passed number of elements
        GenStack(int maxSize);

        //Default Destructor
        ~GenStack();

        //Puts a new element on the top of the stack
        void push(T d) throw (StackException);

        //Takes an element off the top of the stack and returns it
        T pop() throw (StackException);

        //Returns an element off the top of the stack without removing it
        T peek() throw (StackException);

        //Returns the number of elements in the stack
        int getSize();

        //Returns true if the number of elements in the stack is equal to the max size
        bool isFull();

        //Returns true if there are no elements in the stack
        bool isEmpty();

    private:
        int size;
        int top;

        T *myArray;
};

//Default Constructor: array initialzies to 128 elements
template<class T>
GenStack<T>::GenStack(){
    myArray = new T[128];
    size = 128;
    top = -1;
}

//Overloaded Constructor: array initialzies to passed number of elements
template<class T>
GenStack<T>::GenStack(int maxSize){
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
}

//Default Destructor
template<class T>
GenStack<T>::~GenStack(){
    delete[] myArray;
}

//Puts a new element on the top of the stack
template<class T>
void GenStack<T>::push(T d) throw (StackException){
    if(isFull()){
        throw StackException("Stack Array full: tried to push to full stack");
    }
    myArray[++top] = d;
}

//Takes an element off the top of the stack and returns it
template<class T>
T GenStack<T>::pop() throw (StackException){
    if(isEmpty()){
        throw StackException("Stack Array empty: tried to pop from empty stack");
    }

    return myArray[top--];
}

//Returns an element off the top of the stack without removing it
template<class T>
T GenStack<T>::peek() throw (StackException){
    if(isEmpty()){
        throw StackException("Stack Array empty: tried to peek from empty stack");
    }

    return myArray[top];
}

//Returns the number of elements in the stack
template<class T>
int GenStack<T>::getSize(){
    return top+1;
}

//Returns true if the number of elements in the stack is equal to the max size
template<class T>
bool GenStack<T>::isFull(){
    return (top == size-1);
}

//Returns true if there are no elements in the stack
template<class T>
bool GenStack<T>::isEmpty(){
    return (top == -1);
}

#endif //GENSTACK_H