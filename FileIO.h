class FileIO{
    private:
static ifstream inputStream;
static ofstream outputStream;
    public:
void Save(BST<Student> studentTree, BST<Faculty> facultyTree);
BST<Student> LoadStudents();
BST<Faculty> LoadFaculty();

};
