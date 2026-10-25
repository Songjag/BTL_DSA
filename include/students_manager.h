#ifndef STUDENT_MANAGE
#define STUDENT_MANAGE
#include "students.h"
#include "vector.h"
#include <string>
class StudentManager {
private:
    WeitaVector<Student> students;
    int nextID = 1;
    int findIndexByID(int id);

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
