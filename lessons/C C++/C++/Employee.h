#ifndef _EMPLOYEE_H_ // alışıla gelen bir kural olarak dosyanın adı büyük h ile yazılır.
//if not define yani(ifndef) ile eger dosay tanımlanmamışsa define diyerek tanımladık.
#define _EMPLOYEE_H_
#include <iostream>

//using namespace std; isim uzayının hepsini dahil etmeye gerek yoktur. std::string ile yapılabilir.

class Employee{

    public:
        int id;
        int salary;
        std::string name;
        std::string departman;
        void show();// burası header dosyası olduğu için fonksiyonların sadece prototiplerini tanımladık.

};
#include "Employee.cpp"
/*fonksiyonların gövdelerinin tanımlı olduğu dosyayı içe aktardık. include işlemi aşağıdan olmak zorunda
aksi halde fonksiyonlrın gövdeleri sınıfın üst kısmında tanımlamış gibi olur. Hata verir.*/
#endif // yukarıda açılan if kapattık.