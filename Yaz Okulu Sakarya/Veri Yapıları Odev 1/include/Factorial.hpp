/**
* @file Factarial (Başlık Dosyası)
* @description Faktöriyel hesaplama
* @course A GRUBU
* @assignment 1.ÖDEV
* @date 31.07.2022
* @author Taha YAĞMA
*/

#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP
#include ".\ArrayList.hpp"

using namespace std;

class Factorial{
    
    ArrayList l,Z,tmp;

    public:
    ArrayList ToArray(int);// girilen sayıyı ArrayListe çevirme
    ArrayList& factorial(ArrayList&,ArrayList&);// sayıların çarpılıp toplama işlemi için topla fonk. gönderilmesi
    ArrayList& topla(const ArrayList&,const ArrayList&); // yanlış toplama işleminin yapılması.

    
};

#endif