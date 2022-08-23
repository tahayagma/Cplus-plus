#include <iostream>
#include <conio.h>
#include "ArrayList.cpp"



using namespace std;

int main(){

    ArrayList zero,l;
    zero.push_back(10);
    zero.push_back(20);
    l = zero;
    cout<<"l:"<<endl;
    for(int *i = l.begin();i<=l.end();i++)cout<<*i<<" ";
    l.push_back(30);
    cout<<endl;
    for(int *i = l.begin();i<=l.end();i++)cout<<*i<<" ";
    cout<<endl<<"zero: "<<endl;
    cout<<*(zero.begin());    


    getch();
    return 0;
}