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
    //let's do a little research (that means us)  :(
}



/////let's define our tree class/////

template<class T>
class BST{
    public:
        BST();
        virtual ~BST();
        void insert(T value);
        bool contains(T value); //AKA search
        bool deleteR(T key);
        TreeNode<T>* getSuccessor(TreeNode<T> *d);

        TreeNode<T>* getMin();
        TreeNode<T>* getMax();
        bool isEmpty();
        void printTree();
        void recPrint(TreeNode<T> *node);
        void printPre();
        void printPre(TreeNode<T> *node);
        void printPre(TreeNode<T> *node, int level);

    private:
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
    //iterate and delete
    //lets put on our research hats
}

template<class T>
void BST<T>::printTree(){
    recPrint(root);
}

template<class T>
void BST<T>::printPre(){
    printPre(root, 0);
}

template<class T>
void BST<T>::printPre(TreeNode<T> *node){
    printPre(node, 0);
}

template<class T>
void BST<T>::printPre(TreeNode<T> *node, int level){
    if(node == nullptr){
        return;
    }
    else{
        printPre(node->right, level+1);
        for(int i = 0; i < level; i++){
            cout << "   |";
        }
        cout << node->key << endl;

        printPre(node->left, level+1);
    }
}

template<class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if(node == nullptr){
        return;
    }
    else{
        recPrint(node->left);
        cout << node->key << endl;
        recPrint(node->right);
    }
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

#endif //GEN_TREE_H
