/**
* @file Test
* @description Faktöriyel hesaplama test aşaması
* @course A GRUBU
* @assignment 1.ÖDEV
* @date 31.07.2022
* @author Taha YAĞMA
*/

#include "Factorial.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(){

    int sayi;
    cout<<"sayi gir: ";
    cin>>sayi;
    Factorial f1,f2;
    ArrayList temp = f1.ToArray(sayi);
    for(int i=sayi-1;i>1;i--){
        ArrayList bsd = f2.ToArray(i);
        temp = f1.factorial(temp,bsd);
    }
    
    // DOSYA YAZDİRMA

    ofstream outfile("Sonuc.txt");

    if(!outfile){
        cout << "dosyas acma hatasi !";
    }
    else{
        for(int i: temp)outfile<<i<<"";
    }
    outfile.close();


    return 0;
}
