#include "GenTree.h"
#include "Faculty.h"
#include "Person.h"
#include "Student.h"
#include <iostream>

using namespace std;

int main(){


    BST<Student> *StudentTree = new BST<Student>();

    //Make a bunch of Students
    Student Queenie(1234,4.0,1,"Queenie",2,"Enviornmental Science");
    Student Wardu(1234,3.9,2,"Wardu",0,"Integrated Educational Studies");
    Student Earnie(1234,3.8,1,"Earnie",1,"Psychology");
    Student Ricardo(1234,3.7,3,"Ricardo",2,"Applied Physics");
    Student Tracy(1234,3.6,2,"Tracy",1,"German Language and Culture");

    //Insert the students into the StudentTree
    StudentTree->insert(Queenie);
    StudentTree->insert(Wardu);
    StudentTree->insert(Earnie);
    StudentTree->insert(Ricardo);
    StudentTree->insert(Tracy);
    //b->insert('G');
    // b->insert('5');
    // b->insert('v');
    // b->insert('0');
    // b->insert('L');
    // b->insert('a');
    // b->insert('q');
    // b->insert('+');
    // b->insert('!');
    // b->insert('$');
    // b->insert('2');
    // b->insert('^');
    // b->insert('?');
    // b->insert(' ');
    // b->insert('=');
    // b->insert('l');

    StudentTree->printPre();
    StudentTree->deleteR(Queenie);
    cout << endl;

    StudentTree->printPre();
    StudentTree->deleteR(Wardu);
    cout << endl;

    StudentTree->printPre();
    StudentTree->deleteR(Earnie);
    cout << endl;

    StudentTree->printPre();

    cout << StudentTree->contains(Ricardo) << endl;
    cout << StudentTree->contains(Tracy) << endl;

    cout << StudentTree->getMax() << endl;
    cout << StudentTree->getMin() << endl;




    return 0;
}
