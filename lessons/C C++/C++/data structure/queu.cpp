// VECTÖR İLE QUEUE

/* #include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

template<class T>

class Queu{

    T* data;
    int index;
    int cap;

     void growth(){
        if(eleman_sayisi()>= capacity()){
            cap += 1;
            T* new_data = new T[cap]; 

            for(int i = 0; i<=eleman_sayisi();i++)
                new_data[i] = data[i];
            delete [] data;
            data = new_data;
        }
    }

    void shrink(){
        if(eleman_sayisi()<capacity()){
            cap -=1;
            T* new_data = new T[cap];

            for(int i = 1; i<=eleman_sayisi();i++)
                new_data[i-1] = data[i];
            delete [] data;
            data = new_data;
        }
    }

    public:
        Queu(): data(NULL),index(0),cap(1){
            cout<<"Bos bir kuyruk yapisi olustu."<<endl;
            data = new T[cap];
        }

        int capacity()const{return cap;}
        int eleman_sayisi() const{return index;}

        void enqueue(const T& value){
            growth();
            data[index++] = value;
        }

        void dequeue(){
            index--;
            shrink();
        }

        void display(){
            for(int i = 0; i<eleman_sayisi();i++)
                cout<<data[i]<<" ";
        }


};

int main(){

    Queu<float> q;
    q.enqueue(91.5);
    q.enqueue(20.6);
    q.enqueue(35.12);
    q.display();
    cout<<endl;
    cout<<"eleman:"<<q.eleman_sayisi()<<endl;
    cout<<"capacity:"<<q.capacity()<<endl;
    q.dequeue();
    cout<<"eleman:"<<q.eleman_sayisi()<<endl;
    cout<<"capacity:"<<q.capacity()<<endl;
    q.display();

    getch();
    return 0; 
} */

// LİNKED LİST İLE QUEUE


#include <iostream>
#include <conio.h>

using namespace std;

template<class T>
class node{
    public:
    T data;
    node<T>* next;
    node(const T&data =0, node<T>* next = NULL):data(data),next(next){} 

};

template<class T>
class queue{
    node<T>* root;
    node<T>* end;
    int lenght;
    public:
        queue(): root(NULL),end(NULL),lenght(0){}
        queue(const queue<T>& q): queue<T>(){ *this = q;}
        // kopyalama kurucu nesne oluşturulurken çalışır ve deep copy işlemi yapar
        /* queue<int> s1;
           queue<int> s2 = s1 yada queue<int> s2(s1) şeklinde kullanılır.*/
        ~queue(){clear(); }

        bool isEmpty(){ return (root==NULL);}

        void clear(){
            while(!isEmpty())
                dequeue();
        }

        queue<T>& assing(const queue<T>& q){
            clear();
            node<T>* tmp = q.root;
            lenght = q.lenght;
            while (tmp != NULL)
            {
                enqueue(tmp->data);
                tmp = tmp->next;
            }
            
        }

        queue<T>& operator = (const queue<T>& q){ return assing(q);}


        void enqueue(const T& value){
            if (isEmpty())
            {
                root = new node<T>(value);
                end = root;
            }
            else{
                end->next = new node<T>(value);
                end = end->next;
                /* node<T>*tmp = root;
                while (tmp->next != NULL)
                    tmp = tmp->next;
                tmp->next = new node<T>(value); */
            }
            lenght++;
        }
        void dequeue(){
            if (isEmpty())
                cout<<"kuyruk bos"<<endl;
            else{            
            node<T>* tmp = root->next;
            if(root == end)
                end = NULL;
            delete root;
            root = tmp;
            lenght--;
            }
        }
        void son(){cout<<"end:"<<end->data<<"root:"<<root->data<<endl;}

        int size(){return lenght;}

        void display(){
            node<T>* tmp = root;
            while (tmp != NULL)
            {
                cout<<tmp->data<<" ";
                tmp = tmp->next;
            }
        }    

};

int main(){

    queue<int> q;
    cout<<q.size()<<endl;
    q.enqueue(15);
    q.enqueue(26);
    q.display();
    cout<<endl;
    cout<<q.size();
    q.dequeue();
    q.enqueue(50);
    q.enqueue(95);
    q.enqueue(100);
    cout<<endl;
    q.display();
    cout<<endl;
    q.son();
    q.dequeue();
    q.display();
    cout<<endl;
    q.son();
    q.enqueue(256);
    q.display();
    cout<<endl;
    q.son();

    getch();
    return 0;
}
