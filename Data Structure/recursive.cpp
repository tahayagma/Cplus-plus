#include <iostream>
#include <conio.h>

using namespace std;

int fak(int n ){
    if(n == 0)
        return 1;
    return n*fak(n-1);
}

int fib(int n){
    if(n == 0)
        return 1;
    return fib(n-1)+fib(n-2);
}

int topla(int n){
    if(n == 0)
        return 0;
    return n+topla(n-1);
}


void b(int n){
    if(n>1)
        b(n/2);
    cout<<n%2;
}
int main(){

    b(14);
    getch();
    return 0;
}
