/* #include <iostream>
#include <conio.h>
using namespace std;

void degerdegistir(int);
/*bu aslında call by value yani deger ile çağırma işlemidir. Bu yöntemle fonskiyona  sadece sayinin degerini
göndermiş oluyoruz. Ve herhangi bir değişiklik yapamıyoruz.
void degerdegistirPtr( int *);*/
/*referans ile çağırma işleminde fonskiyona sayinin bellekteki adresini göndermiş oluyoruz. Bu sayede
o değişkene doğrudan erişmiş oluruz ve değişiklik yapabiliriz.*/
/* int main()
{  
   int sayi= 10;
   cout << "sayi degeri: "<< sayi<< endl;
   degerdegistir(sayi);
   cout << "fonksiyona gonderildikten sonra sayi :"<< sayi<< endl;
   cout<< "__________________________________________________"<<endl;
   // call by referance(pointer ile yani referans ile çağırma)
   cout << "sayi degeri(call by referance): "<< sayi<< endl;
   degerdegistirPtr(&sayi);// burada sayi degiskeninin adresini göndermiş olduk.
   cout << "fonksiyona gonderildikten sonra sayi(call by referance) :"<< sayi<< endl;


   getch();
   return 0;
}

void degerdegistir(int sayi){

   sayi = 50;
   cout<< "fonksiyon icindeki sayi:"<<sayi<< endl;

}
void degerdegistirPtr( int *sayi){ // pointer olarak çağırma call by referance
   *sayi = 100;
   cout<< "fonksiyon icindeki sayi(call by referance):"<<*sayi<< endl;
} */
/*call by value ile main içinde tanımlanan degisken degeri gönderilirken call by referance ile main içinde
 tanımlanan degişkenin bellekteki adresini göndermiş oluyor.*/

/* void printarray(const int*,const int*);

 #include <iostream>
 #include <conio.h>

 using namespace std;


 int main(){
   
   
  /*  int array[]= {1,2,3,4};
    
   /* cout << "array: "<<array<<endl;// arrayin başlangiç adresini verir.
   cout<<"array +1:"<<array+1<<endl;// ikinci değerin adresini verir. int degerler 4 bayt yer kapladığı için ilk degere
   //4 eklenir ve sonraki degerin başlangiç adresini getirir
   cout <<"array +2:"<<array+2<<endl;// bu da ikinci degerin adresine 4 ekler ve sonraki degerin(3) adresini getirir.
   
   int *ptr = array;// arrayin başlangiç adresinin tutar.

   cout<<"ptr en bastaki degeri:"<<ptr<<endl;
   cout<<"ptr + 1:"<<ptr+1<<endl;// bir sonraki degerin başlangiç adresini getirir.int için 4 bayt kadar ekler

   //pointeri bir sonraki deger götürmek istersek
   ptr = ptr+1;
   cout <<"pointerin yeni degeri :"<<ptr<<endl;
   cout<<"pointer adresinden degeri cekme(*ptr): "<<*ptr<<endl;

   ptr = &array[2];//bu şekilde arrayin 2 indexteki yani 3 degerinin adresini atamış olduk baştki ampersant adresi tutuyor.

   cout<<"ptr ye ikinci index adresi atandi :"<<ptr<<endl;

   string array2[]={"taha","yagma","ces"};

   string *ptr2  = array2;

   cout<<"ptr2+1: "<<ptr2+1<<endl;// string arrayin 1 index adresini çektik
   cout<<"*(ptr2+1): "<<*(ptr2+1)<<endl;// ve bu paranteze oalıp yıldız koyarsak o adreste hani deger varsa onu return eder.
   cout<<"ptr2+1: "<<ptr2[1]<<endl;// yukarıdaki *(ptr2+1) ile aynı işlemi yapar.



   // pointerler ve const

   int array[] = {10,20,30,40,50,60,70,80,90,100};

   printarray(array+2,array+7);//burada + ile arrayin 2 indexine ve 7 ile de 7 indexinini adresini atamış oldu.


    getch();
    return 0;
 }

 void printarray(const int *ptr1,const int *ptr2){
    /*burada const ile tanımlanan pointerlerin adresi değişebilir ama o adresteki deger const olduğu için
    değiştirilemez. Yani 30'un adresini taşıyan pointer deger 60'ın adresine değiştirebilir ama 30 ce 60 
    degerleri pointer ile değiştirelemezler
    *ptr1 = 100;// bu şekilde hata verecektir çünkü degeri const ile tanımlanan pointerin gösterdiği adresteki(adres değişir) degeri değiştirmeye çalışıyoruz.
    for (;ptr1 != ptr2;ptr1++)
    {
       cout << "eleman: "<<*ptr1<< endl;
    }
    

 } */



 //  POİNTERLER VE YAPILAR

 #include <iostream>
 #include <conio.h>

 using namespace std;

struct employee
{
   int id;
   string name;
   string department;
};


 int main(){

    employee Employe1 = {147,"taha","yazılım"};

    employee *ptr = &Employe1; // yukarıda tanımlanan employee1 struct adresi verilmiş oldu.

   cout<<"Normal sekilde strcut elemanlarina erisim(Employe1.name): "<<Employe1.name<<endl;
   cout <<"ptr ile struct elemanlarina erisim(ptr->name): "<<ptr->name<<endl;

    getch();
    return 0;
 }