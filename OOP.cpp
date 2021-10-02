#include <iostream>
#include <conio.h>

using namespace std;


/* class Employee{
    public://bu sınıflarki tüm değişkenlere ve metodlara her yere erişelebilir.
    string name;

    void getEmployee(int id ,string ad){

        cout<<id<<"' li "<<"sayin "<<ad<<name<<" sirketine hosgeldiniz";
    }

};
int main(){

    Employee employee1;//yukardıda tanımlanan class tan bir nesene türettik.structlara benzer.istendiği kadar türetilir.
    employee1.name="TheYagma SoftInc."; // class bulunan name degiskenine deger ataması yaptık.
    employee1.getEmployee(25,"Mahmut Tuncer");//class icindeki bir fonsiyona eriştik/



    getch();
    return 0;
} */


//CONSTRUCTORLAR(YAPICI METODLAR)
class Employee{
private:
    string name;
    int salary;

public:

    Employee(string Name,int maas){//constructor tanımlanması
        name= Name;
        salary= maas;
    }
    void setSalary(int maas){
        salary = maas*4;
    }

    int getSalary(){
        return salary;
    }

    void setName(string Name){
        name = Name;
    }
    string getName(){
        return name;
    }

    void show(){
        cout <<name<<salary<<endl;
    }
};

int main(){

    Employee employee("taha",4000);
    employee.getSalary();


    getch();
    return 0;
}