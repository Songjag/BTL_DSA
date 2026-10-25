#include "students_manager.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int StudentManager::findIndexByID(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}
bool inputScore(double &score, const string &subject) {
    while (true) {
        cout << "Nhap diem " << subject << ": ";
        if (cin >> score && isfinite(score) && score >= 0 && score <= 10) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        }
        if (cin.eof())
            return false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Diem phai nam trong khoang 0 den 10.\n";
    }
}

// Them va cap nhat dung chung cach nhap thong tin.
bool inputStudent(Student &sv) {
    cout << "Nhap ten sinh vien: ";
    if (!getline(cin, sv.name))
        return false;
    cout << "Nhap gioi tinh: ";
    if (!getline(cin, sv.gender))
        return false;

    while (true) {
        cout << "Nhap tuoi: ";
        if (cin >> sv.age && sv.age >= 10 && sv.age <= 100) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        if (cin.eof())
            return false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Tuoi phai nam trong khoang 10 den 100.\n";
    }

    if (!inputScore(sv.math, "Toan") || !inputScore(sv.physics, "Vat ly") ||
        !inputScore(sv.chemistry, "Hoa"))
        return false;
    sv.calcGPA();
    return true;
}

void StudentManager::addStudent() {
    Student sv;
    if (!inputStudent(sv))
        return;
    sv.id = nextID;
    students.push_back(sv);
    nextID++;
    cout << "Da them sinh vien co ID: " << sv.id << '\n';
}
void StudentManager::removeStudent(int id) {
    int idx = findIndexByID(id);
    if (idx == -1) {
        cout << "Khong tim thay sinh vien:\n";
        return;
    }
    students.erase(idx);
    cout << "Xoa sinh vien thanh cong\n";
}
void StudentManager::updateStudent(int id) {
    int idx = findIndexByID(id);
    if (idx == -1) {
        cout << "Khong tim thay sinh vien!\n";
        return;
    }
    Student sv = students[idx];
    cout << "Nhap thong tin sinh vien moi:\n";
    if (!inputStudent(sv))
        return;
    students[idx] = sv;
    cout << "Da cap nhat thong tin sinh vien.\n";
}

void StudentManager::displayAll() {
    if (students.empty()) {
        cout << "\nDanh sach sinh vien dang rong.\n";
        return;
    }

    const string separator = "+----+------------------------------+------------+------+------+-----"
                             "-+------+-------+--------------+\n";

    cout << "\nDANH SACH SINH VIEN (" << students.size() << " sinh vien)\n";
    cout << separator;
    cout << "| ID | Ho va ten                    | Gioi tinh  | Tuoi | Toan | Ly   | Hoa  | GPA   "
            "| Xep loai     |\n";
    cout << separator;

    cout << fixed << setprecision(2);
    for (int i = 0; i < students.size(); ++i) {
        const Student &sv = students[i];
        cout << "| " << setw(2) << right << sv.id << " | " << setw(28) << left << sv.name << " | "
             << setw(10) << left << sv.gender << " | " << setw(4) << right << sv.age << " | "
             << setw(4) << sv.math << " | " << setw(4) << sv.physics << " | " << setw(4)
             << sv.chemistry << " | " << setw(5) << sv.gpa << " | " << setw(12) << left
             << sv.academic_rank << " |\n";
    }
    cout << separator;
    cout.unsetf(ios::floatfield);
    cout << setprecision(6);
}
void StudentManager::saveFile() {
    ofstream file("data/students.txt");

    if (!file) {
        cout << "Khong mo duoc file!\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        const Student &sv = students[i];

        file << sv.id << '\n';
        file << sv.name << '\n';
        file << sv.gender << '\n';
        file << sv.age << " " << sv.math << " " << sv.physics << " " << sv.chemistry << '\n';
    }

    if (!file) {
        cout << "Ghi file that bai!\n";
        return;
    }

    cout << "Luu danh sach thanh cong!\n";
}

void StudentManager::readFile() {
    ifstream file("data/students.txt");

    if (!file)
        return;

    WeitaVector<Student> loaded;
    Student sv;
    int maxID = 0;

    while (file >> sv.id) {
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!getline(file, sv.name))
            break;
        if (!getline(file, sv.gender))
            break;

        if (!(file >> sv.age >> sv.math >> sv.physics >> sv.chemistry))
            break;

        if (sv.id <= 0 || sv.age <= 0 || sv.math < 0 || sv.math > 10 || sv.physics < 0 ||
            sv.physics > 10 || sv.chemistry < 0 || sv.chemistry > 10) {
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

    students = loaded;
    nextID = maxID + 1;
}
void StudentManager::findStudent(string name) {
    bool found = false;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].name.find(name) != string::npos) {
            students[i].display();
            found = true;
        }
    }

    if (!found)
        cout << "Khong tim thay sinh vien!\n";
}

void StudentManager::sortByGPA() {
    for (int i = 0; i < students.size(); i++) {
        for (int j = i + 1; j < students.size(); j++) {
            if (students[i].gpa < students[j].gpa) {
                swap(students[i], students[j]);
            }
        }
    }

    cout << "Da sap xep GPA giam dan!\n";
}

void StudentManager::sortByName() {
    for (int i = 0; i < students.size(); i++) {
        for (int j = i + 1; j < students.size(); j++) {
            if (students[i].name > students[j].name) {
                swap(students[i], students[j]);
            }
        }
    }

    cout << "Da sap xep theo ten!\n";
}
