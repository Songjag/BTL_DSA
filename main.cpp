#include <iostream>
#include "vector.h"
//#include <include/students.h>
//#include <include/students_manager.h>
using namespace std;

int main(){
    // int user_choice;
    // do{
    //     cout<<"Bai tap lon : Nguyen Duc Nguyen-252601073"<<endl;
    //     cout<<"Trinh bay:"<<endl;
    //     cout<<"1.Demo vector"<<endl;
    //     cout<<"2.Quan ly sinh vien"<<endl;
    //     cout<<"0.Ket thuc chuong trinh"<<endl;
    //     cin>>user_choice;
    //     switch (user_choice)
    //     {
    //     case 1:
    //         cout<<"Nguoi dung chon demovector";
    //         break;
    //     case 2:
    //         cout<<"Nguoi dung chon quan ly sinh vien";
    //         break;
        
    //     default:
            
    //         break;
    //     }
    // }
    // while (user_choice!=0);
    WeitaVector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.push_back(80);
    v.push_back(90);
    v.push_back(100);
    v.push_back(110);
    v.push_back(120);
    v.push_back(130);
    v.push_back(140);
    cout<<"Vector:";v.display();
    v.pop_back();
    cout<<"Vector:";v.display();

}