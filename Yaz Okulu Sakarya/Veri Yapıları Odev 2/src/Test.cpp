#include <iostream>
#include <sstream>
#include <fstream>
#include "AvL.hpp" // avl ağaç (lisked list ile )
#include "Radix.hpp" // Radix sıralama

using namespace std;


int main(){
    int counter = 0;
    int SayiDizi[1000];
    Radix l;
    AVL avl;
    int * p;
    ifstream dosya("sayilar.txt");
    int topla =0;
    string str;
	if(dosya.is_open())
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
	
    return 0;
}
