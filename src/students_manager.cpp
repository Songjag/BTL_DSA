#include <iostream>
#include <include/students_manager.h>
#include <bits/stdc++.h>
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
void StudentManager::removeStudent(int id){
    int idx=findIndexByID(id);
    if (idx==-1){
        cout<<"Khong tim thay sinh vien:\n";
    }
    student.erase(idx);
    cout<<"Xoa sinh vien thanh cong\n";
}
void StudentManager::updateStudent(int id){
    int idx=findIndexByID(id);
    Student sv=student[idx];
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Nhap thong tin sinh vien moi:";
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
    student[idx]=sv;
    cout<<"Nhap thong tin sinh vien thanh cong"<<endl;
}
void StudentManager::displayAll(){
    if (student.empty()) {
        cout << "\nDanh sach sinh vien dang rong.\n";
        return;
    }

    const string separator =
        "+----+------------------------------+------------+------+------+------+------+-------+--------------+\n";

    cout << "\nDANH SACH SINH VIEN (" << student.size() << " sinh vien)\n";
    cout << separator;
    cout << "| ID | Ho va ten                    | Gioi tinh  | Tuoi | Toan | Ly   | Hoa  | GPA   | Xep loai     |\n";
    cout << separator;

    cout << fixed << setprecision(2);
    for (int i = 0; i < student.size(); ++i) {
        const Student &sv = student[i];
        cout << "| " << setw(2) << right << sv.id
             << " | " << setw(28) << left << sv.name
             << " | " << setw(10) << left << sv.gender
             << " | " << setw(4) << right << sv.age
             << " | " << setw(4) << sv.math
             << " | " << setw(4) << sv.physics
             << " | " << setw(4) << sv.chemistry
             << " | " << setw(5) << sv.gpa
             << " | " << setw(12) << left << sv.academic_rank
             << " |\n";
    }
    cout << separator;
    cout.unsetf(ios::floatfield);
    cout << setprecision(6);
}
void StudentManager::saveFile(){
    ofstream file("data/students.txt");

    if (!file) {
        cout << "Khong mo duoc file!\n";
        return;
    }

    for (int i = 0; i < student.size(); i++) {
        const Student& sv = student[i];

        file << sv.id << '\n';
        file << sv.name << '\n';
        file << sv.gender << '\n';
        file << sv.age << " "
             << sv.math << " "
             << sv.physics << " "
             << sv.chemistry << '\n';
    }

    if (!file) {
        cout << "Ghi file that bai!\n";
        return;
    }

    cout << "Luu danh sach thanh cong!\n";
}

void StudentManager::readFile() {
    ifstream file("data/students.txt");

    if (!file) return;

    WeitaVector<Student> loaded;
    Student sv;
    int maxID = 0;

    while (file >> sv.id) {
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!getline(file, sv.name)) break;
        if (!getline(file, sv.gender)) break;

        if (!(file >> sv.age
                   >> sv.math
                   >> sv.physics
                   >> sv.chemistry)) break;

        if (sv.id <= 0 || sv.age <= 0 ||
            sv.math < 0 || sv.math > 10 ||
            sv.physics < 0 || sv.physics > 10 ||
            sv.chemistry < 0 || sv.chemistry > 10) {
            cout << "File chua du lieu khong hop le!\n";
            return;
        }

        sv.calcGPA();
        loaded.push_back(sv);

        maxID = max(maxID, sv.id);
    }

    if (!file.eof()) {
        cout << "Loi dinh dang file!\n";
        return;
    }

    student = loaded;
    NextID = maxID + 1;
}
void StudentManager::findStudent(string name){
    bool found = false;

    for (int i = 0; i < student.size(); i++) {
        if (student[i].name.find(name) != string::npos) {
            student[i].display();
            found = true;
        }
    }

    if (!found)
        cout << "Khong tim thay sinh vien!\n";
}

void StudentManager::sortByGPA() {
    for (int i = 0; i < student.size(); i++) {
        for (int j = i + 1; j < student.size(); j++) {
            if (student[i].gpa < student[j].gpa) {
                swap(student[i], student[j]);
            }
        }
    }

    cout << "Da sap xep GPA giam dan!\n";
}

void StudentManager::sortByName() {
    for (int i = 0; i < student.size(); i++) {
        for (int j = i + 1; j < student.size(); j++) {
            if (student[i].name > student[j].name) {
                swap(student[i], student[j]);
            }
        }
    }

    cout << "Da sap xep theo ten!\n";
}
