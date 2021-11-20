// + OPERATOR OVERLOADİNG

/*#include <iostream>
#include <conio.h>

using namespace std;

class Complex{
    double re,im;
    public:

    Complex(double re_in = 0,double im_in =1); // kurucu
    Complex operator+(const Complex &) const;// + operatörü overloading edilecek;
    // önce return type ardından opretor ve sonda sembol olarka syntax dizimi vardır.

    void goster() const;
};
//kurucu
Complex::Complex(double re_in,double im_in){
    cout<<"kurucu calisti"<<endl;
    re_in = re;
    im_in = im;
}
// + operatörü iki nesneyi toplayacak şekilde tanımlandı.
Complex Complex::operator+(const Complex &z)const{

    double yeni_re,yeni_im; // geçicic değişkenler tanımlandı

    yeni_re = re+z.re;
    yeni_im = im+z.im;

    return Complex(yeni_re,yeni_im);// return edildiğinde constructor çalışır.
}
void Complex::goster() const{

    cout<<"re: "<<re<<"\nim: "<<im<<endl;
}


int main(){

    Complex z1(1,1),z2(2,2),z3;
    //z1.operator+(z2).goster();
    z3 = z1.operator+(z2);
    z3.goster();

    getch();
    return 0;
}*/



#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

class String{

    int boy;
    char *icerik;
    public:
    String(); // parametresiz constructor
    String(const char *); // parametreleri contructor
    String(const String &); // kopyalama connstructor
    const String& operator=(const String &); // atama operatörü
    void goster() const;
    ~String(); // destructor (yok edici
};
String::String(){

    cout<<"parametresiz constructor calisti"<<endl;
    boy = 0;
    icerik = new char[1];
    strcpy(icerik,""); // boş karakter icerik  içine kopylandı.
}
// parametreli constructor
String::String(const char *gelen_veri){

    cout<<"parametreli constructor calisti"<<endl;
    boy = strlen(gelen_veri),
    icerik = new char[boy+1];
    strcpy(icerik,gelen_veri);
}

// kopyalama constructor
String::String(const String &gelen_nesne){ // yukarıdaki parmt.constructordan farklıdır nesne alır pointer değil,

    cout<<"koplayalama constructor calisti"<<endl;

    boy = gelen_nesne.boy;
    icerik = new char[boy+1];
    strcpy(icerik,gelen_nesne.icerik);
}
const String& String::operator=(const String &gelen_nesne){

    cout<<"atama operatoru calisti"<<endl;

    boy = gelen_nesne.boy;
    delete[] icerik;
    icerik = new char[boy+1];
    strcpy(icerik,gelen_nesne.icerik);
    return *this; // kendi adresini return ediyor
}

void String::goster() const{

    cout<<"boy:"<<boy<<"\nicerik: "<<icerik<<endl;
}

String::~String(){

    cout<<"destructor is running"<<endl;
    delete [] icerik;// pointer olduğu için [] ile silme işlemi yapılır.
}


int main(){

    String str1("katar 1");
    String str2 = str1; //  bu şekilde olan atamada kopyalama constructor calisir
    str2.goster();
    String str3,str4; // önce nesne türetilir.
    str3 = str4 = str2; // ardından atama overloading ile de nesnneler kopyalanır.
    str3.goster();




    getch();
    return 0;
}