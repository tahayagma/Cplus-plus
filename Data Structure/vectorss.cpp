#include <iostream>
#include <conio.h>

using namespace std;

template<class T>

class vector{
    T* data; // her dizi aynı zamanda bir pointer olduğundan dizilerimizi pointer ile gösterdik
    // vector sınıfının diğer veri türleri ile  de uyumlu olması için template olarak bildirimi yaptık.
    int cap; // dizinin kapasitesini tutabileceğimiz bir değişken tanımladık.
    int index;
    int value;

    // DİNAMİK BÜYÜME
    void growth(){
        if(capacity()<=size()){ // eğer kapasite index değerinden küçükse kapasitenin artırılması gerekir yoksa index taşması olur.
            cap *=2; // kapasite değerini 2 katı kadar arttır ve bununla yeni bir dizi oluştur
            T* new_data = new T[cap]; // T türünde cap kadar new_data adında yeni bir dizi oluşturuldu.

            for (int i = 0; i <size(); i++) // eski data içindeki veriler new_data adlı diziye kopyalandı.
            {
                new_data[i] = data[i];
            }
             delete[] data; // diziler ve pointerler ki dizilerde pointerdir  delete [] dizi_adi şeklinde silinir yani alan serbest bırakıldı
             data = new_data; // boşalan data pointerina new_data dizisini atadık
        }

    }
    // DİNAMİK KÜÇÜLTME
    void shrink(){
        if(capacity()/2 > size()){
            cap /= 2;
            T* new_data = new T[cap];
            for (int i = 0; i < size(); i++)
            {
                new_data[i] = data[i];
            }
            delete [] data;
            data = new_data; // new_data pointerini data içine sakladık. delete [] new_data olursa veriler silinir.
        }
    }

    void reset(){
        delete [] data;
        data = NULL;
        cap,index = 1,0;
    }

    public:
        int size()const{ return index; } // herhangi bir değişiklik olmayacağı için const bildirimi yaptık
        int capacity()const{ return cap;}
        vector(): data(NULL),index(0),cap(1){ // kurucuu metodlar ile değişkenlere atama yapıldı.
            data = new T[cap]; // T türünde cap boyutunda bir dizi oluşturduk. T int olursa  data = new int[1] şeklinde bir dizi oluşur
            // yada T char olursa data = new char[1] şeklinde bir dizi oluşur.
        }
        void push_back(const T& value){ growth(); data[index++] = value;}
        // veri eklenmeden önce büyüme ihtiyacı var mı yok mu diye kontrol edilir.

        void pop_back(){
            if((isEmpty))
                throw "Error"; // bu hata fırlatıldıktan sonra program sonlanır.
            index--; 
            shrink();
        } // veri pop edildikten sonra sorgu yapılır küçülme var mı yok mu diye

        void display(){ 
            for(int i = 0;i<index;i++){
                cout<<data[i];
            }
        }

        bool isEmpty(){return (index == 0);}

        
        // T türünde referans döndürerek hem okuma hem de yazma işlemi yapabilelim.
        // v.at(3) = 50; ile 3.indisteki elemanı 50 olarak değiştirebiliriz.
        T& at(int indis){
            if(indis>=0 && indis<size())
                return data[indis];
            throw "İndis not a range";
        }

        T& operator[](int indis){return at(indis);} // v[3] = şeklinde bir kullanım olur. operator overloading ile 

        T front()const{ if(!isEmpty) return data[0]; } // T hangi veri tipi olursa  metod ona göre şekillenir.
        T back()const {if(!isEmpty) return data[index-1];}

        T* begin() const {return data;} //frontan farklı olarak başlangıç adresini(pointer) döndürür değeri değil
        T* end()const{return data+size();} // back metodundan farklı olarak dizinin sonunun adresini döndürür.

        //yukarıd tanımlanan reset metodunu çağrıldı.
        void clear(){
            reset();
            data = new T[cap];
        }

        // ATAMA OPERATÖRÜN AŞIRI YÜKLENMESİ
        vector<T> &assing(const vector<T> &rhs){
            reset(rhs.size(),rhs.capacity());
            data = new T[rhs.capacity()];
            for(int i = 0; i<size();i++){
                data[i] = rhs.data[i];
            }
            return *this;
        }
        vector<T>& oprerator = (const vector<T> &rhs){return assign(rhs);} 
};


int main(){
    vector<int> v; // vector sınıfından v adında bir nesne türetildi. ve T değeri int olarak verildi.

    cout <<v.capacity();
    cout<<v.size()<<endl;

    v.push_back(15);
    cout<<v.isEmpty()<<endl;
    v.pop_back();
    cout<< v.isEmpty();

    //yazdirma
    int * begin = v.begin();
    int* end = v.end();

    while (begin != end)
    {
        cout<<*begin<<" ";
        begin++;
    }
    

    getch();
    return 0;
}