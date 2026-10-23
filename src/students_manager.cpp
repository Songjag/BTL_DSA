#include <iostream>
#include <include/students_manager.h>
using namespace std;

int StudentManager::findIndexByID(int id){
    for (int i=0;i<student.size();i++){
        if (student[i].id==id){
            return i;
        }
    }
}
void inputScore(double &score, string subject) {
    do {
        cout << "Nhap diem " << subject << ": ";
        cin >> score;
    } while (score < 0 || score > 10);
}
void StudentManager::addStudent(){
    Student sv;
    sv.id=NextID;
    cout<<"Nhap ten sinh vien:";getline(cin,sv.name);
    cout<<"Nhap gioi tinh:";getline(cin,sv.gender);
    do {
        cout << "Nhap tuoi: ";cin >> sv.age;
        if (sv.age < 10 || sv.age > 100) {
            cout << "Tuoi khong le vui long nhap lai.\n";
        }
    } while (sv.age < 10 || sv.age > 100);
    inputScore(sv.math,"Toan");
    inputScore(sv.physics,"Vat ly");
    inputScore(sv.chemistry,"Hoa");
    sv.calcGPA();
    student.push_back(sv);
    NextID++;
    cout<<"Them thanh cong sinh vien voi id:"<<sv.id<<endl;
}