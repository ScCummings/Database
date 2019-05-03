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
        //if there is an output stream open, close it
        outputStream.close();
    }

    outputStream.open(studentData);
    //open a new output stream
    SaveStudentRec(studentTree->GetRoot());
    //Save the current student tree
    outputStream.close();
    //close the outputStream
    outputStream.open(facultyData);
    //open a new outputStream using the facultyData file
    SaveFacultyRec(facultyTree->GetRoot());
}
/*
a) recursive function for saving the student objects found within the user created trees
b) @param: TreeNode<Student> *curr - a TreeNode which is the Node at which we want to start saving the student objects from the tree
c) @return: void
d) no exceptions thrown
*/
void FileIO::SaveStudentRec(TreeNode<Student> *curr) throw (UnserializeException){
    if(curr == nullptr){
        //if curr doesnt exist, exit
        return;
    }
    else{
        try{
            //Preorder traversal to serialize the student object
            outputStream << curr->key.Serialize() << endl;
            SaveStudentRec(curr->left);
            SaveStudentRec(curr->right);
        }
        catch(UnserializeException e){
            //catch any exceptions
            throw e;
        }
    }
}
/*
a) recursive function for saving the faculty objects found within the user created trees
b) @param: TreeNode<Faculty> *curr - a TreeNode which is the Node at which we want to start saving the student objects from the tree
c) @return: void
d) no exceptions thrown
*/
void FileIO::SaveFacultyRec(TreeNode<Faculty> *curr) throw (UnserializeException){
    if(curr == nullptr){
        //if curr doesnt exist, exit
        return;
    }
    else{
        try{
            //preorder traversal to serialize the faculty
            outputStream << curr->key.Serialize() << endl;
            SaveFacultyRec(curr->left);
            SaveFacultyRec(curr->right);
        }
        catch(UnserializeException e){
            throw e;
        }
    }
}
/*
a) function for loading the student objects from the student file
b) @param: None
c) @return: BST<Student>* A pointer to the loaded student tree
d) throws UnserializationException
*/
BST<Student>* FileIO::LoadStudents() throw (UnserializeException){
    BST<Student> *newStudentTree = new BST<Student>();
    if(inputStream.is_open()){
        //if there is an inputstream open, close it
        inputStream.close();
    }
    inputStream.open(studentData);
    //open a new inputStream from the studentData file
    string line = "";
    try{
        //while you can get more add lines through inputStream, Insert the Unserialized student
        while(getline(inputStream,line)){
            newStudentTree->insert(Student::Unserialize(line));
        }
    }
    catch(UnserializeException e){
        //debug statement
        cout << "in load students" << endl;
        throw e;
    }
    return newStudentTree;
}
/*
a) function for loading the faculty objects from the faculty file
b) @param: None
c) @return: BST<Faculty>* A pointer to the loaded faculty tree
d) throws UnserializationException
*/
BST<Faculty>* FileIO::LoadFaculty() throw (UnserializeException){
    BST<Faculty> *newFacultyTree = new BST<Faculty>();
    if(inputStream.is_open()){
        //if there is an inputStream open, close it
        inputStream.close();
    }
    inputStream.open(facultyData);
    //open a new inputStream with the faultyData file
    string line = "";
    try{
        //while you can add more lines through the inputStream, insert the Unserialized faculty objects
        while(getline(inputStream,line)){
            newFacultyTree->insert(Faculty::Unserialize(line));
        }
    }
    //change to UnserializationException
    catch(UnserializeException e){
        throw e;
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
        //open a new inputStream from the studentData file
        string tempLine = "";
        //if the file has data, set studentTableHasData
        if(getline(inputStream, tempLine)){
            studentTableHasData = true;
        }
        //close the inputStream
        inputStream.close();
        //open a new inputStream using the facultyData file
        inputStream.open(facultyData);
        tempLine = "";
        //if the file has data, set facultyTableHasData
        if(getline(inputStream, tempLine)){
            facultyTableHasData = true;
        }

        //if they both have data
        if(studentTableHasData && facultyTableHasData){
            return true;
        }

        //if only one has data
        else if(studentTableHasData || facultyTableHasData){
            if(studentTableHasData){
                //student has data
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
                    //open a new inputStream with the studentData file
                    inputStream.clear();
                    //clear the inputStream
                    inputStream.seekg(0, inputStream.beg);
                    //goes back to the beginning of the file
                    outputStream.open(studentDataDump);
                    //open a outputStream with the studentDataDump file

                    string temp = "";
                    //while you can input into to the inputStream, do it
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
                //if faculty has data
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
                    //open a new input stream with the facultyData file
                    inputStream.open(facultyData);
                    //clear the inputStream
                    inputStream.clear();
                    //start the input stream at the beginning of the file
                    inputStream.seekg(0, inputStream.beg);
                    //open an outputStream with the facultyDataDump file
                    outputStream.open(facultyDataDump);

                    string temp = "";
                    //while you can input to the inputStream, do it
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
