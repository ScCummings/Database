// accessor for the student's advisor's ID
int GetAdvisorID(){
    return advisorID;
}

// the accessor for the student's GPA
float GetGPA(){
    return GPA;
}

// accessor for the student's ID
int GetID(){
    return id;
}

//accessor for the student's name
string GetName(){
    return name;
}

//accessor for the student's rank
short GetRank(){
    return rank;
}

//accessor for the student's specialization
string GetSpecialization(){
    return specialization;
}

//mutator for the student's Specialization (major)
string SetSpecialization(string specialization){
    this.specialization = specialization;
}

// mutator for the student's advisor's ID
void SetAdvisorID(int advisorID){
    this.advisorID = advisorID;
}

// mutator for the student's GPA
void SetGPA(float GPA){
    this.GPA = GPA;
}
