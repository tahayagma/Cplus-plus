#include <iostream>
#include <conio.h>


using namespace std;
template<class T>
class Node{

    public:
    T data; // düğümün değerini tutar
    Node<T>* next; // bir sonraki düğümü gösteren işaretçi
    Node(const T& data=0,Node<T>*next=NULL): data(data),next(next){}
    // kurucu metod ile varsayılan değer ataması gerçekleştirildi.
};

template<class T>
class list{
    Node<T>* root;
    int lenght;
    public:
        list(): root(NULL),lenght(0){}

        ~list(){ // listenin scope bittiğinde listenin tamamen silinip belleğe iade edilmesini sağladık
            clear();
            delete root;}

        list(const int& n,const T& value = 0): list(){// kurucu metod ile istenilen sayıda istenilen değer ile liste oluşturduk.
            for(int i = 0;i<n;i++)
                push_back(value);
        }

        Node<T>* begin()const{return root;}

        Node<T>* end()const{return NULL;}

        list& assing(const list& l){
            clear();
            Node<T>* tmp =l.begin();
            while (tmp != l.end())
            {
                push_back(tmp->data);
                tmp = tmp->next;
            }
            return *this;
        }

        list& operator = (const list&l){return assing(l);}// = operatorunu aşırı yükledik
        
        bool isEmpty()const{return (root == NULL);} // listenin boş olup olmaıdığını sorgular.
        // eğer root yani kök düğüm null ise liste boştur.

        // sondan veri ekleme
        void push_back(const T& value){
            if(isEmpty()) // eğer liste boş ise 
                root = new Node<T>(value); // value değeri ile bir liste oluştur ve ilk değerine ekle ardından root pointere atama yap
            else{
                Node<T>* tmp = begin(); // tmp adından geçici bir Node pointeri oluşturduk.
                while (tmp->next != end()) // döngü ile tmp değeri NULL olana kadar yani en son Node yi bulana kadar devam edecek
                    tmp = tmp->next;
                tmp->next = new Node<T>(value); // son düğüm bulunduktan sonra son düğümün next işaretçisine eklenmek istenen değeri atadık
            }
        }

        // baştan veri ekleme
        void push_front(const T& value){
            if(isEmpty())
                root = new Node<T>(value);
            else{
                Node<T>* tmp = new Node<T>(value); // eklenecek değer ile düğüm oluşturuyoruz.
                tmp->next = root; // ardındand düğümün netx pointer adresine root değerini tanımladık.
                root = tmp; // ve root değerini yeni eklenen değer ile değiştirdik.
            }
        }

        // veri düşürme
        void pop_back(){
            if(isEmpty())
                throw "liste bos";
            if(begin()->next == end()){// eğer listede bir eleman tek varsa
                delete root;
                root = NULL;
            }
            else{
                Node<T>* temp = begin(); // listenin başlangıç düğümünü al
                while (temp->next->next != end()) // root nodenin next değerinin next değeri bir sonraki elemanın next değeri NULL değilse 
                {
                    temp = temp->next; // temp  değerini temp next değeri olarak değiştir yani kaydırarak bir sonraki düğümü al
                }
                delete temp->next;// temp içindeki pointer adresini yani next değeri NULL olan düğümü sil
                temp->next = NULL; // temp yani sondan bir önceki değerin next değerini NULL yap.
            }
        }

        void pop_front(){
            if(isEmpty())
                throw "liste bos";
            Node<T>* temp = root;
            root = temp->next;
            delete temp;
        }

        void erase(const T& value){
            if(!isEmpty()){// lsite boş değil bu blok çalışır boş ise else blok çalışır
                if(root->data == value) // eğer değer ilk düğüme aitse pop_front metodu çağrıldı
                    pop_front();
                else{
                Node<T>* tmp = begin();
                Node<T>* del; // silinecek node yi tutmak için
                while (tmp->next->data != value) // eğer tmpin nextin datası value eşit değilse
                    tmp = tmp->next; // tmp bir sonraki düğüme kaydır
                del = tmp->next;// tmpin nexti yani silinecek düğümü del pointerine atadık
                tmp->next = tmp->next->next; // tempin nextini silinecek nodeden sonrakine node ile güncelledik.
                delete del;} // hedef düğümü sildik.
            }
            else
                cout<<"liste bos";
        }

        void clear(){
            Node<T>* temp = begin();
            Node<T>* first;
            while (temp != end())
            {
                first = temp->next;
                pop_front();// erase metodu yerine daha hızlı çalışır sadece bir while döngüsü var
                temp = first;  
            }
            
        }

        /* void insert(const int &s,const int &e,const int &value){
            Node* temp = begin();
            while(temp->data == s && temp->next->data == e || temp->data = e && temp->next->data == s)
                temp = temp->next;
            Node* tmp2 = temp->next;
            temp->next = new Node(value);
            temp->next->next = tmp2;
        } */

        int size(){
            /*private kısma length adında bir değişken tanımlayıp her ekleme ve silme işlemlerinde azaltıp
            arttırırsak kısa yoldan listenin uzunluğunu elde ederiz ve return lenght diyerek basit bir şekilde elde ederiz*/
            int counter = 0;
            Node<T>* tmp = begin();
            while (tmp != end())
            {
                counter++;
                tmp = tmp->next;
            }
            return counter;
        }

        Node<T>* find(const T& value){
            Node<T>*tmp = begin();
            while(tmp != end() && tmp->data != value)
                tmp = tmp->next;
            return tmp;// daha sonra bu node değer üzerinde işlem yapmal için pointerini döndürdük.
            // eğer eleman yoksa listenin end değeri return ediliyor.
            //return (tmp != NULL); // 0 dönerse yok 1 dönerse var
        }

        void display(){
            Node<T>* temp= begin();
            if(!isEmpty()){
                while (temp != end())
                {
                    cout<<temp->data<<" ";
                    temp = temp->next;
                }
            }
            else
                cout<<"Eleman Bulunamadi. Liste bos"<<endl;
        }
};




int main(){
    list<int> l;

    l.push_back(45);
    l.push_back(100);
    l.push_back(125);
    l.push_front(250);
    l.display();
    /*cout<<"size: "<<l.size()<<endl;
    l.display();
    cout<<endl;
    l.erase(250);
    l.display();
    cout<<"size: "<<l.size()<<endl;
    cout<<l.find(125)<<endl;
    l.clear();
    cout<<l.isEmpty()<<endl;
    cout<<"size: "<<l.size()<<endl; */

   /*  list l2,l3;
    l2.assing(l); // l listesindeki verileri l1 listeye copyala
    l.display();
    cout<<endl;
    l2.display();
    
    cout<<endl<<"_______________"<<endl;
    l3.display();
    l3 = l;
    l3.display(); */


    list<string> l2(5,"hello");// kurucu metod test  
    l2.display();
    
    
    


    getch();
    return 0;
}