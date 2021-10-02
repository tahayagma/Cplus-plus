#include <iostream>
#include <conio.h>

using namespace std;

int main(){

    /* int *ptr = new int;// bir int boyutu kadar(4 bayt) yer ayırdık
    *ptr = 10;// ayrılan alana bir deger ataması yaptık.

    delete ptr; // bu şekilde ayrılan belleği serbest bıraktık ve sildik.*/

    int *ptr;

    int size;

    cout<<"kac deger saklayacaksiniz: ";
    cin>>size;

    ptr = new int[size];//girilen size kadar int veri tipi için yer ayırdık.

    for (int i = 0; i <size; i++)
    {
        cout<<" deger gir: ";
        cin>>ptr[i];
    }
    
    for (int i = 0; i <size; i++)
    {
        cout<<"deger: "<<ptr[i]<<endl;
    }
    
    delete [] ptr; //ayrılantüm alan silinip bilgisayara verildi.


    getch();
    return 0;
}