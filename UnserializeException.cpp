#include "UnserializeException.h"

UnserializeException::UnserializeException(){
    message = "Unserializeation of object failed: invalid input string";
}

UnserializeException::UnserializeException(string message){
    this->message = message;
}

string UnserializeException::GetMessage(){
    return message;
}

