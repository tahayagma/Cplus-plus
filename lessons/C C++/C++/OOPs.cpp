#include <iostream>
#include <conio.h>

using namespace std;

    // TEMEL
/* class mat{
    public:
    int x,y;
    void atama(int _x,int _y){ // void atama bir deger döndürmüyor harici girilen degerleri classta tanımlanan x ve y ye atamasını yapıyor

        x= _x;
        y = _y;
    }
    int topla(){ // dışarıdan deger almadı classta tanımlana x ve y degerleri kullandı. ondan dolayı fonksiyob parametre almadı.

        return x+y;
    }

    int carp(){

        return x*y;
    }

}; */

class idn{

    public:
    int x,y;
    
    void ata(int _x,int _y){

        x = _x;
        y= _y;
    }

    void yaz(){

        cout<<"x: "<<x<<"  y: "<<y<<endl;
    }
    int cikarma(){
    
        return x-y;

    }
    bool zero(){

        return x-y>0;
    }
};


int main(){

        // TEMEL
    /* mat n; // mat classından n adında bir nesne türettik.
    n.atama(4,5);
   cout<<n.topla()<<endl;
   cout<<n.carp(); */

    // POİNTER VE DİZİ İLE CLASSLAR
    idn b;
    idn *p; // pointer olustur
    idn array[10]; // burada her dizi bir pointer olduğu için aslında 10 tane nesne ürettik.
    idn *Parray; Parray = new Nokta[10] // yukarıda tanımlanan array[10] ile aynı işlemdir.
    p = new idn(); // poinere degerine new diyerek classtan bir nesne ürettik. kullanımı p-> seklinde olur.
    b.ata(6,5);
    cout<<b.cikarma()<<endl;
    cout<<b.zero()<<endl;


    getch();
    return 0;
}