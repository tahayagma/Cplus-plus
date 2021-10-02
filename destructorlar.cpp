#include <iostream>
#include <conio.h>

using namespace std;

class Employee{

public:
    string *s;
    int *i;

    Employee(string str,int ivalue){
        s= new string;
        i = new int;
        *s = str;
        *i=  ivalue;
        cout<<"Constructor cagrildi.";
    }
    void show(){

        cout<<" String deger: "<<*s<<" int deger: "<<*i<<endl;
    }
    ~Employee(){
        delete s; //bu şekilde obje içinde ayrılan alanları da silememiz gerekir aksi halde bellek sızınıtısı meydana gelir.
        delete i;
        cout<<"Destructor cagrildi";
    }

};


int main(){

    Employee *emp = new Employee("Taha yagma",145);
    emp->show();

    delete emp; // bu şekilde destructor çağrılır ve objeyi siler.

    getch();
    return 0;
}