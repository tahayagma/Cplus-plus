#ifndef _EMPLOYEE_
#define _EMPLOYEE_
#include "Employee.h"
// class yukarıda tanımlanmış gibi header dosyasını da yukarıda kısımda include ettik.

using namespace std;


void Employee::show(){

    cout<<"name: "<<name<<endl;
    cout<<"departman: "<<departman<<endl;
    cout<<"id: "<<id<<endl;
    cout<<"salary: "<<salary<<endl;

}

#endif