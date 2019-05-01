#include <iostream>
#include <string>
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
#include "GenDoubleLinkedList.h"
using namespace std;


int main(){
    string someString = "{\"id\":1,\"name\":\"Queenie\",\"rank\":2,\"specialization\":\"Sci\",\"GPA\":4.0,\"advisorID\":4432}";
    string someStringF = "{\"id\":4432,\"name\":\"Urdu\",\"rank\":0,\"specialization\":\"Queso Studies\",\"advisees\":[]}";


    Student bitchface = Student::Unserialize(someString);
    cout << bitchface << endl << endl;
    cout << "someString:  " << someString << endl;
    cout << "bitchface.:  " << bitchface.Serialize() << endl << endl;
    cout << "**********************************" << endl << endl;
    Faculty someFaculty = Faculty::Unserialize(someStringF);
    cout << someFaculty << endl << endl;
    cout << "someStringF:  " << someStringF << endl;
    cout << "someFaculty:  " << someFaculty.Serialize() << endl << endl;
    return 0;
}