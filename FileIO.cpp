//Name:  Dan Haub
//Student ID#:  2315346
//Chapman Email:  haub@chapman.edu
//Name:  Scott Cummings
//Student ID#:  2317991
//Chapman Email:  scummings@chapman.edu
//Course Number and Section:  CPSC 350-01
//Assignment:  5 - School Database

#include "FileIO.h"

using namespace std;

/*
a) function for saving the trees created by the user
b) @param: BST<Student>* studentTree - a pointer to a tree which contains all of the student information that was added during the user's session | BST<Faculty>* facultyTree - a pointer to a tree which contains all the faculty information that was added during the user's session
c) @return: void
d) no exceptions thrown
*/
void FileIO::Save(BST<Student> *studentTree, BST<Faculty> *facultyTree){
    if(outputStream.is_open()){
        outputStream.close();
    }

    outputStream.open(studentData);
    SaveStudentRec(studentTree->GetRoot());

    outputStream.close();
    outputStream.open(facultyData);
    SaveFacultyRec(facultyTree->GetRoot());
}
/*
a) recursive function for saving the student objects found within the user created trees
b) @param: TreeNode<Student> *curr - a TreeNode which is the Node at which we want to start saving the student objects from the tree
c) @return: void
d) no exceptions thrown
*/
void FileIO::SaveStudentRec(TreeNode<Student> *curr){
    if(curr == nullptr){
        return;
    }
    else{
        outputStream << curr->key.Serialize() << endl;
        SaveStudentRec(curr->left);
        SaveStudentRec(curr->right);
    }
}
/*
a) recursive function for saving the faculty objects found within the user created trees
b) @param: TreeNode<Faculty> *curr - a TreeNode which is the Node at which we want to start saving the student objects from the tree
c) @return: void
d) no exceptions thrown
*/
void FileIO::SaveFacultyRec(TreeNode<Faculty> *curr){
    if(curr == nullptr){
        return;
    }
    else{
        outputStream << curr->key.Serialize() << endl;
        SaveFacultyRec(curr->left);
        SaveFacultyRec(curr->right);
    }
}
/*
a) function for loading the student objects from the student file
b) @param: None
c) @return: BST<Student>* A pointer to the loaded student tree
d) throws UnserializationException
*/
BST<Student>* FileIO::LoadStudents(){
    BST<Student> *newStudentTree = new BST<Student>();
    if(inputStream.is_open()){
        inputStream.close();
    }
    inputStream.open(studentData);
    string line = "";
    try{
        while(getline(inputStream,line)){
            newStudentTree->insert(Student::Unserialize(line));
        }
    }
    //change to UnserializationException
    catch(int e){
        cout << "UnserializationException" << endl;
    }
    return newStudentTree;
}
/*
a) function for loading the faculty objects from the faculty file
b) @param: None
c) @return: BST<Faculty>* A pointer to the loaded faculty tree
d) throws UnserializationException
*/
BST<Faculty>* FileIO::LoadFaculty(){
    BST<Faculty> *newFacultyTree = new BST<Faculty>();
    if(inputStream.is_open()){
        inputStream.close();
    }
    inputStream.open(facultyData);
    string line = "";
    try{
        while(getline(inputStream,line)){
            newFacultyTree->insert(Faculty::Unserialize(line));
        }
    }
    //change to UnserializationException
    catch(int e){
        cout << "UnserializationException" << endl;
    }
    return newFacultyTree;
}
/*
a) function for checking for the student and faculty files
b) @param: None
c) @return: bool - true if both of the files are sucessfully opened and have data inside
d) no exceptions thrown
*/
bool FileIO::CheckLoadStatus(){
    bool userResponse = false;
    string userResponseString = "";
    while(true){
        cout << "Would you like to load files from a previous database?(y/n)" << endl;
        cin >> userResponseString;
        if(userResponseString == "y"){
            userResponse = true;
            break;
        }
        else if(userResponseString == "n"){
            userResponse = false;
            break;
        }
        else{
            cout << "Sorry, user response not recognized." << endl;
        }
    }
    if(userResponse == false){
        return false;
    }
    else{
        bool studentTableHasData = false;
        bool facultyTableHasData = false;

        inputStream.open(studentData);
        string tempLine = "";
        if(getline(inputStream, tempLine)){
            studentTableHasData = true;
        }
        inputStream.close();
        inputStream.open(facultyData);
        tempLine = "";
        if(getline(inputStream, tempLine)){
            facultyTableHasData = true;
        }


        if(studentTableHasData && facultyTableHasData){
            return true;
        }

        else if(studentTableHasData || facultyTableHasData){
            if(studentTableHasData){
                bool userResponse = false;
                string userResponseString = "";
                while(true){
                    cout << "Sorry, data was only found in the student file. Would you like to dump this file?(y/n)" << endl;
                    cin >> userResponseString;
                    if(userResponseString == "y"){
                        userResponse = true;
                        break;
                    }
                    else if(userResponseString == "n"){
                        userResponse = false;
                        break;
                    }
                    else{
                        cout << "Sorry, user response not recognized." << endl;
                    }
                }
                if(userResponse){
                    inputStream.open(studentData);
                    inputStream.clear();
                    inputStream.seekg(0, inputStream.beg);
                    outputStream.open(studentDataDump);

                    string temp = "";
                    while(getline(inputStream,temp)){
                        outputStream << temp << endl;
                    }
                    return false;
                }
                else if(!userResponse){
                    return false;
                }
                else{
                    return false;
                }
            }

            else if(facultyTableHasData){
                bool userResponse = false;
                string userResponseString = "";
                while(true){
                    cout << "Sorry, data was only found in the faculty file. Would you like to dump this file?(y/n)" << endl;
                    cin >> userResponseString;
                    if(userResponseString == "y"){
                        userResponse = true;
                        break;
                    }
                    else if(userResponseString == "n"){
                        userResponse = false;
                        break;
                    }
                    else{
                        cout << "Sorry, user response not recognized." << endl;
                    }
                }
                if(userResponse){
                    inputStream.open(facultyData);
                    inputStream.clear();
                    inputStream.seekg(0, inputStream.beg);
                    outputStream.open(facultyDataDump);

                    string temp = "";
                    while(getline(inputStream,temp)){
                        outputStream << temp << endl;
                    }
                    return false;
                }
                else if(!userResponse){
                    return false;
                }
                else{
                    return false;
                }
            }
        else {
            cout << "Neither file has data :(" << endl;
            return false;
        }
    }
}
}
