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
        ArrayList bsd = f2.ToArray(i);
        temp = f1.factorial(temp,bsd);
    }
    
    // DOSYA YAZDİRMA

    ofstream outfile("Sonuc.txt");

    if(!outfile){
        cout << "dosyas acma hatasi !";
    }
    else{
        for(int * i = temp.end();i >=temp.begin();i--)outfile<<*i<<"";
    }
    outfile.close();
    


    


    //DEBUG


    /*ArrayList l1,l2;
    l1.push_front(10);
    l1.push_front(20);
    cout<<"l1: ";
    for(int a: l1) cout<<a<<" ";cout<<endl;
    l2 = l1;
    l2.push_front(25);
    cout<<"l2: ";
    for(int a: l2) cout<<a<<" ";cout<<endl;
    cout<<"l1: ";
    for(int a: l1) cout<<a<<" ";cout<<endl;
    l1 = l2;
    cout<<"l1: ";
    for(int a: l1) cout<<a<<" ";cout<<endl;
    l2.clear();
    cout<<"l2: ";
    for(int a: l2) cout<<a<<" ";cout<<endl;*/

    return 0;
}
