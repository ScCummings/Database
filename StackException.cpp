#include "StackException.h"
#include <iostream>
using namespace std;

//default constructor with message "Stack Exception"
StackException::StackException(){
    message = "Stack Exception";
}

//overloaded constructor with specific message
StackException::StackException(string m){
    message = m;
}

//returns the exception message
string StackException::GetMessage(){
    return message;
}