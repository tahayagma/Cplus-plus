/**
* @file Test
* @description Faktöriyel hesaplama test aşaması
* @course A GRUBU
* @assignment 1.ÖDEV
* @date 31.07.2022
* @author Taha YAĞMA
*/

#include "Factorial.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(){

    int sayi;
    cout<<"sayi gir: ";
    cin>>sayi;
    Factorial f1,f2;
    ArrayList temp = f1.ToArray(sayi);
    for(int i=sayi-1;i>1;i--){
        temp = f1.factorial(temp,f2.ToArray(i));
    }
	
	cout<<"temp size: "<<temp.size()<<endl;
	cout<<"temp capacity: "<<temp.capacity()<<endl;
    
    // DOSYA YAZDİRMA

    ofstream outfile("Sonuc.txt");

    if(!outfile){
        cout << "dosya acma hatasi !";
    }
    else{
        for(int * i = temp.end();i >=temp.begin();i--)outfile<<*i<<"";
    }
    outfile.close();
    
    return 0;
}
