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
        cap *=2; // kapasiteyi 2 katına çıkardık.
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
int* ArrayList::end(){return data+size()-1;}

void ArrayList::push_front(const int& value)
{
    arttir();
    if(size() == 0){
        data[0] = value;
    }
    else{
        for(int i = size()-1;i>=0;i--){
            data[i+1] = data[i]; 
        }
        data[0] = value;
    }
    lenght++;
}

void ArrayList::push_back(const int& value)
{
    arttir();
    data[lenght++] = value;
}

// istenilen uzunlukta 0 sıfırlardan oluşan dizi oluştur

/*ArrayList& ArrayList::zeros(const int& n){
    int* tmp = new int[n]{0};
    for(int i=0;i<lenght;i++){
        tmp[i] = data[i];
    }
    lenght = n;
    data = tmp;
    return *this;

    //lisY.zeros(lisX.size()); kullanımı
}*/

void ArrayList::reverse()
{
    int* tmp = new int[size()];
    int counter = 0;
    for(int i= size()-1;i>=0;i--){
        tmp[counter++] = data[i];
    }
    data = tmp;
}

// atama işlemleri 
ArrayList& ArrayList::atama(ArrayList& rhs)
{
    clear();
    data = new int[rhs.size()];
    for(int i = 0; i<rhs.size();i++){
        data[i] = rhs.data[i];
    }
    lenght = rhs.size();
    cap = rhs.size();
    return *this;
}

// atama operatörünün aşırı yüklenmesi
ArrayList& ArrayList::operator = (ArrayList& rhs){return atama(rhs);}

void ArrayList::clear()
{
    delete[] data;
    //data = 0;
    cap = 1;
    lenght = 0;
    data = new int[cap];
}

ArrayList::~ArrayList()
{
    delete [] data;
}