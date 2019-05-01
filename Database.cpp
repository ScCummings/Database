#include "Database.h"

using namespace std;

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
Database::Database() {
	if(fileIO.CheckLoadStatus()){
        studentTable = fileIO.LoadStudents();
        facultyTable = fileIO.LoadFaculty();
        cout << "loaded from files" << endl;

        studentTable->printTree();

    }
	else{
        studentTable = new BST<Student>();
	    facultyTable = new BST<Faculty>();
    }
	//}

	//rollbackStack = new LimitedAcceptingStack<Rollback>();
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
Database::Database(BST<Student> *studentTable, BST<Faculty> *facultyTable) {
	this->studentTable = studentTable;
	this->facultyTable = facultyTable;
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
Database::~Database() {
	//save to file

	delete studentTable;
	delete facultyTable;
	//delete rollbackStack;
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
bool Database::LoadFiles() {
	return false;
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
void Database::PrintFaculty() {
	facultyTable->recPrint();
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
void Database::PrintStudents() {
	studentTable->recPrint();
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
void Database::PrintFaculty(int facultyID) {
	Faculty *temp = new Faculty(facultyID);
	temp = facultyTable->Find(temp);
	if (temp == nullptr) {
		cout << "Sorry, faculty member not found" << endl;
	}
	else {
		cout << (*temp);
	}
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
void Database::PrintStudent(int studentID) {
	Student *temp = new Student(studentID);
	temp = studentTable->Find(temp);
	if (temp == nullptr) {
		cout << "Sorry, student was not found" << endl;
	}
	else {
		cout << (*temp);
	}
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
void Database::PrintAdvisor(int studentID) {
	Student* stuTemp = new Student(studentID);
	stuTemp = studentTable->Find(stuTemp);
	if (stuTemp == nullptr) {
		cout << "Sorry, the student whose advisor you are looking for was not found" << endl;
	}
	else {
		Faculty* facTemp = new Faculty(stuTemp->GetAdvisorID());
		facTemp = facultyTable->Find(facTemp);
		if (facTemp == nullptr) {
			cout << "Sorry, the student's advisor was not found" << endl;
		}
		else {
			cout << (*facTemp);
		}
	}

}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
void Database::PrintAdvisees(int facultyID) {
	Faculty* facTemp = new Faculty(facultyID);
	facTemp = facultyTable->Find(facTemp);
	int* studentIDs = facTemp->GetAdvisees();
	for (int i = 0; i < facTemp->GetAdviseeCount(); ++i) {
		Student* stuTemp = new Student(studentIDs[i]);
		stuTemp = studentTable->Find(stuTemp);
		if (stuTemp == nullptr) {
			cout << "Sorry, one of the student's that you tried to access doesn't exist." << endl;
		}
		else {
			cout << (*stuTemp) << endl;
		}
	}
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
void Database::AddStudent(Student newStudent, bool isRollback) {
	if (&newStudent != nullptr) {
		studentTable->insert(newStudent);
        Faculty *tempFac = new Faculty(newStudent.GetAdvisorID());
        tempFac = facultyTable->Find(tempFac);
        tempFac->AddAdvisee(newStudent.GetID());

        if(!isRollback){
            Rollback r(newStudent.GetID(), false);
            rollbackStack->Push(r);
        }
        
	}
	else {
		cout << "Sorry, the student you passed in doesn't exist." << endl;
	}
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
void Database::DeleteStudent(int studentID, bool isRollback) {
	Student* stuTemp = new Student(studentID);
	stuTemp = studentTable->Find(stuTemp);
	Faculty* facTemp = new Faculty(stuTemp->GetAdvisorID());
	facTemp = facultyTable->Find(facTemp);
	//facTemp->AddAdvisee(stuTemp->GetID());
	//facTemp->RemoveAdvisee(studentID);
	//this->ChangeAdvisor(studentID, facultyTable->GetRoot()->key.GetID());
	if (stuTemp != nullptr) {
        if(!isRollback){
            Rollback r(stuTemp);
            rollbackStack->Push(r);
        }
		studentTable->deleteR((*stuTemp));
	}
	else {
		cout << "Sorry, the student you tried to delete doesn't exist." << endl;
	}
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
void Database::AddFaculty(Faculty newFaculty, bool isRollback) {
	if (&newFaculty != nullptr) {
		facultyTable->insert(newFaculty);
        if(!isRollback){
            Rollback r(newFaculty.GetID(), true);
            rollbackStack->Push(r);
        }
	}
	else {
		cout << "Sorry, the faculty member you passed in doesn't exist." << endl;
	}
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
void Database::DeleteFaculty(int facultyID, bool isRollback) {
	Faculty* facTemp = new Faculty(facultyID);
	facTemp = facultyTable->Find(facTemp);
	/*for (int i = 0; i < facTemp->GetAdviseeCount(); ++i) {
		//set each of the advisees to the root
		Student* stuTemp = new Student();
		stuTemp = studentTable->Find(stuTemp);
		stuTemp->SetAdvisorID(facultyTable->GetRoot()->key.GetID());
	}*/
	
	if (facTemp != nullptr) {
        if(!isRollback){
            Rollback r(facTemp);
            rollbackStack->Push(r);
        }
		facultyTable->deleteR((*facTemp));
        facultyTable->GetRoot()->key.AddAdvisees(facTemp->GetAdvisees(), facTemp->GetAdviseeCount());
	}
	else {
		cout << "Sorry, the faculty member you tried to delete doesn't exist." << endl;
	}
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
void Database::ChangeAdvisor(int studentID, int facultyID, bool isRollback) {
	Student* stuTemp = new Student(studentID);
	stuTemp = studentTable->Find(stuTemp);

    //if the stuTemp's new advisor will be nonexistant
    if(facultyID == 0){
        RemoveAdvisee(stuTemp->GetAdvisorID(), studentID, isRollback);
        return;
    }

	Faculty* facTemp1 = new Faculty(facultyID);
	facTemp1 = facultyTable->Find(facTemp1);

    //If the student doesn't have an advisor currently
    if(stuTemp->GetAdvisorID() == 0){
        stuTemp->SetAdvisorID(facultyID);
        facTemp1->AddAdvisee(studentID);

        if(!isRollback){
            Rollback r(0, studentID, true);
        }
    }

    //Otherwise
    else{
        Faculty* facTemp2 = new Faculty(stuTemp->GetAdvisorID());
        facTemp2 = facultyTable->Find(facTemp2);

        facTemp1->AddAdvisee(studentID);
        stuTemp->SetAdvisorID(facultyID);
        facTemp2->RemoveAdvisee(studentID);

        if(!isRollback){
            Rollback r(facTemp2->GetID(), studentID, true);
            rollbackStack->Push(r);
        }
    }
}

/*
a) accessor for the Student's Name
b) @param: NA
c) @return: NA
d) no exceptions thrown
*/
void Database::RemoveAdvisee(int facultyID, int studentID, bool isRollback) {
	Faculty* facTemp = new Faculty(facultyID);
	facTemp = facultyTable->Find(facTemp);
	facTemp->RemoveAdvisee(studentID);
	Student* stuTemp = new Student(studentID);
	stuTemp = studentTable->Find(stuTemp);
	stuTemp->SetAdvisorID(0);

    if(!isRollback){
        Rollback r(facultyID, studentID, false);
        rollbackStack->Push(r);
    }
    
}
//void Database::Rollback();
