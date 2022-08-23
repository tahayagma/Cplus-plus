/*#include <iostream>
#include <conio.h>

using namespace std;

class Nokta{

    public: // pıblic belirtilmezse constructor çağrılmaz
    int x,y;

    Nokta(int x,int y){ // direk atama için constructor tanımlanı ve isimler class içinde ki ile aynı olduğundan this pointeri kullanıldı.
        cout<<"constructor cagrildi."<<endl;
        this->x = x;
        this->y = y;
    }

    void git(int posx,int posy){
        x = posx;
        y = posy;
    }

    //void sifir_mi(){
        if (x == 0 && y == 0)
            cout<<"nokta orjindedir."<<endl;
        else
            cout<<"noktalar orjinde degildir."<<endl;
        goster(); // noktlar orjinde degilse bulundukları noktlari göstermesi için aşağıda goster metodunu çağır
    }//
    bool sifirMi(){return (x==0 && y==0);} //eşitse 1 degeri yani true döner  degilse 0 yani false döner.

    void goster(){

        cout<<"x: "<<x<<"\n"<<"y: "<<y<<endl;;
    }
};



int main(){

    Nokta n(10,15); // constrcutor ile değerleri nesne ile gönderdik 
    n.goster(); // tanımlanan fonkistonu çağırdık
    n.git(0,25);
    n.goster();
    if (n.sifirMi())
        cout<<"Noktalar orjindedir"<<endl;
    else
        cout<<"orjinde degildir"<<endl;
        n.goster();
    
    getch();
    return 0;
}*/


/*#include <iostream>
#include <conio.h>

using namespace std;


class Nokta{

    public:
    const int s = 20; // bu degere buradan atama yapılamaz counstructor içinde atama yapılır. const int sabit = 10  hata verir. 
    int x,y;
    Nokta(int,int); // parametreli Constructor prototip tanımlandı
    Nokta(); //parametresiz constructor tanımlandı
    void goster();
    void git(int,int);
    bool sifirMi();
};
//ÖNEMLİ NOT: prototipler class içinde tanımlandıktan sonra func bodyler tanımlanırken func dönüş tipini de bildirmek gerekiyor.
Nokta::Nokta(int x,int y){
    cout<<"parametreli constructor cagirildi"<<endl;
    this->x = x;
    this->y = y;
};
Nokta::Nokta(){cout<<"Parametresiz Constructor cagirildi.";}

void Nokta::goster(){cout<<"x: "<<x<<"\n"<<"y: "<<y<<endl;}

void Nokta::git(int posx,int posy){x = posx;y = posy;}

bool Nokta:: sifirMi(){return (x==0 && y == 0);}


int main(){

    Nokta n1(100,150),n2(10,0); //Nokta sınıfından 2 adet nesne türetildi
    n1.goster();
    
    n2.sifirMi();

    if (n2.sifirMi())
        cout<<"Noktalar orjindedir."<<endl;
    else
        cout<<"orjinde degildir."<<endl;
        

    Nokta n3; // parametresiz kurucu cagrilir.
    cout<<"sabit: "<<n3.s<<endl;
    getch();
    return 0;
}*/

/*#include <iostream>
#include <conio.h>
#include <cstring>// str islemleri için include edilmesi gerekir

using namespace std;

class String{

    int boy;
    char *icerik;
    public:
    String(const char *); // kurucu fonksiyon
    String(const String & );// kopyalama kurucusu

    void goster();
    ~String(); // destructor
};

String::String(const char *gelen_veri){
    cout<<"kurucu calisti"<<endl;
    boy = strlen(gelen_veri);
    icerik = new char[boy+1];
    strcpy(icerik,gelen_veri);

}

String::String(const String &gelen_nesne){ // kopyalama kurucusu
    cout<<"kopyalama kurcusu calisti."<<endl;
    boy = gelen_nesne.boy;
    icerik = new char[boy+1]; // gelen nesnenin boyundan 1 falzası kadar yer ayrıldı. null karakteri için +1 olur.
    strcpy(icerik,gelen_nesne.icerik);// gelen_nesne içndeki içerik ile dinamik olarak ayrılan alana strcpy ile kopyalandı.
}

void String::goster(){
    cout<<"icerik: "<<icerik<<"\nboy: "<<boy<<endl;
}


String::~String(){  
    cout<<"destructor calisti."<<endl;
    delete [] icerik; // pointer ile ayrılan yer belleğe iade edildi
}

int main(){

    
    String string1("Katar 1"); // string1 nesnesine constructor ile veri gönderildi
    string1.goster();
    String diger = string1; // kopyalama kurucusu calisir.
    String baska(string1); // kopyalama kurucusu calisir.
    diger.goster();
    baska.goster();
    //string1.~String();
    
    
    getch();
    return 0;
}*/

//NESNELERİN FONSKİYONLARA REFERANS OLARAK AKATARILMASI
//  STATİK DEĞİŞKENLER STATİC FONKSİYON İLE SIFIRLANIR.

/*#include <iostream>
#include <conio.h>

using namespace std;

class Complex{

    float re,im;
    static unsigned int sayac; // unsigned işaretsiz tam sayılar 2 byte yer kaplar.0 dan 65535 e kadar
    public: 
    Complex(float re_in = 0,float im_in= 1);//parametreli bir kurucu tanımlandı ve parametrelere  varsayılan değerler atandı.
    Complex(const Complex &); //kopyalama kurucusu
    Complex topla(const Complex &) const;// alınan parametre const olduğu için fonksiyon da const türünde tanımlandı. dönüş değeri Complex türünde olacaktır.
    void goster() const;// sadece gosterme işlemi yapacağı için const olarak tanımlandı.
    static void sifirla(){sayac=0;};
    ~Complex(); //destructor 
};

// Kurucu
Complex::Complex(float re_in,float im_in){


    re = re_in;
    im = im_in;
    sayac++;
    cout<<"constructor calisti"<<endl;
    cout<<"Nesne sayisi: "<<sayac<<endl;
}
// Kopyalama Kurucusu

Complex::Complex(const Complex &c){
    re = c.re;
    im = c.im;
    sayac++;
    cout<<"Kopyalama kurucusu calisti"<<endl;
    cout<<"Nesne sayisi: "<<sayac<<endl;
}
Complex Complex::topla(const Complex &c) const{// ilk değer fonk. dönüş tipidir.
    cout<<"Toplama metodu calisti."<<endl;

    Complex sonuc; // fonk dönüş değeri Complex türünde olduğu için toplama işinden çıkan sonucu tutmak için Complex türünde sonuc nesnesi olusuturuldu.
    //yukarıdaki kullanım yerine gecici nesneler türetilebilir. böylelikle bellekte komple nesne yerine iki değişken türetilir.
    //float gecici_re,gecici_im;
    //gecici_re = re+c.re; // şeklinde değerler toplanıp gecici değişkene atanabilir.
    sonuc.re = re+c.re;
    sonuc.im = im+c.im;
    return sonuc; // return Complex(gecici_re,gecici_im) // nesne türeriliyor constructor calisir.
}
void Complex::goster() const{
    cout<<"re: "<<re<<"  im: "<<im<<endl;
}
Complex::~Complex(){

    sayac--;
    cout<<"destructor calisti."<<endl;
    cout<<"nesne sayisi: "<<sayac<<endl;
}
unsigned int Complex::sayac;// bellekte yer ayrildi

int main(){

    Complex::sifirla(); // önce sayac degeri sifirlandi.
    Complex z1(5,6),z2(2,8),z3; // üç tane nesne türetildi. // degerler verilmeyedebilir.Çünkü varsayılan degerleri atanmış.
    //burada toplam üç nesne türedildi. sonuc ile nesne sayisi 4 olur

    //(z1.topla(z2)).goster(); // bu şekilde return edilen değeri 1 kere yakalız nesne üretmekten kurarır.
    z3 =z1.topla(z2); // toplama işleminden return edien z3 atanıyor.
    z3.goster(); // goster ile z3 içine atananan deger basitiriliyor.


    getch();
    return 0;
}*/


// SINIFLARDA ARKADAŞLIK (FRİEND) İLİŞKİSİ
// CONSTRUCTORLAR SINIFIN PUBLİC ALTINDA OLMALI Kİ DIŞARIDAN ERİŞİME İZİN VERİLSİN.
/*#include <iostream>
#include <conio.h>

using namespace std;
class A{
    friend void sifirla(A &);// sifirla funk hiç bir sınıfa ati değiş ama yine friend olaral tanımlanabilir.
    //önce fonksiyon sonra sınuıf friend olarak belirlenir.
    friend class B; // B classı A nın arkadaşıdır tüm degerlere ulaşabilir.private dahil. 
    private:
    int i = 2303;
    float f;
    public:
    void func1(char *c);
};
void sifirla(A &n){// önce fonksiyon gövdesi tanımlandı.

    n.i = 0;
    n.f = 12.2;
}
class B{ // A sınıfı B sınıfındaki degerler erişemez. Arkadaşı değil
    int j;
    public:
    void func2(A &s){cout<<s.i;}// A sınıfında türetilen bir nesne referans alıp nesne üzerinden A classının tüm değerlerine erişebilir.
};




int main(){
    A a; // A sınıdından bir nesne türetildi.
    B b; // B sınfından bir nesne türedildi.
    b.func2(a); //B sınfındaki funck2 cağrıldı ve degerl olarak A sınıfından türetilen  a nesnesi verildi.
    sifirla(a);// hiç bir sınıfa ait olmayan funk ile sınıf verilerine erişim yapılır.
    b.func2(a);

    getch();
    return 0; 
}*/


// CLASS İÇİNDEN DİĞER SINIFLARA AİT ÜYE NESNELER TÜRETMEK VE CANLANDIRMAK
#include <iostream>
#include <conio.h>

using namespace std;

class Kesir{ // ComplexKes classından bu sınıftan nesne türetildiği için bu class yukarıda tanımlandı.
    int pay, payda;

    public:
    Kesir(int,int); // Consstructor

    void goster() const;
};

Kesir::Kesir(int py,int pyd){
    cout<<"Kesir constructor calisti"<<endl;
    pay =py;
    if (pyd == 0) payda = 1; // gelen payda 0 ise paydayı 1 eşitledik
    else payda = pyd;
}

void Kesir::goster()const{
    cout<<pay<<"/"<<payda<<endl;
}

class ComplexKes{
    Kesir re,im; // Kesir sınıfından iki tane nesne türetildi. ÜYE NESNELER

    public:
    ComplexKes(int ,int );// kurucu tanımlandı

    void goster() const; // değişime kapalı bir goster func tanımlandı.
};
ComplexKes::ComplexKes(int re_in,int im_in) : re(re_in,1),im(im_in,1){// türetilen re im nesnelerine değerler gönderildi
    cout<<"Kurucu calisti."<<endl;
    cout<<"Turetilen nesnelere degerler gonderildi."<<endl;
} 

void ComplexKes::goster() const{

    re.goster();
    im.goster();
}


int main(){

    ComplexKes ck(2,5);
    ck.goster();


    getch();
    return 0;
}

