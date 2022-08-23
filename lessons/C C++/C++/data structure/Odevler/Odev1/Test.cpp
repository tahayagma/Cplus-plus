/**
* @file Test
* @description Faktöriyel hesaplama test aşaması
* @course A GRUBU
* @assignment 1.ÖDEV
* @date 31.07.2022
* @author Taha YAĞMA
*/

#include "Factorial.cpp"
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int main(){

    int sayi;
    cout<<"sayi gir: ";
    cin>>sayi;
    Factorial f1,f2;
    ArrayList temp = f1.ToArray(sayi);
    //ArrayList bsd = f2.ToArray(10);
    for(int i=sayi-1;i>1;i--){
        //bsd = f2.ToArray(i);
        temp = f1.factorial(temp,f2.ToArray(i));
    }
    cout<<"temp size: "<<temp.size()<<endl;
    cout<<"temp cap: "<<temp.capacity();
    //for(int * i = temp.begin();i<=temp.end();i++)cout<<*i;
    // DOSYA YAZDİRMA

    ofstream outfile("deneme.txt");

    if(!outfile){
        cout << "dosya acma hatasi !";
    }
    else{
        for(int * i = temp.end();i >=temp.begin();i--)outfile<<*i<<"";
    }
    outfile.close();
    //exit(1);


    getch(); 
    return 0;
}
