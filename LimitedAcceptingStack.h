#ifndef LIMITED_ACCEPTING_STACK_H
#define LIMITED_ACCEPTING_STACK_H



template<class T>
public class LimitedAcceptingStack{
    public:
        //Default Constructor: Max Size will be 128
        LimitedAccpetingStack();

        //Overloaded Constructor: Max Size chosen by parameter
        LimitedAccpetingStack(int maxSize);

        //Destructor
        ~LimitedAccpetingStack();

        //Adds a new element to the stack.
        //If the stack is full, the first
        //inserted element is deleted
        void Push(T newElement);

        //Removes the top element of the stack and returns it
        T Pop();

        //Returns the top element of the stack without removing it
        T Peek();

        //Returns the current number of elements stored in the stack
        int GetSize();

        //Returns true if the number of elements contained in the stack
        //is equivilant to the maximum size of the stack
        bool IsFull();

        //Returns true if no elements are contained in the stack
        bool IsEmpty();
    
    private:
        int head;
        int tail;
        int maxSize;
        int numElements;

        T* stackArray;
}

template<class T>
LimitedAcceptingStack<T>::LimitedAcceptingStack(){
    stackArray = new T[128];
    maxSize = 128;
    head = 0;
    tail = -1;
    numElements = 0;
}
template<class T>
LimitedAcceptingStack<T>::LimitedAcceptingStack(int maxSize){
    stackArray = new T[maxSize];
    this->maxSize = maxSize;
    head = 0;
    tail = -1;
    numElements = 0;
}

template<class T>
LimitedAcceptingStack<T>::~LimitedAccpetingStack(){
    delete[] stackArray;
}

template<class T>
void LimitedAcceptingStack<T>::Push(T newElement){

}

template<class T>
T LimitedAcceptingStack<T>::Pop(){

}

template<class T>
T LimitedAcceptingStack<T>::Peek(){

}

template<class T>
int LimitedAcceptingStack<T>::GetSize(){

}

template<class T>
bool LimitedAcceptingStack<T>::
#endif //LIMITED_ACCEPTING_STACK_H