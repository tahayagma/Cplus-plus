#include <iostream>
#include <conio.h>

using namespace std;
template<class T>
class node{
    public:
    T data;
    node<T>* left;
    node<T>* right;
    node(const T& data=T(),node<T>* left=NULL,node<T>*right=NULL):data(data),left(left),right(right){}
};

template<class T>
class BinaryTree{
    node<T>* root;

    public:
    BinaryTree():root(NULL){}
    node<T>* getRoot()const{return root;}
    bool isEmpty() {return (root==NULL);}
    
    node<T>* addNode(node<T>* tmp,const T& value){
        if(tmp){ // eğer root boş değilse
            if(value < tmp->data)// ve gelen değer root değerinden küçükse sol tarafa ekleme olacak
                tmp->left = addNode(tmp->left,value); // root soluna recursive ile root sol değeri ve gelen veri gönderiliyor
            else
                tmp->right = addNode(tmp->right,value);
        }
        else
            tmp = new node<T>(value);// yeni değer ile bir node oluştur.
            //root = tmp;//
        root = tmp;
        return tmp;
    }

    void addNode(const T& value){addNode(root,value);}// addNode metodu aşırı yüklendi

    node<T>* find(node<T>*tmp,const T& value){
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

    node<T>* find(const T& value){return find(root,value);}// search metodu aşırı yüklendi.

    int height(node<T>* n ){
        if(n){
            int left = height(n->left);
            int right = height(n->right);
            return 1+ max(left,right);
        }
        return -1;
    }
    
    int height(){return height(root);}

    void preorder(node<T>* root){
        if(root){
            cout<<root->data<<endl;
            preorder(root->left);
            preorder(root->right);
        }
        else
            cout<<"-"<<endl;
    }

    void preorder(){preorder(root);}

    void inorder(node<T>* root){
        if(root){
            inorder(root->left);
            cout<<root->data<<endl;
            inorder(root->right);
    }   }    

    void inorder(){inorder(root);}

    void postorder(node<T>* root){
        if(root){
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<endl;
        }
    }

    void postorder(){postorder(root);}

    node<T>* getMin(node<T>* tmp){
        /* if(tmp && tmp->left)
            return getMin(tmp->left);
        return tmp; */
        while (tmp && tmp->left)
            tmp = tmp->left;
        return tmp;
        
    }

    node<T>* getMin(){return getMin(root);}

    node<T>* getMax(node<T>* tmp){
        /* if(tmp && tmp->right)
            return getMin(tmp->right);
        return tmp; */

        while (tmp && tmp->right)
            tmp = tmp->right;
        return tmp;
        
    }

    node<T>* getMax(){return getMax(root);}

    node<T>* mirror(node<T>* tmp){
        if(tmp){
            mirror(tmp->left);
            mirror(tmp->right);
            node<T>*temp = tmp->left;
            tmp->left = tmp->right;
            tmp->right = temp;
        }
        return tmp;
    }

    void mirror(){root = mirror(root);}

    node<T>* remove(const T& value,node<T>* tmp){
        if(tmp->data == value){
            if(!tmp->left && !tmp->right){ // sağ ve sol boş ise 
                delete tmp;
                return NULL;
            }
            else if(tmp->left == NULL){ // sol boş ise 
                node<T>* Node = tmp->right;
                tmp = tmp->right;
                delete Node;
            }

            else if(tmp->right == NULL){ // sağ boş ise
                node<T> *Node =tmp->left;
                tmp = tmp->left;
                delete Node;
            }
            else{ // sağ ve sol dolu ise
                node<T>* min = getMin(tmp->right); // sağ alt ağaçta en küçük değeri aldık.
                tmp->data = min->data; // silinecek düğümün datasına en küçük düğümün datasını atadık
                tmp->right = remove(min->data,tmp->right);  // tmp sağına ise en küçük değeri silme işleminden yapılacak olan return değeri atandı.

                // NOT: sağdan en küçük veriyi aldığımız için  sol ile işimiz yok.

            }
        }
        else{
            if(value<tmp->data)
                tmp->left = remove(value,tmp->left);
            else
                tmp->right = remove(value,tmp->right);
        }
        return tmp;
    }

    node<T>* remove(const int&value){return remove(value,root);}

    int depth(node<T>* start,node<T>*finish){
        if(start){
            if(start == finish)
                return 0;
            int left = depth(start->left,finish);
            int right = depth(start->right,finish);
        }
        else
            return INT_MIN;
    }

    int depth(node<T>*finish){return depth(root,finish);}
};


int main(){

    BinaryTree<int> tree;
    tree.addNode(30);
    tree.addNode(20);
    tree.addNode(50);
    tree.addNode(10);
    tree.addNode(25);
    tree.addNode(40);
    tree.addNode(70);
    //cout<<"root :"<<tree.getRoot()->data<<endl;
    //cout<<"find:"<<tree.find(70)->data<<endl;
    //cout<<tree.getRoot()<<endl;
    tree.remove(70);
    //cout<<tree.getRoot();
    tree.preorder();

    getch();
    return 0;
}