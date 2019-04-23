#include "GenTree.h"
#include <iostream>

int main(){
    BST<char> *b = new BST<char>();

    b->insert('G');
    b->insert('5');
    b->insert('v');
    b->insert('0');
    b->insert('L');
    b->insert('a');
    b->insert('q');
    b->insert('+');
    b->insert('!');
    b->insert('$');
    b->insert('2');
    b->insert('^');
    b->insert('?');
    b->insert(' ');
    b->insert('=');
    b->insert('l');

    b->printPre();
    b->deleteR('G');
    cout << endl;

    b->printPre();
    b->deleteR('L');
    cout << endl;

    b->printPre();
    b->deleteR('0');
    cout << endl;

    b->printPre();

    cout << b->contains('L') << endl;
    cout << b->contains('z') << endl;
    cout << b->contains('=') << endl;

    cout << b->getMax() << endl;
    cout << b->getMin() << endl;




    return 0;
}