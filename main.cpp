#include "GenTree.h"
#include "Faculty.h"
#include "Person.h"
#include <iostream>

using namespace std;

int main(){
    Faculty f0(4432, "Name Bitchface", 0, "Bitching");
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

    cout << f0 << endl;


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
