#include <iostream>
//#include <include/vector.h>
//#include <include/students.h>
//#include <include/students_manager.h>
using namespace std;

int main(){
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
            cout<<"Nguoi dung chon demovector";
            break;
        case 2:
            cout<<"Nguoi dung chon quan ly sinh vien";
            break;
        
        default:
            
            break;
        }
    }
    while (user_choice!=0);
}