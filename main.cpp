#include "GenTree.h"
#include "Faculty.h"
#include "Person.h"
#include "Student.h"
#include <iostream>

using namespace std;

int main(){
<<<<<<< HEAD

    /*BST<Person> *StudentTree = new BST<Person>();

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

    Faculty f0(4432, "Name", 0, "N/A");
=======
    Faculty f0(4432, "Name Bitchface", 0, "Bitching");
>>>>>>> 394fecaffce5bc1a960194d394edbcb7949de1a9
    Faculty f1(6653, "Name", 0, "N/A");
    Faculty f2(5433, "Name", 0, "N/A");
    Faculty f3(1425, "Name", 0, "N/A");
    Faculty f4(6546, "Name", 0, "N/A");
    Faculty f5(2434, "Name", 0, "N/A");
    Faculty f6(1432, "Name", 0, "N/A");
    Faculty f7(5532, "Name", 0, "N/A");
    Faculty f8(4432, "Name", 0, "N/A");
    Faculty f9(1123, "Name", 0, "N/A");

    cout << "Equals (1):  " << (f0 == f8) << endl;
    cout << "Equals (0):  " << (f9 == f8) << endl;

    cout << "Greater (1)  " << (f1 > f2) << endl;
    cout << "Greater (0)  " << (f3 > f2) << endl;

    cout << "Lesser (1)   " << (f5 < f4) << endl;
    cout << "Lesser (0)   " << (f6 < f9) << endl;

    f0.AddAdvisee(234423);
    f0.AddAdvisee(543523);
    f0.AddAdvisee(243465);
    f0.AddAdvisee(987967);

    cout << f0 << endl;*/
    Student Queenie(1234,4.0,1,"Queenie",2,"Enviornmental Science");
    Student Wardu(1234,3.9,2,"Wardu",0,"Integrated Educational Studies");
    Student Earnie(1234,3.8,1,"Earnie",1,"Psychology");
    Student Ricardo(1234,3.7,3,"Ricardo",2,"Applied Physics");
    Student Tracy(1234,3.6,2,"Tracy",1,"German Language and Culture");

    cout << Queenie.GetName() << endl;
    cout << Wardu.GetAdvisorID() << endl;
    cout << Earnie.GetGPA() << endl;
    cout << Ricardo.GetID() << endl;
    cout << Tracy.GetSpecialization() << endl;

    return 0;
}

// BST<char> *b = new BST<char>();

// b->insert('G');
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

// b->printPre();
// b->deleteR('G');
// cout << endl;

// b->printPre();
// b->deleteR('L');
// cout << endl;

// b->printPre();
// b->deleteR('0');
// cout << endl;

// b->printPre();

// cout << b->contains('L') << endl;
// cout << b->contains('z') << endl;
// cout << b->contains('=') << endl;

// cout << b->getMax() << endl;
// cout << b->getMin() << endl;
