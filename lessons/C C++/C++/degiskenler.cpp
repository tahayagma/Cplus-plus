#include <iostream>
#include <conio.h>

using namespace std;
/* // fonksiyon oluşturdukç
void test(){

     static int a = 14;
    a++;
    cout<< "a'nin degeri: "<<a<<endl;
}
// fonksiton içinde tanımlanan tüm degiskenler fonsiyon bittikten sonra otomatik olarak silinir.
//Ancak degiskenin başına static ifadesi gelirse degisken program boyunca geçerli olur ve eşsiz olur.
// yani python bilinen değişken mantığı olur aynı isimde başak değişken olamaz yoksa çarşı pazar karışır.

int main(){

    int i = 1;
    while (i<=5)
    {
        test();
        i++;
    }
    
    //test(); // oluşturulan fonksiyonu çağırdık.


    getch();
    return 0;
} */

// STATİK SINIF ÜYELERİ

/* class Gamer{
public:
    static int gamers;// buradan gamers değişkenine deger veremeyiz hata verecektir
    Gamer(){
        gamers++;
        cout<<"yeni oyuncu olusturuldu."<<endl;//endl demezsek yan yana yazar.
    }
};
int Gamer::gamers=0; // bu şekilde sınıf içindeki bir degiskene ulaşıp deger verdik
int main(){

    Gamer gamer1;
    Gamer gamer2;
    Gamer gamer3;
    Gamer gamer4;

    cout<<Gamer::gamers<<endl;
    


    getch();
    return 0;
} */

// SINIFARIN STATİK METODLARI

/*class matematik{


public:
    
    static void cube(int x){

        cout<<x*x*x<<endl;
    }
    static void add2(int x){


        cout<<x+2<<endl;
    }
};

int main(){

    matematik::cube(6); // fonksiyon içinden oluşturduğumuz fonksiyon alışı deger gönderdik.
    matematik::add2(18); // static olmazsa bu şekilde ulaşamayız error raise


    getch();
    return 0;
}*/

// FRIEND FONKSIYONLAR VE SINIFLAR


/* class Employee{

private:
    string name;
    int salary;
    int age;
public:
    Employee(string name,int age, int salary){

        this->name = name; // burada aynı class içinde private degişkenlere this pointeri ile erişebiliyoruz
        this->age = age;
        this->salary = salary;
    }
    friend void showInfos(Employee employee);// bu sınıfın dışında tanımlanan bir fonksiyonun class içindeki private degerlere erişmesini
    // istersek class için fonksiyonu friend olarak belirtmemiz gerekir. aksi halde private degerlere erişemez.
};

void showInfos(Employee employee){

    cout<<employee.name<<" "<<employee.age<<" "<<employee.salary<<endl; // friend olarak belirtilmeyen fonk ile private alanına erişim yapamaz
}

int main(){

    Employee employee("Taha",25,200);
    showInfos(employee);

    
    getch();
    return 0;
} */


class Employee{

private:
    string name;
    int age;
    int salary;
public:
    Employee(string name, int age, int salary){

        this->name= name;
        this->age = age;
        this->salary= salary;

    }
    friend class test; // bu şekilde de classları friend olarak tanımlıyoruz
};

class test{

public:
    static void showInfos(Employee employee){

        cout<<employee.name<< " "<<employee.age<<" "<< employee.salary<<endl;
    }
};

int main(){
    Employee employee("Taha",25,4400);
    test::showInfos(employee);


    getch();
    return 0;
}