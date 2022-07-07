/*
https://www.youtube.com/watch?v=nWet06FHwig&list=PLIM5iw4GHbNX8O53Z7Dqi1ZIUxZzpFhR8&index=46
https://www.youtube.com/watch?v=stwZhzaeTBg&list=PLfs1gAT4S8yJuI9WLcTwsANzsHloTz1p5&index=99

SİLME İŞLEMLERİNDE SON KISIM EKSİK

*/

#include <iostream>
#include <conio.h>

using namespace std;

class  node{
    public:
    int data;
    node* left;
    node* right;

    node(int data = 0,node*left =NULL,node*right= NULL): data(data),left(left),right(right){}
};

class AVL{
    node* root;

     int height(node* Node){
        if(Node){
            int left = height(Node->left);
            int right = height(Node->right);
            return 1+max(left,right);
        }
        else
            return 0;
    }
    public:
    AVL(): root(NULL){}
    bool isEmpty(){return (root == NULL);}
   
    int height(){return height(root);}

    node * getRoot(){return root;}

    int balancefactor(node* Node){
        return height(Node->left)-height(Node->right); // mutlak değerce 1 den büyükse dengesizlik vardır. (-1,0,1) alabilir.
    }
    // sağa dönüş(sol sol dengesizliği)
    node* ll_rotate(node* Node){
        node* temp = Node->left;
        Node->left = temp->right;
        temp->right = Node;
        return temp; // bozulan düğüdemden sonraki düğümü return edecek eklemede ebeveyn ile bağlant kursun
    }

    node* rr_rotate(node* Node){
        node* temp = Node->right;
        Node->right = temp->left;
        temp->left = Node;
        return temp;
    }

    node * insert(int value,node*Node){
        if(!Node) // node boş ise 
            return new node(value); // verilen değeri yeni bir düğüm olarak ekle
        else// boş değilse
            if(value<Node->data){ // eğer value düğümün datasından küçükse sol için fonksiyon tekrar çağrılıyor.
                Node->left = insert(value,Node->left);
                Node = query(Node);
            }
            else{ // değilse de sağ için fonksiyon çağrılıyor
                Node->right = insert(value,Node->right);
                Node = query(Node);
            }
        return Node;
    }

    void insert(int value){root =  insert(value,root);}


    node* query(node* Node){
        int h = balancefactor(Node);
        if(abs(h)>1){ // fark mutlak değerce 1 den büyükse dengesizlik vardır.
            if(h>1){// sol-sol yada sol sağ dengesizliği vardır.
                if(!Node->left->right){// sola eklenme vardır.ve sol-sol dengeziliği vardır.
                    cout<<"sol sol dengesizlik"<<endl;
                    Node = ll_rotate(Node);}
                else{ //sağa eklenme vardır ve sol-sağ dengesizliği vardır.
                    cout<<"sol sag dengesizlik"<<endl;
                    Node->left = rr_rotate(Node->left);
                    Node = ll_rotate(Node);
                }
            }
            else{ // 1 den küçükse sağ-sağ yada sağ sol dengesizliği vardır.
                if(!Node->right->left){// sağ eklenme vardır.ve sağ-sağ dengeziliği vardır.
                    cout<<"sag sag dengesizlik"<<endl;
                    Node = rr_rotate(Node);}
                else{ //sola eklenme vardır ve sağ-sol dengesizliği vardır.
                    cout<<"sag sol dengesizlik"<<endl;
                    Node->right = ll_rotate(Node->right);
                    Node = rr_rotate(Node);
                }
            }
        }
        return Node;
    }

    node* find(node* tmp,const int& value){
        if(tmp){
            if(tmp->data == value)
                return tmp;
            else if(value<tmp->data)
                return find(tmp->left,value); //return edilmezse son değer elde edilemez
            else
                return find(tmp->right,value);//return edilmezse son değer elde edilemez
        }
        return tmp;
    }

    node* find(const int& value){return find(root,value);}// search metodu aşırı yüklendi.

    
    node* sil(const int& value,node*tmp){
        if(tmp->data == value){
            if(!tmp->left && !tmp->right){ // sağ ve sol boş ise 
                delete tmp;
                return NULL;
            }
            else if(tmp->left == NULL){ // sol boş ise 
                node* Node = tmp->right;
                tmp = tmp->right;
                delete Node;
            }

            else if(tmp->right == NULL){ // sağ boş ise
                node*Node =tmp->left;
                tmp = tmp->left;
                delete Node;
            }
            else{ // sağ ve sol dolu ise
                node *min = getMin(tmp->right); // sağ alt ağaçta en küçük değeri aldık.
                tmp->data = min->data; // silinecek düğümün datasına en küçük düğümün datasını atadık
                tmp->right = sil(min->data,tmp->right);  // tmp sağına ise en küçük değeri silme işleminden yapılacak olan return değeri atandı.

                // NOT: sağdan en küçük veriyi aldığımız için  sol ile işimiz yok.

            }
        }
        else{
            if(value<tmp->data)
                tmp->left = sil(value,tmp->left);
            else
                tmp->right = sil(value,tmp->right);
        }
        tmp = query(tmp);
        return tmp;
    }

    node* sil(const int&value){return sil(value,root);}

     node* getMin(node* tmp){
        /* if(tmp && tmp->left)
            return getMin(tmp->left);
        return tmp; */
        while (tmp && tmp->left)
            tmp = tmp->left;
        return tmp;
        
    }

    node* getMin(){return getMin(root);}




     void preorder(node* root){
        if(root){
            cout<<root->data<<endl;
            preorder(root->left);
            preorder(root->right);
        }
        else
            cout<<"-"<<endl;
    }

    void preorder(){preorder(root);}


};


int main(){
    AVL avl;
    avl.insert(20);
    avl.insert(15);
    avl.insert(30);
    avl.insert(40);
    avl.insert(25);
    avl.insert(26);
    avl.insert(24);
    avl.insert(23);
    avl.preorder();
    avl.sil(20);
    cout<<"_____________"<<endl;
    avl.preorder();

    getch();
    return 0; 
}