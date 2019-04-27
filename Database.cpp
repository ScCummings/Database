#include "Database.h"

using namespace std;

Database::Database(){
    if(!LoadFiles){
        studentTable = new BST<Student>();
        facultyTable = new BST<Faculty>();
    }

    rollbackStack = new LimitedAcceptingStack<Rollback>();
}

Database::~Database(){
    //save to file

    delete studentTable;
    delete facultyTable;
    delete rollbackStack;
}

bool Database::LoadFiles(){
    return false;
}

void Database::PrintFaculty(){
    facultyTable->recPrint();
}
void Database::PrintStudents(){
    studentTable->recPrint();
}
void Database::PrintFaculty(int facultyID){
    Faculty *temp = new Faculty(facultyID);
    temp = facultyTable->Find(temp);
    if(temp == nullptr){
        cout << "Sorry, faculty member not found" << endl;
    }
    else{
        cout << &temp;
    }
}
void Database::PrintStudent(int studentID){
    Student *temp = new Student(studentID);
    temp = studentTable->Find(temp);
    if(temp == nullptr){
        cout << "Sorry, student was not found" << endl;
    }
    else{
        cout << &temp;
    }
}
void Database::PrintAdvisor(int studentID){
    Student* stuTemp = new Student(studentID);
    stuTemp = studentTable->Find(stuTemp);
    if(stuTemp == nullptr){
        cout << "Sorry, the student whose advisor you are looking for was not found" << endl;
    }
    else{
        Faculty* facTemp = new Faculty(stuTemp->GetAdvisorID());
        facTemp = facultyTable->Find(facTemp);
        if(facTemp == nullptr){
            cout << "Sorry, the student's advisor was not found" << endl;
        }
        else{
            cout << (*facTemp);
        }
    }

}
void Database::PrintAdvisees(int facultyID){
    Faculty* facTemp = new Faculty(facultyID);
    facTemp = facultyTable->Find(facTemp);
    int* studentIDs = facTemp->GetAdvisees();
    for(int i = 0;i < facTemp->GetAdviseeCount();++i){
        Student* stuTemp = new Student(studentIDs[i]);
        stuTemp = studentTable->Find(stuTemp);
        if(stuTemp == nullptr){
            cout << "Sorry, one of the student's that you tried to access doesn't exist." << endl;
        }
        else{
            cout << (*stuTemp);
        }
    }
}
void Database::AddStudent(Student newStudent){
    newStudent.SetAdvisorID(facultyTable->GetRoot()->key.GetID());
    if(&newStudent != nullptr){
        studentTable->insert(newStudent);
    }
    else{
        cout << "Sorry, the student you passed in doesn't exist." << endl;
    }
}
void Database::DeleteStudent(int studentID){
    Student* stuTemp = new Student(studentID);
    stuTemp = studentTable->Find(stuTemp);
    Faculty* facTemp = new Faculty(stuTemp->GetAdvisorID());
    facTemp = facultyTable->Find(facTemp);
    facTemp->RemoveAdvisee(studentID);
    if(stuTemp != nullptr){
        studentTable->deleteR((*stuTemp));
    }
    else{
        cout << "Sorry, the student you tried to delete doesn't exist." << endl;
    }
}

void Database::AddFaculty(Faculty newFaculty){
    if(&newFaculty != nullptr){
        facultyTable->insert(newFaculty);
    }
    else{
        cout << "Sorry, the student you passed in doesn't exist." << endl;
    }
}

void Database::DeleteFaculty(int facultyID){
    Faculty* facTemp = new Faculty(facultyID);
    facTemp = facultyTable->Find(facTemp);
    for(int i = 0;i < facTemp->GetAdviseeCount();++i){
        Student* stuTemp = new Student(facTemp->GetAdvisees()[i]);
        stuTemp = studentTable->Find(stuTemp);
        stuTemp->SetAdvisorID(facultyTable->GetRoot()->key.GetID());
    }
    if(facTemp != nullptr){
        facultyTable->deleteR((*facTemp));
    }
    else{
        cout << "Sorry, the faculty member you tried to delete doesn't exist." << endl;
    }
}

void Database::ChangeAdvisor(int studentID,int facultyID){
    Student* stuTemp = new Student(studentID);
    stuTemp = studentTable->Find(stuTemp);
    Faculty* facTemp1 = new Faculty(facultyID);
    Faculty* facTemp2 = new Faculty(facultyID);
    facTemp1 = facultyTable->Find(facTemp1);
    facTemp2 = facultyTable->Find(facTemp2);
    facTemp1->AddAdvisee(studentID);
    stuTemp->SetAdvisorID(facultyID);
    facTemp2->RemoveAdvisee(studentID);
}
void Database::RemoveAdvisee(int facultyID,int studentID){
    Faculty* facTemp = new Faculty(facultyID);
    facTemp = facultyTable->Find(facTemp);
    facTemp->RemoveAdvisee(studentID);
    Student* stuTemp = new Student(studentID);
    stuTemp = studentTable->Find(stuTemp);
    stuTemp->SetAdvisorID(facultyTable->GetRoot()->key.GetID());
}
//void Database::Rollback();
