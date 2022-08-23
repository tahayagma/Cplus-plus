#include <iostream>
#include <conio.h>
#include "ArrayList.cpp"

using namespace std;

void factorial(ArrayList&,ArrayList&);
void topla(ArrayList&,ArrayList&);

int main(){
    
    ArrayList l1,l2;
    int n = 19;
    while(n>0){
        l1.push_back(n%10);
        n /=10; 
    }
    for(int *i = l1.begin();i<=l1.end();i++)cout<<*i<<" ";
    //factorial(l1,l2);
    


    getch();
    return 0;
}

void factorial(ArrayList & l1,ArrayList &l2){
    ArrayList c;
    ArrayList tmp;
    int elde= 0;
    int toplam = 0;
    for(int* i = l2.begin();i >=l2.end();i--){
        for(int* j = l1.begin();j >=l1.end();j--)
        {
            toplam = (*j)*(*i)+elde;
            if(toplam>9)
            {
                elde = toplam/10;
                c.push_back(toplam%10);
            }
            else
            {
                c.push_back(toplam);
                elde = 0;
            }
        }

        if(elde != 0)
        {
            c.push_back(elde);
            elde=0;
        }
        if(tmp.size() == 0)
            tmp = c;
        else
            topla(tmp,c);
        c.clear();
        //for(int*i = tmp.begin(); i <= tmp.end() ;i++){cout<<*i<<" ";}cout<<endl;
        //cout<<*(c.end())<<endl;
    }
}

void topla(ArrayList& l1,ArrayList& l2){
    ArrayList Z;
    int fark = (l1.size()-l2.size());
    if(abs(fark)>0)
    {
        if(l1.size()>l2.size())// list y ekleme yapılacak
        {
            for(int i= 0; i<abs(fark);i++)
                l2.push_back(0);
        }
        else
        {
            for(int i= 0;i<abs(fark);i++){l1.push_back(0);}
        }
    }
    //for(int*i = l1.begin(); i <= l1.end() ;i++){cout<<*i;};cout<<endl;
    //for(int*i = l2.begin(); i <= l2.end() ;i++){cout<<*i;};cout<<endl;

    int elde = 0;
    int toplam = 0;

    int *x = l1.begin();
    int *y = l2.begin();
    while(x <=l1.end() && y <=l2.end())
    {
        toplam =*x+*y+elde;

        if(toplam>9)
        {
            elde = toplam/10;
            Z.push_front(toplam%10);
        }
        else
        {
            Z.push_front(toplam);
            elde = 0;
        }
        toplam = 0;

        ++x;
        ++y;
    }
    if(elde !=0)
        Z.push_front(elde);
    elde= 0;
    for(int*i = Z.begin(); i <= Z.end() ;i++){cout<<*i;};cout<<endl;

}