//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  4 - Registrar Simulation

#ifndef GENODOUBLE_LINKED_LIST_H
#define GENODOUBLE_LINKED_LIST_H

#include <iostream>
using namespace std;

template<class T>
class GenDoubleListNode{
    public:
        GenDoubleListNode();
        GenDoubleListNode(T d); //Overloaded constructor
        ~GenDoubleListNode();

        T data;

        GenDoubleListNode *next;
        GenDoubleListNode *prev;
};

template<class T>
GenDoubleListNode<T>::GenDoubleListNode(){
    data = nullptr;
    next = nullptr;
    prev = nullptr;
}

template<class T>
GenDoubleListNode<T>::GenDoubleListNode(T d){
    data = d;
    next = nullptr;
    prev = nullptr;
}

template<class T>
GenDoubleListNode<T>::~GenDoubleListNode(){
    next = nullptr;
    prev = nullptr;
}

template<class T>
class GenDoubleLinkedList {
    private:
        GenDoubleListNode<T> *front;
        GenDoubleListNode<T> *back;
        GenDoubleListNode<T> *currentNode;
        unsigned int size;

    public:
        //Default Constructor
        GenDoubleLinkedList();
        //Destructor
        ~GenDoubleLinkedList();

        //Inserts an object at the front of the list
        void insertFront(T d);
        //Mutatior function for front object
        void setFront(T d);
        //Accessor function for front object
        T getFront();
        //Removes the front object
        T removeFront();

        //Inserts an object at the back of the list
        void insertBack(T d);
        //Mutatior function for back object
        void setBack(T d);
        //Accessor function for back object
        T getBack();
        //Removes the back object
        T removeBack();

        //Inserts an object at the specified position of the list
        void insertPos(int pos, T d);
        //Mutator function for object at specified position
        void setPos(int pos, T d);
        //Accessor function for object at specified position
        T getPos(int pos);
        //Removes the object at the specified position
        T deletePos(int pos);

        //Removes the first instance of specified object
        int remove(T d);
        //Removes the last instance of specified object
        int removeLast(T d);
        //Finds the first instance of specified object
        int find(T d);
        //Finds the last instance of specified object
        int findLast(T d);

        //Returns the next object in the list
        T getNext();
        //Returns true if there is a next object in the iterator
        bool hasNext();
        //Resets the list iterator pointer to the front of the list
        void resetIterator();

        //Returns true if the list is empty
        bool isEmpty();
        //Returns the current size of the list
        unsigned int getSize();
        //Prints the list in array format
        void printList();

        //Swaps the objects stored at the two positions
        void swapPos(int pos1, int pos2);
        //Sorts the list in ascending order (only works for numeric types)
        void sort();
};

template<class T>
GenDoubleLinkedList<T>::GenDoubleLinkedList(){
    front = nullptr;
    back = nullptr;
    currentNode = nullptr;
    size = 0;
}
template<class T>
GenDoubleLinkedList<T>::~GenDoubleLinkedList(){
    /*if(front == nullptr)
		//don't destruct (return)
		We need to account for empty lists in the destructor (advisees list from the faculty objects)
	*/
    GenDoubleListNode<T> *curr = front;
    front = nullptr;
    back = nullptr;
    currentNode = nullptr;

    if(curr != nullptr){
        //iterate through list and delete each node
        while(curr->next != nullptr){
            curr = curr->next;
            delete curr->prev;
        }
        delete curr;
    }
}


template<class T>
void GenDoubleLinkedList<T>::insertFront(T d){
    GenDoubleListNode<T> *node = new GenDoubleListNode<T>(d);
        if(size == 0){
        front = node;
        back = node;
    }
    else{
        node->next = front;
        front->prev = node;
        front = node;
    }
    size++;
    resetIterator();
}
template<class T>
void GenDoubleLinkedList<T>::setFront(T d){
    if(size == 0){
        cerr << "Tried to mutate an element in an empty list\n";
        exit(EXIT_FAILURE);
    }

    front->data = d;
}
template<class T>
T GenDoubleLinkedList<T>::getFront(){
    if(size == 0){
        cerr << "Tried to access an element in an empty list\n";
        exit(EXIT_FAILURE);
    }

    return front->data;
}
template<class T>
T GenDoubleLinkedList<T>::removeFront(){
    if(size == 0){
        cerr << "Tried to remove from an empty list\n";
        exit(EXIT_FAILURE);
    }

    T temp = front->data;
    GenDoubleListNode<T> *ft = front;

    if(size == 1){
        front = nullptr;
        back = nullptr;
    }
    else{
        front = front->next;
        front->prev = nullptr;
    }


    ft->next = nullptr;
    delete ft;
    size--;
    resetIterator();
    return temp;
}


template<class T>
void GenDoubleLinkedList<T>::insertBack(T d){
    GenDoubleListNode<T> *node = new GenDoubleListNode<T>(d);

    //if this is the first element, set it to the front and the back
    if(size == 0){
        back = node;
        front = node;
    }
    else{
        node->prev = back;
        back->next = node;
        back = node;
    }

    resetIterator();
    size++;
}
template<class T>
void GenDoubleLinkedList<T>::setBack(T d){
    if(size == 0){
        cerr << "Tried to mutate an element in an empty list\n";
        exit(EXIT_FAILURE);
    }

    back->data = d;
}
template<class T>
T GenDoubleLinkedList<T>::getBack(){
    if(size == 0){
        cerr << "Tried to access an element in an empty list\n";
        exit(EXIT_FAILURE);
    }

    return back->data;
}
template<class T>
T GenDoubleLinkedList<T>::removeBack(){
    if(size == 0){
        cerr << "Tried to remove from an empty list\n";
        exit(EXIT_FAILURE);
    }

    T temp = back->data;
    GenDoubleListNode<T> *bt = back;
    if(size != 1){
        back = back->prev;
        back->next = nullptr;
    }
    else{
        back = nullptr;
        front = nullptr;
    }

    bt->prev = nullptr;
    delete bt;
    size--;
    resetIterator();
    return temp;

}


template<class T>
void GenDoubleLinkedList<T>::insertPos(int pos, T d){
    if(pos > size || pos < 0){
        cerr << "\nLinked List index out of bounds" << endl;
        exit(EXIT_FAILURE);
    }

    if(pos == 0){
        insertFront(d);
    }
    else if(pos == size){
        insertBack(d);
    }
    else{
        GenDoubleListNode<T> *curr = front;
        GenDoubleListNode<T> *node = new GenDoubleListNode<T>(d);

        for(int i = 0; i < pos-1; i++){
            curr = curr->next;
        }

        node->prev = curr;
        node->next = curr->next;

        curr->next->prev = node;
        curr->next = node;
    }

    resetIterator();
}
template<class T>
void GenDoubleLinkedList<T>::setPos(int pos, T d){
    if(size == 0){
        cerr << "Tried to mutate an element in an empty list\n";
        exit(EXIT_FAILURE);
    }

    if(pos >=size || pos < 0){
        cerr << "\nLinked List index out of bounds" << endl;
        exit(EXIT_FAILURE);
    }

    if(pos == 0){
        front->data = d;
        return;
    }
    else if(pos == size-1){
        back->data = d;
        return;
    }

    GenDoubleListNode<T> *curr = front;

    for(int i = 0; i < pos; i++){
        curr = curr->next;
    }

    curr->data = d;
}
template<class T>
T GenDoubleLinkedList<T>::getPos(int pos){
    if(size == 0){
        cerr << "Tried to access an element in an empty list\n";
        exit(EXIT_FAILURE);
    }

    if(pos >=size || pos < 0){
        cerr << "\nLinked List index out of bounds" << endl;
        exit(EXIT_FAILURE);
    }

    if(pos == 0){
        return front->data;
    }
    else if(pos == size-1){
        return back->data;
    }

    GenDoubleListNode<T> *curr = front;

    for(int i = 0; i < pos; i++){
        curr = curr->next;
    }

    return curr->data;
}
template<class T>
T GenDoubleLinkedList<T>::deletePos(int pos){
    if(size == 0){
        cerr << "Tried to remove from an empty list\n";
        exit(EXIT_FAILURE);
    }

    if(pos == 0){
        return removeFront();
    }
    else if(pos == size-1){
        return removeBack();
    }
    else if(pos >=size || pos < 0){
        cerr << "\nLinked List index out of bounds" << endl;
        exit(EXIT_FAILURE);
    }

    GenDoubleListNode<T> *atPos = front;
    GenDoubleListNode<T> *beforePos;
    GenDoubleListNode<T> *afterPos;

    for(int i = 0; i < pos; i++){
        atPos = atPos->next;
        beforePos = atPos->prev;
        afterPos = atPos->next;
    }

    beforePos->next = afterPos;
    afterPos->prev = beforePos;

    T temp = atPos->data;
    atPos->next = nullptr;
    atPos->prev = nullptr;
    delete atPos;

    size--;
    resetIterator();
    return temp;

}


template<class T>
int GenDoubleLinkedList<T>::find(T d){
    if(size == 0){
        cerr << "Tried to access an element in an empty list\n";
        exit(EXIT_FAILURE);
    }

    GenDoubleListNode<T> *curr = front;
    int index = -1;

    while(curr != nullptr){
        index++;
        if(curr->data == d){
            break;
        }
        else{
            curr = curr->next;
        }
    }

    if(curr == nullptr){ //d doens't exits in the list
        index = -1;
    }

    return index;
}
template<class T>
int GenDoubleLinkedList<T>::findLast(T d){
    if(size == 0){
        cerr << "Tried to access an element in an empty list\n";
        exit(EXIT_FAILURE);
    }

    GenDoubleListNode<T> *curr = back;
    int index = size;

    while(curr != nullptr){
        index--;
        if(curr->data == d){
            break;
        }
        else{
            curr = curr->prev;
        }
    }

    if(curr == nullptr){
        index = -1;
    }

    return index;
}
template<class T>
int GenDoubleLinkedList<T>::remove(T d){
    if(size == 0){
        cerr << "Tried to remove from an empty list\n";
        exit(EXIT_FAILURE);
    }

    int pos = find(d);
    deletePos(pos);
    return pos;
}
template<class T>
int GenDoubleLinkedList<T>::removeLast(T d){
    if(size == 0){
        cerr << "Tried to remove from an empty list\n";
        exit(EXIT_FAILURE);
    }

    int pos = findLast(d);
    deletePos(pos);
    return pos;
}


template<class T>
T GenDoubleLinkedList<T>::getNext(){
    if(currentNode == nullptr){
        cerr << "Tried to access nonexistant next element\n";
        exit(EXIT_FAILURE);
    }
    T temp = currentNode->data;
    currentNode = currentNode->next;
    return temp;
}
template<class T>
bool GenDoubleLinkedList<T>::hasNext(){
    return currentNode != nullptr;
}
template<class T>
void GenDoubleLinkedList<T>::resetIterator(){
    currentNode = front;
}


template<class T>
bool GenDoubleLinkedList<T>::isEmpty(){
    return size == 0;
}
template<class T>
unsigned int GenDoubleLinkedList<T>::getSize(){
    return size;
}
template<class T>
void GenDoubleLinkedList<T>::printList(){
    if(size == 0){
        cout << "[]" << endl;
        return;
    }
    GenDoubleListNode<T> *curr = front;
    cout << "[";
    while(curr->next != nullptr){
        cout << curr->data << ", ";
        curr = curr->next;
    }
    cout << curr->data << "]" << endl;
}

template<class T>
void GenDoubleLinkedList<T>::swapPos(int pos1, int pos2){
    T temp = getPos(pos1);
    setPos(pos1, getPos(pos2));
    setPos(pos2, temp);
}
template<class T>
void GenDoubleLinkedList<T>::sort(){
    //bubble sort
    for(int i = 0; i < size-1; i++){
        bool swapped = false;
        for(int j = 0; j < size-i-1; j++){
            if(getPos(j) > getPos(j+1)){
                swapPos(j, j+1);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

#endif //GENODOUBLE_LINKED_LIST_H
