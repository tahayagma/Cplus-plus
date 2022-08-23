#include <iostream>
#include <conio.h>

using namespace std;

class Column{
    int *data;
    int boyut;
    public:
        Column(int boyut){// constructor tanımladık
            data = new int[boyut];
            cout<<boyut<<" elemanli bir dizi olustu."<<endl;
        }

        Column(const Column& c){
            this->boyut = c.boyut;
            data = new int[boyut];

            for (int i = 0; i <boyut; i++)
                data[i] = c.data[i];
            cout<<"Kopyalama kurucusu calisti."<<endl;
        }

        ~Column(){delete[] data;cout<<"yikici calisti";}
        // data verisi bir array olduğu için delete [] şeklinde silmemiz gerekiyor.

        /* int getBoyut(){return boyut;}
        void setBoyut(int boyut){this->boyut = boyut;} */

        void print()const{
            for (int i = 0; i < boyut; i++)
                cout<<data[i]<<" ";
            cout<<endl;
        }
};

int main(){

    Column c(1);
    c.print();
    c.~Column();// destructor çağrildi.
  
    getch();
    return 0;
}