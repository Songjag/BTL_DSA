#include "students.h"
#include <iostream>
using namespace std;

void Student::calcGPA() {
    gpa = (math + physics + chemistry) / 3;
    if (gpa >= 8) {
        academic_rank = "Gioi";
    } else if (gpa >= 6.5) {
        academic_rank = "Kha";
    } else if (gpa >= 5) {
        academic_rank = "Trung binh";
    } else {
        academic_rank = "Yeu";
    }
}

void Student::display() {
    cout << "Sinh vien:" << id << "-" << name;
    cout << "Diem :" << "Toan:" << math << "-" << "Ly:" << physics << "-"<< "Hoa:" << chemistry << endl;
}
