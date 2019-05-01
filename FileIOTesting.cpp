#include <iostream>
#include <string>
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
#include "GenDoubleLinkedList.h"
using namespace std;


int main(){
    string someString = "{\"id\":1,\"name\":\"Queenie\",\"rank\":2,\"specialization\":\"Sci\",\"GPA\":4.0,\"advisorID\":4432}";
    string someStringF = "{\"id\":4432,\"name\":\"Urdu\",\"rank\":0,\"specialization\":\"Queso Studies\",\"advisees\":[]}";


    Student bitchface = Student::Unserialize(someString);
    cout << bitchface << endl << endl;
    cout << "someString:  " << someString << endl;
    cout << "bitchface.:  " << bitchface.Serialize() << endl << endl;
    cout << "**********************************" << endl << endl;
    Faculty someFaculty = Faculty::Unserialize(someStringF);
    cout << someFaculty << endl << endl;
    cout << "someStringF:  " << someStringF << endl;
    cout << "someFaculty:  " << someFaculty.Serialize() << endl << endl;
    return 0;
}

// Student UnserializeS(string str){
//     GenStack<char> *delim = new GenStack<char>();

//     //Stores values used to create new student
//     int id = -1;
//     string name = "";
//     short rank = -1;
//     string specialization = "";
//     float GPA = -1;
//     int advisorID = -1;

//     //Traverses entire student string
//     for(int i = 0; i < str.length(); i++){
//         //Tests the current character for delimiters
//         if((str[i] == '{') || (str[i] == '[') || (str[i] == '\"' & (!delim->isEmpty() && (delim->peek() != '\"')))){
//             delim->push(str[i]);
//         }

//         //Once the start of a new member variable is found, traverse it
//         else if(delim->peek() == '\"'){
//             //will be the name of the member variable
//             string thisString = "";

//             //collect characters until the close quote
//             while(str[i] != '\"'){
//                 thisString += str[i++];
//             }

//             //removes the quote from the delimiter stack
//             delim->pop();

//             //checks to see if the next character is a colon (it should be)
//             if(str[i+1] == ':'){
//                 //move past the colon
//                 i += 2;

//                 //check the name of the current member vairable
//                 if(thisString == "id"){
//                     string idString = "";

//                     //collect numeric characters until the next member variable starts at the comma
//                     while(str[i] != ','){
//                         idString += str[i++];
//                     }

//                     //try to parse the collected characters
//                     try{
//                         id = stoi(idString);
//                     }
//                     catch(invalid_argument e){
//                         cerr << "Invalid student string" << endl;
//                         //throwing error
//                     }
//                 }
//                 else if(thisString == "name"){
//                     string nameString = "";

//                     //check if the next character is a quote (which it should be)
//                     if(str[i++] == '\"'){
//                         //collects characters until the close quote
//                         while(str[i] != '\"'){
//                             nameString += str[i++];
//                         }

//                         i++;
//                         if(str[i] != ','){
//                             cerr << "Invalid student string" << endl;
//                         }
//                     }
//                     //otherwise throws an error
//                     else{
//                         cerr << "Invalid student string" << endl;
//                         //throwing error
//                     }
//                     name = nameString;
//                 }
//                 else if(thisString == "rank"){
//                     string rankString = "";
//                     while(str[i] != ','){
//                         rankString += str[i++];
//                     }

//                     rank = (short)stoi(rankString);
//                 }
//                 else if(thisString == "specialization"){
//                     string specializationString = "";
//                     if(str[i++] == '\"'){
//                         while(str[i] != '\"'){
//                             specializationString += str[i++];
//                         }

//                         i++;
//                         if(str[i] != ','){
//                             cerr << "Invalid student string" << endl;
//                         }
//                     }
//                     else{
//                         cerr << "Invalid student string" << endl;
//                         //throwing error
//                     }
//                     specialization = specializationString;
//                 }
//                 else if(thisString == "GPA"){
//                     string gpaString = "";
//                     while(str[i] != ','){
//                         gpaString += str[i++];
//                     }

//                     GPA = stof(gpaString);
//                 }
//                 else if(thisString == "advisorID"){
//                     string advisorIDString = "";
//                     while(str[i] != '}'){
//                         advisorIDString += str[i++];
//                     }

//                     advisorID = stoi(advisorIDString);
//                 }
//                 continue;
//             }
//             else{
//                 cerr << "invalid student string\n";
//                 //throw error
//             }
//         }
//     }

//     delete delim;

//     Student someStudent(id,GPA,advisorID,name,rank,specialization);
//     return someStudent;
// }

// Faculty UnserializeF(string str){
//     GenStack<char> *delim = new GenStack<char>();
//     //{"id":4432,"name":"Urdu","rank":0,"specialization":"Queso Studies","advisees":[234423,543523,243465,987967]}
//     //Stores values used to create new student
//     int id = -1;
//     string name = "";
//     short rank = -1;
//     string specialization = "";
//     GenDoubleLinkedList<int> *advisees = new GenDoubleLinkedList<int>();

//     //Traverses entire faculty string
//     for(int i = 0; i < str.length(); i++){
//         //Tests the current character for delimiters
//         if((str[i] == '{') || (str[i] == '[') || (str[i] == '\"' & (!delim->isEmpty() && (delim->peek() != '\"')))){
//             delim->push(str[i]);
//         }

//         //Once the start of a new member variable is found, traverse it
//         else if(delim->peek() == '\"'){
//             //will be the name of the member variable
//             string thisString = "";

//             //collect characters until the close quote
//             while(str[i] != '\"'){
//                 thisString += str[i++];
//             }

//             //removes the quote from the delimiter stack
//             delim->pop();

//             //checks to see if the next character is a colon (it should be)
//             if(str[i+1] == ':'){
//                 //move past the colon
//                 i += 2;

//                 //check the name of the current member vairable
//                 if(thisString == "id"){
//                     string idString = "";

//                     //collect numeric characters until the next member variable starts at the comma
//                     while(str[i] != ','){
//                         idString += str[i++];
//                     }

//                     //try to parse the collected characters
//                     try{
//                         id = stoi(idString);
//                     }
//                     catch(invalid_argument e){
//                         cerr << "ID: Invalid faculty string" << endl;
//                         //throwing error
//                     }
//                 }
//                 else if(thisString == "name"){
//                     string nameString = "";

//                     //check if the next character is a quote (which it should be)
//                     if(str[i++] == '\"'){
//                         //collects characters until the close quote
//                         while(str[i] != '\"'){
//                             nameString += str[i++];
//                         }

//                         i++;
//                         if(str[i] != ','){
//                             cerr << "Name: Invalid faculty string" << endl;
//                         }
//                     }
//                     //otherwise throws an error
//                     else{
//                         cerr << "Name: Invalid faculty string" << endl;
//                         //throwing error
//                     }
//                     name = nameString;
//                 }
//                 else if(thisString == "rank"){
//                     string rankString = "";
//                     while(str[i] != ','){
//                         rankString += str[i++];
//                     }

//                     rank = (short)stoi(rankString);
//                 }
//                 else if(thisString == "specialization"){
//                     string specializationString = "";
//                     if(str[i++] == '\"'){
//                         while(str[i] != '\"'){
//                             specializationString += str[i++];
//                         }

//                         i++;
//                         if(str[i] != ','){
//                             cerr << "Specialization: Invalid faculty string" << endl;
//                         }
//                     }
//                     else{
//                         cerr << "Specialization2: Invalid faculty string" << endl;
//                         //throwing error
//                     }
//                     specialization = specializationString;
//                 }

//                 else if(thisString == "advisees"){
//                     cout << "gets into else if" << endl;
//                     if(str[i] == '['){
//                         cout << "gets into if" << endl;
//                         i++;
//                         cout << "str[i] before the while loop: " << str[i] << endl;
//                         while(str[i] != ']'){
//                             cout << "gets into while loop" << endl;
//                             string studentIDString = "";
//                             cout << "Makes the string" << endl;
//                             while(str[i] != ',' && str[i] != ']'){
//                                 cout << "Goes through the second while loop" << endl;
//                                 studentIDString += str[i++];
//                             }
//                             if(str[i] == ','){
//                                 i++;
//                             }
//                             //try to parse the collected characters
//                             try{
//                                 cout << "Try gets called" << endl;
//                                 cout << "Student Id String: " << studentIDString << endl;
//                                 advisees->insertBack(stoi(studentIDString));
//                             }
//                             catch(invalid_argument e){
//                                 cerr << "Advisees: Invalid faculty string" << endl;
//                                 //throwing error
//                             }
//                         }
//                     }
//                     else{
//                         cerr << "Advisees2: Invalid faculty string" << endl;
//                         //throwing error
//                     }
//                 }
//                 continue;
//             }
//             else{
//                 cerr << "whole thing: invalid faculty string\n";
//                 //throw error
//             }
//         }
//     }

//     delete delim;

//     Faculty someFaculty(id,name,rank,specialization,advisees);
//     return someFaculty;
// }
