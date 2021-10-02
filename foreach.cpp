#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    int a[]={10,20,30,40,50};
    for(int item:a){ // pythondaki for i in a ile aynı işlevi görüyor.
        cout<<"deger: "<<item<<endl;
    }



    getch();
    return 0;
}