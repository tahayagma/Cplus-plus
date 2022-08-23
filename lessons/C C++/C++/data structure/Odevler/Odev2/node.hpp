#ifndef NODE_HPP
#define NODE_HPP

class node{

    public:
    int dizi[1000]; // her bir satırı dizi olarak barındırıyor
    int ArrLen; // dizinin uzunluğunu temsil eder
    int data; // dizinin toplam değeri 
    node* left;
    node* right;
    node(int,int*,int,node*,node*);
};

#endif