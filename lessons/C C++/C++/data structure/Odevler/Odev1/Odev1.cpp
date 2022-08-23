#include <iostream>
#include <conio.h>
#include <list>

using namespace std;

list<int> ToArray(int);
list<int> factorial(list<int>,list<int>);

list<int> topla(const list<int>&, const list<int>&);

int main(){
    int sayi = 20;
    list<int>tmp = ToArray(sayi);
    //tmp = factorial(tmp,ToArray(10));
    for(int i = sayi-1;i>1;i--){
        tmp = factorial(tmp,ToArray(i));
    }
    /*for(int b:tmp){
        std::cout<<b;
    }*/
    getch();
    return 0;
}

list<int> ToArray(int x){//0-9
    list<int>l;
    int n = x;
    while(n>0){
        l.push_front(n%10);
        n /=10; 
    }
    return l;
}

//
list<int> factorial(list<int>l1,list<int>l2){
    list<int>c;
    list<int>c2;
    int elde = 0;
    int toplam = 0;
    l1.reverse();
    l2.reverse();
    list<int>tmp;
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
    for(int b: tmp)
        cout<<b<<" ";
    cout<<endl;
    return tmp;
}

list<int> topla(const list<int>& lisX, const list<int>& lisY) {
    list<int> Z;
    list<int>lx = lisX;
    list<int>ly = lisY;
    int fark = (lisX.size()-lisY.size());
    if(abs(fark)>0){
        if(lisX.size()>lisY.size())// list y ekleme yapılacak
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
    /*for(int i : Z){
        cout<<i<<" ";
    }*/
    return Z;
}
