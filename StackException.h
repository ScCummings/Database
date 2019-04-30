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