//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Name:  Scott Cummings
//Student ID#:  2317991
//Chapman Email:  scummings@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  5 - School Database

#ifndef STACK_EXCEPTION_H
#define STACK_EXCEPTION_H

#include <iostream>
using namespace std;

class StackException{
    public:
        //default constructor with message "Stack Exception"
        StackException();

        //overloaded constructor with specific message
        StackException(string m);

        //returns the exception message
        string GetMessage();
    private:
        //stores the message
        string message;
};

#endif //STACK_EXCEPTION_H