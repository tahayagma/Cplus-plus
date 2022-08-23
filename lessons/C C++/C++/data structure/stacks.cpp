// VECTÖR İLE STACK
/* #include <iostream>

#include <conio.h>

using namespace std;

template<class T>

class stack{

    T* data;
    int index;
    int cap;

    void growth(){
        if(eleman_sayisi()>= capacity()){
            cap += 1;
            T* new_data = new T[cap]; 

            for(int i = 1; i<=eleman_sayisi();i++)
                new_data[i] = data[i-1];
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
        int eleman_sayisi() const{return index;}
        int capacity()const{return cap;}
        stack(): data(NULL),index(0),cap(1){
            cout<<"Stack olusturuldu.";
            data = new T[cap];
            }

        void push(const T& value){
            growth();
            data[0] = value;
            index++;
        }

        void pop(){
            index--;
            shrink();
        }

        void display(){
            for(int i = 0; i<eleman_sayisi();i++)
                cout<<data[i]<<" ";
        }
        
        T* top(){return data;}
};




int main(){

    stack<int> s;

    s.push(9);
    s.push(25);
    s.push(40);
    s.display();
    cout<<endl;
    cout<<"eleman:"<<s.eleman_sayisi()<<endl;
    cout<<"capacity:"<<s.capacity()<<endl;
    s.pop();
    cout<<"eleman:"<<s.eleman_sayisi()<<endl;
    cout<<"capacity:"<<s.capacity()<<endl;
    s.display();
    cout<<"en bas : "<<*s.top();

    getch();
    return 0;
} */

// LİNKED LİST İLE STACK

#include <iostream>
#include <conio.h>

using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(const T& data=0,Node<T>*next=NULL): data(data),next(next){}
};

template<class T>
class stack{
    Node<T>* root;
    int length;
    public:
    stack():root(NULL),length(0){}
    ~stack(){
        clear();
        delete root;}

    int size()const{return length;}
    bool isEmpty()const {return (root==NULL);}

    Node<T>* top()const {return root;}
    Node<T>* end()const{ return NULL;}

    stack& assign(const stack& s){// bir stack yapısını başka bir stack içine kopyalama
        clear();
        Node<T>* tmp = s.top()->next;
        root =  new Node<T>(s.top()->data);
        Node<T>* tmp2 = top();
        while(tmp != s.end()){
            tmp2->next = new Node<T>(tmp->data);
            length = s.size();
            tmp2= tmp2->next;
            tmp= tmp->next;
        }
        return *this;
    }

    stack& operator = (const stack& s){ return assign(s);} // = operatörünü aşırı yükleyerek assing metodu ile çalıştırdık.

    void push(const T& value){
        Node<T>* tmp = new Node<T>(value,root); // kurucu değeri parametreleri gönderdik
        root = tmp;
        length++;
    }

    void pop(){
        if(!isEmpty()){
            Node<T>* temp = top()->next;
            //T del = root->data;
            delete root;
            root = temp;
            length--;
            //return del;
        } // geri dönüş tipi T olduğu için uygun bir return değeri belirlememiz gerekiyor
    }

    void clear(){
        while(!isEmpty()) // isEmpty true dönene kadar pop fonksiyonunu çağırdık.
            pop();
        }

    void display(){
        Node<T>* tmp = top();
        while (tmp != end()){
            cout<<tmp->data<<" ";
            tmp = tmp->next;
            }
    }
};

int main(){
    stack<string> s;
    s.push("ali");
    s.push("veli");
    s.push("mehmet");

    /* cout<<endl;
    cout<<"size: "<<s.size()<<endl;
    cout<<"___________________"<<endl;
    s.clear();
    cout<<"size: "<<s.size(); */
    stack<string> s2;
    s2 = s;//s2.assign(s);
    cout<<"size: "<<s2.size()<<endl;
    s2.display();
    cout<<endl;
    s2.pop();
    cout<<"size: "<<s2.size()<<endl;
    s2.display();
    s2.push("Derman");
    cout<<"size: "<<s2.size()<<endl;
    s2.display();



    getch();
    return 0;
}
