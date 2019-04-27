#ifndef GEN_TREE_H
#define GEN_TREE_H

#include <iostream>
using namespace std;

template<class T>
class TreeNode{
    public:
        TreeNode();
        TreeNode(T k);
        virtual ~TreeNode();//why a virtual destructor?

        T key;
        TreeNode<T> *left;
        TreeNode<T> *right;
};


//////Implementation///////

template<class T>
TreeNode<T>::TreeNode(){
    left = nullptr;
    right = nullptr;
}

template<class T>
TreeNode<T>::TreeNode(T k){
    key = k;
    left = nullptr;
    right = nullptr;
}

template<class T>
TreeNode<T>::~TreeNode(){
    left = nullptr;
    right = nullptr;
}


/////let's define our tree class/////

template<class T>
class BST{
    public:
        BST();
        virtual ~BST();
        void insert(T value);
        bool contains(T value); //AKA search
        T* Find(T *value);
        bool deleteR(T key);
        TreeNode<T>* getSuccessor(TreeNode<T> *d);

        TreeNode<T>* getMin();
        TreeNode<T>* getMax();
        bool isEmpty();
        void printTree();
        void recPrint(TreeNode<T> *node);
        void recPrint();
        TreeNode<T>* GetRoot();
        /*
        void printPre();
        void printPre(TreeNode<T> *node);
        void printPre(TreeNode<T> *node, int level);*/

    private:
        void destructRecursive(TreeNode<T> *node);
        TreeNode<T>* root;
};


/////implement this bad boy/////

//Default
template<class T>
BST<T>::BST(){
    root = nullptr;
}

template<class T>
BST<T>::~BST(){
    cout << "Makes it into the destructor" << endl;
    destructRecursive(root);
    cout << "Makes it past destructRecursive" << endl;
}

template<class T>
void BST<T>::destructRecursive(TreeNode<T> *node){
    if(node != nullptr){
        destructRecursive(node->left);
        destructRecursive(node->right);
        delete node;
    }
}

template<class T>
void BST<T>::printTree(){
    recPrint(root);
}

template<class T>
void BST<T>::recPrint(TreeNode<T> *node){
    cout << "makes it into recPrint" << endl;
    if(node == nullptr){
        cout << "node is null" << endl;
        return;
    }
    else{
        cout << "node is not null" << endl;
        recPrint(node->left);
        cout << node->key << endl;
        recPrint(node->right);
    }
}

//overloaded recPrint function that calls from the root
template<class T>
void BST<T>::recPrint(){
    recPrint(root);
}
template<class T>
bool BST<T>::isEmpty(){
    return (root == nullptr);
}

template<class T>
void BST<T>::insert(T value){
    //check if value exists, if not continue

    TreeNode<T> *node = new TreeNode<T>(value); //key is now set to value

    if(isEmpty()){ //empty tree
        root = node;
    }
    else{  //not empty need to find insertion point
        TreeNode<T> *current = root; //keep track of where we are
        TreeNode<T> *parent = nullptr; //keep track of where we've been

        while(true){
            parent = current;

            if(value < current->key){
                current = current->left; //going left

                if(current == nullptr){ //we found a home for new node
                    parent->left = node;
                    break;
                }
                //otherwise it'll keep looping
            }
            else{
                current = current->right; //going right

                if(current == nullptr){
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template<class T>
bool BST<T>::contains(T value){
    if(isEmpty()){
        return false;
    }
    else{ //not an empty tree
        TreeNode<T> *current = root;

        while(current->key != value){
            if(value < current->key)
                current = current->left;
            else
                current = current->right;

            if(current == nullptr) //we didn't find it :(
                return false;
        }
    }
    return true;
}

template<class T>
bool BST<T>::deleteR(T key){
    if(isEmpty())
        return false;

    if(!contains(key))
        return false;

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while(current->key != key){
        parent = current;

        if(key < current->key){
            isLeft = true;
            current = current->left;
        }
        else //right child
        {
            isLeft = false;
            current = current->right;
        }

        if(current == nullptr)
            return false;
    }

    //at this point we found our node
    //now lets check our cases

    if(current->left == nullptr && current->right == nullptr){
        if(current == root)
            root = nullptr;
        else if(isLeft){
            parent->left = nullptr;
            //delete current; check this!
        }
        else{ //right child
            parent->right = nullptr;
            //delete current; check this!
        }
    }

    //check for nodes with one child
    else if(current->right == nullptr){ // current has a left child
        if(current == root){
            root = current->left;
        }
        else if(isLeft){
            parent->left = current->left;
        }
        else{ //right child
            parent->right = current->left;
        }
    }
    else if(current->left == nullptr){ // current has a right child
        if(current == root){
            root = current->right;
        }
        else if(isLeft){
            parent->left = current->right;
        }
        else{ //right child
            parent->right = current->right;
        }
    }

    //node has two children!
    else{
        //find the successor of the node to be deleted (current)
        TreeNode<T> *successor = getSuccessor(current);

        if(current == root){
            root = successor;
        }
        else if(isLeft){
            parent->left = successor;
        }
        else{ // right child
            parent->right = successor;
        }

        successor->left = current->left;
    }

    return true;
}

template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){ //d is the node to be deleted
    //we want the smallest larger than d
    TreeNode<T> *sp = d; //successor's parent
    TreeNode<T> *successor = d; //
    TreeNode<T> *current = d->right;

    while(current != nullptr){
        sp = successor;
        successor = current;
        current = current->left;
    }

    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }

    return successor;

}

template<class T>
T* BST<T>::Find(T *value){
    if(isEmpty()){
        cout << "Sorry, the tree is empty." << endl;
        return nullptr;
    }
    else{ //not an empty tree
        TreeNode<T> *current = root;

        while(current->key != (*value)){
            if((*value) < current->key)
                current = current->left;
            else
                current = current->right;

            if(current == nullptr) //we didn't find it :(
                cout << "Value was not found." << endl;
                return nullptr;
        }

        T *returnT = &current->key;

        return returnT;
    }
}

//GetRoot function for the addStudent function in Database
template<class T>
TreeNode<T>* BST<T>::GetRoot(){
    return root;
}
//getMax and getMin to be added

#endif //GEN_TREE_H
