#ifndef STUDENT_MANAGE
#define STUDENT_MANAGE
#include <string>
#include <include/vector.h>
#include <include/students.h>
class StudentManager{
    private:
        WeitaVector<Student> student;
        int NextID=1;
        int findIndexByID(int id) ;
    public:
        void addStudent();
        void removeStudent(int id);
        void updateStudent(int id);
        void findStudent(string name);
        void sortByGPA();
        void sortByName();
        void displayAll();
        void readFile();
        void saveFile();

};
#endif
