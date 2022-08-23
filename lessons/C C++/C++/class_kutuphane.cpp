#include <iostream>
#include <conio.h>
#include "Employee.h"// tanımladığımız header dosyasını içeri aktardık

using namespace std;

int main(){
    Employee emp;//Employee.h içinde tanımlanan classtan bir nesne türettik.
    Employee Emp;
    string ad;
    cout<<"login name: ";cin>>ad;
    emp.name =ad; // nesne ile classa deger gönderdik.
    emp.id = 14;
    emp.salary = 2500;
    emp.departman = "computer science";
    Emp.name = "ikinci emp";
    Emp.salary = 5252;
    Emp.id = 220;
    Emp.departman = "IT";
    emp.show(); // Employee.cpp dosyasında tanımlanan fonksiyoun çağırıp veriler bastırdık.
    Emp.show();


    getch();
    return 100;
}