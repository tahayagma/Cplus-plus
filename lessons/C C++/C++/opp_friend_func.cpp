#include <iostream>
#include <conio.h>

using namespace std;


class A{
    private:
        int x;
    public:
        void setx(int);
        int getx();

    friend void Foo(A&);

};

int A::getx(){ return x;}

void A::setx(int _x){ x = _x;}

void Foo(A&a){cout<<a.x;}

int main(){

    A n; // A classından bir nesne türettik.
    n.setx(20); // stx adındaki fonksiyonu çağırarak x degeri gönderdik.
    cout<<n.getx()<<endl; // x degeri return edecek func çağırdık

    Foo(n);
    cout<<n.getx();



    getch();
    return 0;
}