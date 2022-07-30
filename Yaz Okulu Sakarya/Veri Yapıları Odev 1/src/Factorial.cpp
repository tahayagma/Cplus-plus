/**
* @file Factorial(cpp dosyası)
* @description Factorial başlık dosyasının fonksiyon gövdesi gerçeklenmesi
* @course A GRUBU
* @assignment 1.ÖDEV
* @date 31.07.2022
* @author Taha YAĞMA
*/


#include "Factorial.hpp"
#include <math.h>

ArrayList Factorial::ToArray(int value)
{   
    l.clear();
    int n = value;
    while(n>0){
        l.push_front(n%10);
        n /=10; 
    }
    return l;
}

ArrayList& Factorial::topla(const ArrayList& lisX,const ArrayList&lisY){
    ArrayList lx = lisX;
    ArrayList ly = lisY;
    Z.clear();
    int fark = (lx.size()-ly.size());
    if(abs(fark)>0){
        if(lx.size()>ly.size())// list y ekleme yapılacak
        {
            for(int i= 0; i<abs(fark);i++)
                ly.push_front(0);
        }
        else{
            for(int i= 0;i<abs(fark);i++){
                lx.push_front(0);
            }
                
        }
    }
    lx.reverse();
    ly.reverse();
    auto x = lx.begin();
    auto y = ly.begin();
    int elde = 0;
    int toplam = 0;
    while(x != lx.end() && y != ly.end()) {
        
        toplam =*x+*y+elde;
        if(toplam>9){
            elde = toplam/10;
            Z.push_front(toplam%10);
        }
        else{
            Z.push_front(toplam);
            elde = 0;}
        toplam = 0;

        ++x;
        ++y;
    }
    if(elde !=0){
        Z.push_front(elde);
    }
    elde= 0;
    return Z;
}

ArrayList& Factorial::factorial(ArrayList& l1,ArrayList& l2){
    ArrayList c;
    int elde = 0;
    int toplam = 0;
    tmp.clear();
    l1.reverse();
    l2.reverse();
    for(int i : l2){
        for(int j: l1)
        {
            toplam = j*i+elde;
            if(toplam>9)
            {
                elde = toplam/10;
                c.push_front(toplam%10);
            }
            else
            {
                c.push_front(toplam);
                elde = 0;
            }
        }
        if(elde != 0)
        {
            c.push_front(elde);
            elde=0;
        }
        if(tmp.size() == 0)
            tmp = c;
        else{
            tmp = topla(tmp,c);
            }
        c.clear();
    }
    return tmp;
}
