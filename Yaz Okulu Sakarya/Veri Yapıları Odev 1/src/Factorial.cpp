/**
* @file Factorial(cpp dosyası)
* @description Factorial başlık dosyasının fonksiyon gövdesi gerçeklenmesi
* @course B GRUBU
* @assignment 1.ÖDEV
* @date 07.08.2022
* @author Taha YAĞMA
*/

#include "Factorial.hpp"
#include <math.h>

ArrayList& Factorial::ToArray(int value)
{   
    l.clear();
    int n = value;
    while(n>0){
        l.push_back(n%10);
        n /=10; 
    }
    return l;
}

ArrayList& Factorial::topla(ArrayList& lisX,ArrayList&lisY){
    Z.clear();
    int fark = (lisX.size()-lisY.size());
    if(abs(fark)>0){
        if(lisX.size()>lisY.size())// list y ekleme yapılacak
        {
            for(int i= 0; i<abs(fark);i++){lisY.push_back(0);}
        }
        else
        {
            for(int i= 0;i<abs(fark);i++){lisX.push_back(0);}
                
        }
    }
    int* x = lisX.begin();
    int* y = lisY.begin();
    int elde = 0;
    int toplam = 0;
    while(x <= lisX.end() && y <= lisY.end()) {
        
        toplam =*x+*y+elde;
        if(toplam>9)
        {
            elde = toplam/10;
            Z.push_back(toplam%10);
        }
        else
        {
            Z.push_back(toplam);
            elde = 0;
        }
        toplam = 0;

        ++x;
        ++y;
    }
    if(elde !=0){
        Z.push_back(elde);
    }
    elde= 0;
    //for(int*i = Z.begin(); i <= Z.end() ;i++){cout<<*i;};cout<<endl;
    return Z;
}

ArrayList& Factorial::factorial(ArrayList& l1,ArrayList& l2){
    ArrayList c;
    int elde = 0;
    int toplam = 0;
    tmp.clear();
    for(int* i = l2.begin();i <=l2.end();i++){
        for(int* j = l1.begin();j <=l1.end();j++)
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
        //for(int*i = c.begin(); i <= c.end() ;i++){cout<<*i;};cout<<endl;
        //for(int i : c)cout<<i<<" ";cout<<endl;
        if(tmp.size() == 0)
            tmp = c;
        else
            tmp = topla(tmp,c);
        c.clear();
    }
    //for(int*i = tmp.begin(); i <= tmp.end() ;i++){cout<<*i;};cout<<endl;
    return tmp;
}
