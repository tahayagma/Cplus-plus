#include <iostream>
#include <conio.h>
#include <sstream>
#include <fstream>
#include "AvL.cpp" // avl ağaç (lisked list ile )
#include "Radix.cpp" // Radix sıralama

using namespace std;


int main(){
    int counter = 0;
    int SayiDizi[1000];
    Radix l;
    AVL avl;
    int * p;
    int sayi;
    
    ifstream dosya("sayilar.txt");
    int topla =0;
    string str;
    while(getline(dosya, str)) 
    {
        istringstream ss(str);
        int num;
        while(ss >> num)
        {   
            SayiDizi[counter++] = num;
            topla += num;
        }
        p = l.radix(SayiDizi,counter);
        avl.insert(topla,p,counter);
        topla = 0;
        counter = 0;
    }
    avl.preorder();
    dosya.close();

    

    getch();
    return 0;
}
