//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Name:  Scott Cummings
//Student ID#:  2317991
//Chapman Email:  scummings@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  5 - School Database

#ifndef GEN_TREE_H
#define GEN_TREE_H

#include <iostream>
using namespace std;

template<class T>
class TreeNode {
public:
	TreeNode();
	TreeNode(T k);
	virtual ~TreeNode();//why a virtual destructor?

	T key;
	TreeNode<T> *left;
	TreeNode<T> *right;
};


//////Implementation///////
/*
a) tree node constructor
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
template<class T>
TreeNode<T>::TreeNode() {
	left = nullptr;
	right = nullptr;
}
/*
a) overloaded TreeNode constructor that passes in a T object to place as the data of the Node
b) @param: T k - a T object (faculty or student) that gets set as the data of the TreeNode
c) @return: NA
d) no exceptions thrown
*/
template<class T>
TreeNode<T>::TreeNode(T k) {
	key = k;
	left = nullptr;
	right = nullptr;
}
/*
a) TreeNode destructor function
b) @param: None
c) @return: NA
d) no exceptions thrown
*/
template<class T>
TreeNode<T>::~TreeNode() {
	left = nullptr;
	right = nullptr;
}


/////let's define our tree class/////

template<class T>
class BST {
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



/*
a) constructor for the BST class
b) @param: None
c) @return: NA
d) no exceptions thrown
*/
template<class T>
BST<T>::BST() {
	root = nullptr;
}
/*
a) destructor for the BST class
b) @param: None
c) @return: NA
d) no exceptions thrown
*/
template<class T>
BST<T>::~BST() {
	destructRecursive(root);
}
/*
a) Recursively destructs the BST
b) @param: TreeNode<T>* node - the node that is the root of the BST that we want to destroy
c) @return: void
d) no exceptions thrown
*/
template<class T>
void BST<T>::destructRecursive(TreeNode<T> *node) {
	if (node != nullptr) {
		//while the node exists, do a postorder traversal and delete the tree(from the root)
		destructRecursive(node->left);
		destructRecursive(node->right);
		delete node;
	}
}
/*
a) function that prints the BST using the recPrint function
b) @param: None
c) @return: void
d) no exceptions thrown
*/
template<class T>
void BST<T>::printTree() {
	recPrint(root);
}
/*
a) a function that recursively prints each of the nodes in the BST
b) @param: TreeNode<T> *node - the TreeNode that is the root of the tree we would like to print
c) @return: void
d) no exceptions thrown
*/
template<class T>
void BST<T>::recPrint(TreeNode<T> *node) {
	if (node == nullptr) {
		//if the node doesnt exist, break
		return;
	}
	else {
		//inorder traversal of the tree to recursively print
		recPrint(node->left);
		cout << node->key << endl << endl;
		recPrint(node->right);
	}
}


/*
a) overloaded recPrint function that calls from the root
b) @param: None
c) @return: void
d) no exceptions thrown
*/
template<class T>
void BST<T>::recPrint() {
	recPrint(root);
}

/*
a) funtion that returns whether or not the BST is empty
b) @param: None
c) @return: bool - whether or not the BST is empty
d) no exceptions thrown
*/
template<class T>
bool BST<T>::isEmpty() {
	return (root == nullptr);
}
/*
a) function that inserts a new T value and TreeNode into the BST
b) @param: T value - the data of the new node
c) @return: void
d) no exceptions thrown
*/
template<class T>
void BST<T>::insert(T value) {
	//check if value exists, if not continue

	TreeNode<T> *node = new TreeNode<T>(value); //key is now set to value

	if (isEmpty()) { //empty tree
		root = node;
	}
	else {  //not empty need to find insertion point
		TreeNode<T> *current = root; //keep track of where we are
		TreeNode<T> *parent = nullptr; //keep track of where we've been

		while (true) {
			parent = current;

			if (value < current->key) {
				current = current->left; //going left

				if (current == nullptr) { //we found a home for new node
					parent->left = node;
					break;
				}
				//otherwise it'll keep looping
			}
			else {
				current = current->right; //going right

				if (current == nullptr) {
					parent->right = node;
					break;
				}
			}
		}
	}
}
/*
a) function that determines whether or not a BST contains the T value within one of its TreeNodes
b) @param: T value - the data that we are searching for
c) @return: bool - whether or not the BST contains the T value
d) no exceptions thrown
*/
template<class T>
bool BST<T>::contains(T value) {
	if (isEmpty()) {
		return false;
	}
	else { //not an empty tree
		TreeNode<T> *current = root;

		while (current->key != value) {
			//while the key isnt the value (we haven't gotten to it yet)
			if (value < current->key)
				current = current->left;
			else
				current = current->right;

			if (current == nullptr) //we didn't find it :(
				return false;
		}
	}
	return true;
}
/*
a) function that deletes a TreeNode from the tree that has the data key. It then returns whether or not it was sucessful in the deletion
b) @param: T key - the data that we are trying to delete
c) @return: bool - whether or not the TreeNode with that data was deleted
d) no exceptions thrown
*/
template<class T>
bool BST<T>::deleteR(T key) {
	if (isEmpty()){
		//if the tree is empty, stop deleting
		return false;
	}

	if (!contains(key)){
		//if the tree doesnt contain the key, dont delete it
		return false;
	}

	TreeNode<T> *current = root;
	TreeNode<T> *parent = root;
	bool isLeft = true;

	while (current->key != key) {
		parent = current;

		if (key < current->key) {
			isLeft = true;
			current = current->left;
		}
		else //right child
		{
			isLeft = false;
			current = current->right;
		}

		if (current == nullptr)
			return false;
	}

	//at this point we found our node
	//now lets check our cases

	if (current->left == nullptr && current->right == nullptr) {
		if (current == root)
			root = nullptr;
		else if (isLeft) {
			parent->left = nullptr;
			//delete current; check this!
		}
		else { //right child
			parent->right = nullptr;
			//delete current; check this!
		}
	}

	//check for nodes with one child
	else if (current->right == nullptr) { // current has a left child
		if (current == root) {
			root = current->left;
		}
		else if (isLeft) {
			parent->left = current->left;
		}
		else { //right child
			parent->right = current->left;
		}
	}
	else if (current->left == nullptr) { // current has a right child
		if (current == root) {
			root = current->right;
		}
		else if (isLeft) {
			parent->left = current->right;
		}
		else { //right child
			parent->right = current->right;
		}
	}

	//node has two children!
	else {
		//find the successor of the node to be deleted (current)
		TreeNode<T> *successor = getSuccessor(current);

		if (current == root) {
			root = successor;
		}
		else if (isLeft) {
			parent->left = successor;
		}
		else { // right child
			parent->right = successor;
		}

		successor->left = current->left;
	}

	return true;
}
/*
a) function that returns the node that will replace the node that we just deleted
b) @param: TreeNode<T> *d - the node that will be deleted
c) @return: TreeNode<T> *d - the node that will replace the node that was just deleted
d) no exceptions thrown
*/
template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) { //d is the node to be deleted
	//we want the smallest larger than d
	TreeNode<T> *sp = d; //successor's parent
	TreeNode<T> *successor = d; //
	TreeNode<T> *current = d->right;

	while (current != nullptr) {
		sp = successor;
		successor = current;
		current = current->left;
	}

	if (successor != d->right) {
		sp->left = successor->right;
		successor->right = d->right;
	}

	return successor;

}
/*
a) a function that finds and returns a pointer to the data for a T object we are looking for
b) @param: T *value - the data that we are searching for
c) @return: T* - a pointer to the data we are looking for within the tree
d) no exceptions thrown
*/
template<class T>
T* BST<T>::Find(T *value) {
	if (isEmpty()) {
		cout << "Sorry, the tree is empty." << endl;
		return nullptr;
	}
	else { //not an empty tree
		TreeNode<T> *current = root;

		while (current->key != (*value)) {
			if ((*value) < current->key)
				current = current->left;
			else
				current = current->right;

			if (current == nullptr){
				cout << "Value was not found." << endl;
				return nullptr;
			}

		}

		T *returnT = &current->key;

		return returnT;
	}
}
/*
a) accessor function for the Root of the BST
b) @param: Node
c) @return: TreeNode<T>* - a pointer to the root of the BST
d) no exceptions thrown
*/
template<class T>
TreeNode<T>* BST<T>::GetRoot() {
	return root;
}
//getMax and getMin to be added

#endif //GEN_TREE_H
