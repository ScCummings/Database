#include <iostream>
using namespace std;

class TreeNode{
    public:
        TreeNode();
        TreeNode(int k);
        virtual ~TreeNode();//why a virtual destructor?

        int key;
        TreeNode *left;
        TreeNode *right;
};


//////Implementation///////

TreeNode::TreeNode(){
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(int k){
    key = k;
    left = nullptr;
    right = nullptr;
}

TreeNode::~TreeNode(){
    //let's do a little research (that means us)  :(
}



/////let's define our tree class/////

class BST{
    public:
        BST();
        virtual ~BST();
        void insert(int value);
        bool contains(int value); //AKA search
        bool deleteR(int key);
        TreeNode* getSuccessor(TreeNode* d);

        TreeNode* getMin();
        TreeNode* getMax();
        bool isEmpty();
        void printTree();
        void recPrint(TreeNode *node);
        void printPre();
        void printPre(TreeNode *node);
        void printPre(TreeNode *node, int level);

    private:
        TreeNode* root;
};


/////implement this bad boy/////

//Default
BST::BST(){
    root = nullptr;
}

BST::~BST(){
    //iterate and delete
    //lets put on our research hats
}

void BST::printTree(){
    recPrint(root);
}

void BST::printPre(){
    printPre(root, 0);
}

void BST::printPre(TreeNode *node){
    printPre(node, 0);
}

void BST::printPre(TreeNode *node, int level){
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

void BST::recPrint(TreeNode *node){
    if(node == nullptr){
        return;
    }
    else{
        recPrint(node->left);
        cout << node->key << endl;
        recPrint(node->right);
    }
}

bool BST::isEmpty(){
    return (root == nullptr);
}

void BST::insert(int value){
    //check if value exists, if not continue

    TreeNode *node = new TreeNode(value); //key is now set to value

    if(isEmpty()){ //empty tree
        root = node;
    }
    else{  //not empty need to find insertion point
        TreeNode *current = root; //keep track of where we are
        TreeNode *parent = nullptr; //keep track of where we've been

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

bool BST::contains(int value){
    if(isEmpty()){
        return false;
    }
    else{ //not an empty tree
        TreeNode *current = root;

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

bool BST::deleteR(int key){
    if(isEmpty())
        return false;
    
    if(!contains(key))
        return false;

    TreeNode *current = root;
    TreeNode *parent = root;
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
        TreeNode *successor = getSuccessor(current);

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

TreeNode* BST::getSuccessor(TreeNode *d){ //d is the node to be deleted
    //we want the smallest larger than d
    TreeNode *sp = d; //successor's parent
    TreeNode *successor = d; //
    TreeNode *current = d->right;

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

