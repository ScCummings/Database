// #include "GenTree.h"
// #include "Faculty.h"
// #include "Person.h"
// #include "Student.h"
#include "Database.h"
#include <iostream>

void TestScott();
//void TestDan();

int main(){
    //TestScott();

    cout << endl << endl;
    cout << "========================";
    cout << endl << endl;

    //TestDan();

    return 0;
}


void TestScott(){
    BST<Student> *StudentTree = new BST<Student>();
    BST<Faculty> *FacultyTree = new BST<Faculty>()
    cout << "makes it into test" << endl;
    //Make a bunch of Students
    Student Queenie(1234,4.0,1,"Queenie",2,"Enviornmental Science");
    cout << Queenie << endl;
    Student Wardu(1234,3.9,2,"Wardu",0,"Integrated Educational Studies");
    Student Earnie(1234,3.8,1,"Earnie",1,"Psychology");
    Student Ricardo(1234,3.7,3,"Ricardo",2,"Applied Physics");
    Student Tracy(1234,3.6,2,"Tracy",1,"German Language and Culture");
    cout << "Makes all the students" << endl;
    //Insert the students into the StudentTree
    StudentTree->insert(Queenie);
    StudentTree->insert(Wardu);
    StudentTree->insert(Earnie);
    StudentTree->insert(Ricardo);
    StudentTree->insert(Tracy);

    //cout << StudentTree->getMax() << endl;
    //cout << StudentTree->getMin() << endl;

    Faculty f0(4432, "Name", 0, "N/A");
    Faculty f1(6653, "Name", 0, "N/A");
    Faculty f2(5433, "Name", 0, "N/A");
    Faculty f3(1425, "Name", 0, "N/A");
    Faculty f4(6546, "Name", 0, "N/A");
    Faculty f5(2434, "Name", 0, "N/A");
    Faculty f6(1432, "Name", 0, "N/A");
    Faculty f7(5532, "Name", 0, "N/A");
    Faculty f8(4432, "Name", 0, "N/A");
    Faculty f9(1123, "Name", 0, "N/A");
    //insert each of the faculty objects into the FacultyTree
    FacultyTree->insert(f0);
    FacultyTree->insert(f1);
    FacultyTree->insert(f2);
    FacultyTree->insert(f3);
    FacultyTree->insert(f4);
    FacultyTree->insert(f5);
    FacultyTree->insert(f6);
    FacultyTree->insert(f7);
    FacultyTree->insert(f8);
    FacultyTree->insert(f9);

    f0.AddAdvisee(234423);
    f0.AddAdvisee(543523);
    f0.AddAdvisee(243465);
    f0.AddAdvisee(987967);

    cout << f0 << endl;
    /*Student Queenie(1234,4.0,1,"Queenie",2,"Enviornmental Science");
    Student Wardu(1234,3.9,2,"Wardu",0,"Integrated Educational Studies");
    Student Earnie(1234,3.8,1,"Earnie",1,"Psychology");
    Student Ricardo(1234,3.7,3,"Ricardo",2,"Applied Physics");
    Student Tracy(1234,3.6,2,"Tracy",1,"German Language and Culture");*/
    Database d = new Database()

}

/*void TestDan(){
    Faculty f0(4432, "Albert Einstein", 5, "Physics");
    Faculty f1(6653, "Name", 0, "N/A");
    Faculty f2(5433, "Name", 0, "N/A");
    Faculty f3(1425, "Name", 0, "N/A");
    Faculty f4(6546, "Name", 0, "N/A");
    Faculty f5(2434, "Name", 0, "N/A");
    Faculty f6(1432, "Name", 0, "N/A");
    Faculty f7(5532, "Name", 0, "N/A");
    Faculty f8(4432, "Name", 0, "N/A");
    Faculty f9(1123, "Name", 0, "N/A");

    // cout << "Equals (1):  " << (f0 == f8) << endl;
    // cout << "Equals (0):  " << (f9 == f8) << endl;

    // cout << "Greater (1)  " << (f1 > f2) << endl;
    // cout << "Greater (0)  " << (f3 > f2) << endl;

    // cout << "Lesser (1)   " << (f5 < f4) << endl;
    // cout << "Lesser (0)   " << (f6 < f9) << endl;

    // f0.AddAdvisee(234423);
    // f0.AddAdvisee(543523);
    // f0.AddAdvisee(243465);
    // f0.AddAdvisee(987967);

    // cout << f0 << endl;

    // f0.RemoveAdvisee(543523);

    // cout << f0 << endl;

    // int* haha = f0.GetAdvisees();

    // int count = f0.GetAdviseeCount();

    for(int i = 0; i < count; i++){
        cout << haha[i] << endl;
    }*/

    //BST<char> *b = new BST<char>();

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
//}
