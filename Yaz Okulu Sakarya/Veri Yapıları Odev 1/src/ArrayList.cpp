/**
* @file ArrayList (cpp dosyası)
* @description  ArrayList başlık dosyasının fonksiyon gövdesi gerçeklenmesi
* @course A GRUBU
* @assignment 1.ÖDEV
* @date 31.07.2022
* @author Taha YAĞMA
*/


#include "ArrayList.hpp"


// Boyut arttırma 
 void ArrayList::arttir(){
    if(capacity()<=size())
    { 
        cap *=5; // kapasiteyi 5 katına çıkardık. Böylelikle arttir metoduna daha az girilir bu sayede daha hızlı çalışır fakat bad_alloc hatası alma ols artar.öneri:2
        int*  new_data = new int[cap];// yeni kapasite boyutunda yeni bir dizi oluşturuldu. 
        for(int i= 0; i<size();i++)// veriler yeni diziye kopyalanıyor.
        { 
            new_data[i] = data[i];
        }       
        delete[] data;// eski dizi silindi.
        data  = new_data;// data dizisine yeni oluşturulan dizi atanıyor;
    }
}
ArrayList::ArrayList():lenght(0),cap(1){data = new int[cap];}
int ArrayList::size(){return lenght;}
int ArrayList::capacity(){return cap;}
int* ArrayList::begin(){ return data;}
int* ArrayList::end(){return data+(size()-1);}


void ArrayList::push_back(const int& value)
{
    arttir();
    data[lenght++] = value;
}

// atama işlemleri 
ArrayList& ArrayList::atama(ArrayList& rhs)
{   clear();
    data = new int[rhs.size()];
    for(int i = 0; i<rhs.size();i++){
        data[i] = rhs.data[i];
    }
    lenght = rhs.size();
    cap = rhs.size();
    return *this;
}

// atama operatörün aşırı yüklenmesi
ArrayList& ArrayList::operator = (ArrayList& rhs){return atama(rhs);}

void ArrayList::clear()
{
	delete[] data;
    //data = 0;
    cap = 1;
    lenght = 0;
    data = new int[cap];
}

/*ArrayList::~ArrayList()
{
    clear();
}*/
