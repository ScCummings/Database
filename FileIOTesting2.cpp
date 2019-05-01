#include "FileIO.h"
#include "Database.h"
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
    cout << "******PRINT FACULTY*************" << endl;
    database.PrintFaculty();
    cout << "******PRINT STUDENTS************" << endl;
	database.PrintStudents();
    cout << "********PRINT SPECIFIC FACULTY*****" << endl;
	database.PrintFaculty(1276);
    cout << "*********PRINT SPECIFIC STUDENT*****" << endl;
	database.PrintStudent(1);
    cout << "*********PRINT STUDENT'S ADVISOR****" << endl;
	database.PrintAdvisor(1);
    cout << "**********PRINT FACULTY'S ADVISEES****" << endl;
	database.PrintAdvisees(1276);
    cout << "**********ADD STUDENT***********" << endl;
    Student Isaac(7,5.5,1276,"Isaac",2,"Literature");
	database.AddStudent(Isaac);
    cout << "**********CHECK AND MAKE SURE THE NEW STUDENT IS THERE*******" << endl;
    database.PrintStudents();
    database.PrintStudent(7);
    database.PrintAdvisees(1276);
    cout << "*********DELETE STUDENT********" <<  endl;
	database.DeleteStudent(7);
    cout << "**********CHECK AND MAKE SURE THE NEW STUDENT IS THERE*******" << endl;
    database.PrintStudents();
    database.PrintStudent(7);
    database.PrintAdvisees(1276);
    cout << "*******CHANGE ADVISOR********" << endl;
    /*Faculty::Faculty(int id, string name, short rank, string specialization, GenDoubleLinkedList<int> *advisees) {
    GenDoubleLinkedList<int> advisees()
    Faculty Orion(1398,"Orion",2,"Xadia Studies",)
	database.AddFaculty(Faculty newFaculty);
	//void DeleteFaculty(int facultyID);*/

	database.ChangeAdvisor(3,1276);
	//void RemoveAdvisee(int facultyID, int studentID);
	//void Rollback();
    return 0;
}
