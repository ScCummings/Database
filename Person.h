#include <string>

using namespace std;

class Person
{
private:
  // the ID number of the person
 int id;

 // the name of the person
 string name;

 // the rank of the person (Year for student and rank for faulty)
  string rank;

 // the Specialization of the person (major for student and department for faculty)
 string specialization;

 ////accessors & mutator for Specialization and rank////
public:
 // accessor for rank
 virtual string GetRank();

 // accessor for name
 virtual string GetName();

 // accessor for ID
 virtual int GetID();

 // accessor for specialization
 virtual string GetSpecialization();

 // mutator for specialization
 virtual void SetRank(string specialization);
};
