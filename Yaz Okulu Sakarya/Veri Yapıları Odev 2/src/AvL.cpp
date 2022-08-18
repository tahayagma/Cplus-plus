#include "AvL.hpp"
//#include "node.cpp"
#include <iostream>
using namespace std;

int AVL::height(node* Node){
    if(Node){
        int left = height(Node->left);
        int right = height(Node->right);
        return 1+std::max(left,right);
    }
    else
        return 0;
};
AVL::AVL(): root(NULL){};
int AVL::height(){return height(root);}

int AVL::balancefactor(node* Node){
        return height(Node->left)-height(Node->right); // mutlak değerce 1 den büyükse dengesizlik vardır. (-1,0,1) alabilir.
    }
node* AVL::ll_rotate(node* Node){
        node* temp = Node->left;
        Node->left = temp->right;
        temp->right = Node;
        return temp; // bozulan düğüdemden sonraki düğümü return edecek eklemede ebeveyn ile bağlant kursun
    }

node* AVL::rr_rotate(node* Node){
        node* temp = Node->right;
        Node->right = temp->left;
        temp->left = Node;
        return temp;
    }
node* AVL::query(node* Node){
        int h = balancefactor(Node);
        if(abs(h)>1){ // fark mutlak değerce 1 den büyükse dengesizlik vardır.
            if(h>1){// sol-sol yada sol sağ dengesizliği vardır.
                if(!Node->left->right){// sola eklenme vardır.ve sol-sol dengeziliği vardır.
                    Node = ll_rotate(Node);}
                else{ //sağa eklenme vardır ve sol-sağ dengesizliği vardır.
                    Node->left = rr_rotate(Node->left);
                    Node = ll_rotate(Node);
                }
            }
            else{ // 1 den küçükse sağ-sağ yada sağ sol dengesizliği vardır.
                if(!Node->right->left){// sağ eklenme vardır.ve sağ-sağ dengeziliği vardır.
                    Node = rr_rotate(Node);}
                else{ //sola eklenme vardır ve sağ-sol dengesizliği vardır.
                    Node->right = ll_rotate(Node->right);
                    Node = rr_rotate(Node);
                }
            }
        }
        return Node;
    }
    
    int d = -1; // seviyeyi temsil eder.
    int c = 0;
    int array[1000]; // düğümlerin önceki seviye değerleri tutar
node * AVL::insert(int value,int* dizi,int ArrLen, node*Node){
        d++;
        if(!Node){ // node boş ise
            array[c] = value;
            array[c+1] = d;
            c +=2;
            d = -1;
            return new node(value,dizi,ArrLen,NULL,NULL);//new node(value); // verilen değeri yeni bir düğüm olarak ekle
            } 
        else// boş değilse
            if(value<Node->data){// eğer value düğümün datasından küçükse sol için fonksiyon tekrar çağrılıyor.
                Node->left = insert(value,dizi,ArrLen,Node->left);
                }
            else{// değilse de sağ için fonksiyon çağrılıyor
                
                Node->right = insert(value,dizi,ArrLen,Node->right);
                }
            Node = query(Node);
        return Node;
    }

void AVL::insert(int value,int* dizi,int ArrLen){root =  insert(value,dizi,ArrLen,root);}


int sonraki = -1; // düğümlerin dengelendikten sonraki seviye değerlerini tutar
void AVL::preorder(node * root){
    sonraki++;
    int counter = 0;
    if(root){
            for(int i= 0;i<c+2;i=i+2){
                if(array[i] == root->data){
                    int islem = array[i+1]-sonraki;
                    if(islem<0){// aşağı yönde-- en büyük değer sil
                         root->ArrLen = root->ArrLen-1;}
                    if(islem>0){// yukarı yönde - en küçük değer sil 
                        for(int i = 1;i<root->ArrLen;i++)
                            root->dizi[i-1] = root->dizi[i];
                        root->ArrLen = root->ArrLen-1;}
                }
            }
            cout<<root->data<<":";
            for(int i = 0;i<root->ArrLen;i++)cout<<root->dizi[i]<<" ";
            cout<<endl;
            preorder(root->left);
            preorder(root->right);
        }
        else
            sonraki = 0;
           
}
void AVL::preorder(){preorder(root);}
