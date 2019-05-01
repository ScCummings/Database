#include "FileIO.h"

/*
int main(){
    FileIO newFileIO;
    bool b = newFileIO.CheckLoadStatus();
    string s = "";

    if(b){
        s = "true";
    }
    else{
        s = "false";
    }
    cout << s << endl;
    BST<Faculty>* faculty = newFileIO.LoadFaculty();
    cout << "DEBUG: " << faculty->GetRoot()->key << endl;
    BST<Student>* students = newFileIO.LoadStudents();
    Database database(students,faculty);
    cout << "******DATABASE TESTING*********" << endl;
    database.PrintFaculty();
	/*database.PrintStudents();
	PrintFaculty(int facultyID);
	void PrintStudent(int studentID);
	void PrintAdvisor(int studentID);
	void PrintAdvisees(int facultyID);
	void AddStudent(Student newStudent);
	void DeleteStudent(int studentID);
	void AddFaculty(Faculty newFaculty);
	void DeleteFaculty(int facultyID);
	void ChangeAdvisor(int studentID, int facultyID);
	void RemoveAdvisee(int facultyID, int studentID);
	void Rollback();
    return 0;
}
*/
