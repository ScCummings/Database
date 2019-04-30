void FileIO::Save(BST<Student> studentTree, BST<Faculty> facultyTree){
    if(node == nullptr){
        return;
    }
    else{
        //reference to key
        recPrint(node->left);
        recPrint(node->right);
    }
}
BST<Student> FileIO::LoadStudents(){

}
BST<Faculty> FileIO::LoadFaculty(){

}
