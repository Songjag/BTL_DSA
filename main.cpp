#include "students_manager.h"
#include "vector.h"
#include <iostream>
#include <limits>
using namespace std;

void clearScreen() { cout << "\033[2J\033[H" << flush; }
// Moi lan nhap so deu bo phan con lai cua dong.
bool readNumber(const string &prompt, int &number) {
    while (true) {
        cout << prompt;
        if (cin >> number) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        }
        if (cin.eof())
            return false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Lua chon khong hop le. Vui long nhap so nguyen.\n";
    }
}

void pauseScreen() {
    cout << "\nNhan Enter de tiep tuc...";
    string line;
    getline(cin, line);
}

void displayVector(const WeitaVector<int> &values) {
    if (values.empty()) {
        cout << "[ ]\n";
        return;
    }
    cout << "[ ";
    for (int i = 0; i < values.size(); ++i) {
        cout << values[i];
        if (i + 1 < values.size()) {
            cout << " | ";
        }
    }
    cout << " ]\n";
}
void menu_demo_vector(WeitaVector<int> &values) {
    while (true) {
        clearScreen();
        cout << "DEMO VECTOR\n";
        cout << "Vector hien tai: ";
        displayVector(values);
        cout << "1. Them phan tu\n"
             << "2. Xoa phan tu cuoi\n"
             << "3. Xem kich thuoc\n"
             << "4. Xoa tat ca phan tu\n"
             << "0. Quay lai menu chinh\n";

        int choice;
        if (!readNumber("Nhap lua chon: ", choice) || choice == 0)
            return;

        switch (choice) {
        case 1: {
            int value;
            if (!readNumber("Nhap phan tu: ", value))
                return;
            values.push_back(value);
            cout << "Da them phan tu.\n";
            break;
        }
        case 2:
            if (values.empty()) {
                cout << "Vector dang rong.\n";
            } else {
                values.pop_back();
                cout << "Da xoa phan tu cuoi.\n";
            }
            break;
        case 3:
            cout << "So phan tu: " << values.size() << '\n';
            break;
        case 4:
            values.clear();
            cout << "Da xoa tat ca phan tu.\n";
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }
        pauseScreen();
    }
}

void menu_students_manage(StudentManager &manager) {
    while (true) {
        clearScreen();
        cout << "MENU STUDENT\n"
             << "1. Them sinh vien\n"
             << "2. Xoa sinh vien\n"
             << "3. Cap nhat sinh vien\n"
             << "4. Tim sinh vien theo ten\n"
             << "5. Hien thi danh sach\n"
             << "6. Sap xep theo GPA\n"
             << "7. Sap xep theo ten\n"
             << "8. Luu danh sach\n"
             << "0. Quay lai menu chinh\n";

        int choice;
        if (!readNumber("Nhap lua chon: ", choice) || choice == 0)
            return;

        switch (choice) {
        case 1:
            manager.addStudent();
            break;
        case 2: {
            int id;
            if (!readNumber("Nhap ID sinh vien can xoa: ", id))
                return;
            manager.removeStudent(id);
            break;
        }
        case 3: {
            int id;
            if (!readNumber("Nhap ID sinh vien can cap nhat: ", id))
                return;
            manager.updateStudent(id);
            break;
        }
        case 4: {
            string name;
            cout << "Nhap ten can tim: ";
            if (!getline(cin, name))
                return;
            manager.findStudent(name);
            break;
        }
        case 5:
            manager.displayAll();
            break;
        case 6:
            manager.sortByGPA();
            break;
        case 7:
            manager.sortByName();
            break;
        case 8:
            manager.saveFile();
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }
        if (cin.eof())
            return;
        pauseScreen();
    }
}

int main() {
    StudentManager manager;
    WeitaVector<int> values;
    manager.readFile();

    while (true) {
        clearScreen();
        cout << "Bai tap lon: Nguyen Duc Nguyen - 252601073\n"
             << "1. Demo vector\n"
             << "2. Quan ly sinh vien\n"
             << "0. Ket thuc chuong trinh\n";

        int choice;
        if (!readNumber("Nhap lua chon: ", choice) || choice == 0)
            break;

        switch (choice) {
        case 1:
            menu_demo_vector(values);
            break;
        case 2:
            menu_students_manage(manager);
            break;
        default:
            cout << "Lua chon khong hop le.\n";
            pauseScreen();
        }
    }
    return 0;
}
