#ifndef AVL_HPP
#define AVL_HPP
#include "node.hpp"

class AVL{
    node * root;
    int height(node*);
    
    public:
    
    AVL();
    int height();// node yüksekliğini döndürür
    int balancefactor(node*);// height metodundan değerler ile sağ ve sol altağaçlar arasındaki farkı alır
    node* ll_rotate(node*); // sol sol dengesizliği
    node* rr_rotate(node*); //sağ sağ dengesizliği
    node*query(node*); // balancefactor metodundan dönen değer ile dengesizlik duruma göre döndürme yapar
    node* insert(int,int*,int,node*); // düğüm ekleme
    void insert(int,int*,int);
    void preorder(node*); // düğüm değerini ve düğüm dizisini yazdırma
    void preorder();
};

#endif