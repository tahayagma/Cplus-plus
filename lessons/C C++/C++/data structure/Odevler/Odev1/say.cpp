#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int main(){

   ifstream fin("deneme.txt"); 
    char character; long count = 0; 
    while (fin >> character) ++count; 
    cout << count; 
    getch();
    return 0;
}