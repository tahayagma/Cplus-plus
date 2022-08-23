#include <iostream>
#include <conio.h>
/* destructorlar icin  pointerlerin olması gerekir. pointer ile bellekten ayrılan yerin destructor ile 
delete diyerek bellege geri verilmesi gerekir. Aksi halde bellek sızıntısı meydana gelir. */

using namespace std;

class Employee{

    public:
    string *s;
    int *i;

    Employee(string st,int in){
        cout<<"constructor called;"<<endl;
        /* önde constructor çağrılacağı içn yukarıda tanımlana pointerlar için dinamik yer tahsisi yaptık */
        s = new string;
        i = new int;

        *s = st; // tanımlanan pointerlere gelen degerleri atadık.
        *i = in;
    }

    ~Employee(){
        delete s;
        /* eger pointer olarak tanımlanan degiskenleri destructor içinde silmezsek main icinde olusturulan
        pointer nesnesi silinse dahi bu degiskenler bellekte yer tutmaya devam edecektir. ayrı olarak 
        silinmesi lazımdır. */
        delete i;
        cout<<"destructor called"<<endl;
    }
    void display(){
        cout<<"name: "<<*s<<" age : "<<*i<<endl;
    }
};




int main(){

    Employee  *emp = new Employee("taha",262);
    /*emp adında bir pointer olusturup new diyerek Employee classından bir yer ayırdık  ve 
    constructor sayesinde verilerimizi gönderdik.*/
    emp->display();// pointer olduğu için -> ile func çağırdık.
    delete emp;// emp pointeri main içinde tanımlandığı için burada siliyoruz.

    getch();
    return 0;
}