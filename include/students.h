#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
class Student {
    public:
        int id;
        string name;
        string gender;
        int age;

        double math, physics, chemistry;
        double gpa;
        string academic_rank;

        void display();
        void calcGPA();
};
#endif
