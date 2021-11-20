/* #include <iostream>
#include <conio.h>

using namespace std;


class apple{

    public:
        int salary;
        int age;
        string name;
    apple(int salary,int age,string name){
        this->salary = salary;
        this->age = age;
        this->name = name;
    }

    void yazdir(){


        cout<<"salary: "<<salary<<endl;
        cout<<"age: "<<age<<endl;
        cout<<"name: "<<name<<endl;
    }



};

int main(){

    apple app(1520,254,"taha");

    apple k2 = app; // biz özel olarak tanımlamadığımız sürece kopyalama kurcusu default olarak tanımlanır.
    k2.yazdir();// kopya ile olusan nesneden metod çağırdık.

    //app.yazdir();




    getch();
    return 0;
} */

