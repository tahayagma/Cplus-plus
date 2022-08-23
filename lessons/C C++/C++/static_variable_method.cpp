#include <iostream>
#include <conio.h>

using namespace std;
/* fonksiyon tanımlanan degisken fonksiyon bittiginde bellekten silinirler. Ancat static olarak tanımlanan
 degiskenler fonksiyon bittikten sonra bellekten silinmezler*/
 
 void test(){

     int i = 4; // static deger olmadığı için func her çağrıldığında i degiskeni tekrar olusturulur ve 4 degerinde başlar ve aslında i++
     // hiç bir şekilde i degerini artırmaz.
     i++;
     cout<<"i'nin degeri: "<<i<<endl;
 }

 void static_test(){

     static int i = 10; // static olduğu için 10 olan deger kalıcı olur ve i++ olursa i degeri 11 olur.
     // func çağrıldığın i degeri tekrar olusturulmaz önceki tanımlı degerinden devem eder.
     i++;cout<<"static i degeri: "<<i<<endl;

 }

/* test func içinde tanılanan i degeri 4 iken 1 artılır 5 olur ve func biter  ve i degeri otomatik olarak bellekten silinir. */

int main(){

    test();
    test();
    test();

    static_test();// ilk çağrılışta 1 kere static i degeri tanımlanır. i = 10
    static_test();// sonraki çağırmada  static i tekrar olusturulmaz öncekinden devam eder. i = 11 olur ve silinmez
    static_test();

    getch();
    return 0;
}