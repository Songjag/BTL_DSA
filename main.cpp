#include <iostream>
#include "vector.h"
#include <limits>
//#include <include/students.h>
//#include <include/students_manager.h>
using namespace std;
void clearScreen() {
    cout << "\033[2J\033[H" << flush;
}
void pauseScreen() {
    cout << "\nNhan Enter de tiep tuc...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void displayVector(const WeitaVector<int>& values) {
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
void menu_demo_vector(){
    static WeitaVector<int> a;
    int choices = -1;

    do {
        clearScreen();
        cout << "Demo vector :\n";
        cout << "Vector hien tai (" << a.size() << " phan tu): ";
        displayVector(a);
        cout << "\n1. Push phan tu\n"
             << "2. Pop phan tu cuoi\n"
             << "3. Xem kich thuoc hien tai\n"
             << "4. Clear vector\n"
             << "0. Quay lai menu chinh\n"
             << "Nhap lua chon cua ban: ";

        if (!(cin >> choices)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Lua chon khong hop le.\n";
            pauseScreen();
            continue;
        }

        switch (choices) {
        case 1: {
            int value;
            cout << "Nhap phan tu can push: ";
            if (cin >> value) {
                a.push_back(value);
                cout << "\n[+] Push thanh cong!\n";
                cout << "Vector sau khi push: ";
                displayVector(a);
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Phan tu khong hop le.\n";
            }
            pauseScreen();
            break;
        }
        case 2:
            if (a.empty()) {
                cout << "Vector dang rong, khong the pop.\n";
            } else {
                a.pop_back();
                cout << "[+] Pop thanh cong!\n";
            }
            cout << "Vector sau khi pop: ";
            displayVector(a);
            pauseScreen();
            break;
        case 3:
            cout << "Kich thuoc hien tai: " << a.size() << '\n';
            pauseScreen();
            break;
        case 4:
            a.clear();
            cout << "Da clear vector. Vector hien tai: ";
            displayVector(a);
            pauseScreen();
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le.\n";
            pauseScreen();
            break;
        }
    } while (choices != 0);
}
void menu_students_manage(){
    clearScreen();
    cout<<"Ban da chon: Quan ly sinh vien"<<endl;




    pauseScreen();
}
void menu_main(){
    int user_choice;
    do{
        cout<<"Bai tap lon : Nguyen Duc Nguyen-252601073"<<endl;
        cout<<"Trinh bay:"<<endl;
        cout<<"1.Demo vector"<<endl;
        cout<<"2.Quan ly sinh vien"<<endl;
        cout<<"0.Ket thuc chuong trinh"<<endl;
        cin>>user_choice;
        switch (user_choice)
        {
        case 1:
            menu_demo_vector();
            break;
        case 2:
            menu_students_manage();
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le.\n";
            pauseScreen();
            break;
        }
    }
    while (user_choice!=0);
}
int main(){
    menu_main();
    return 0;
}