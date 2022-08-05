/**
* @file ArrayList(Başlık Dosyası)
* @description Faktöriyel hesaplaması için ArrayList yapısı oluşturma
* @course A GRUBU
* @assignment 1.ÖDEV
* @date 31.07.2022
* @author Taha YAĞMA
*/



/**
* @file ArrayList(Başlık Dosyası)
* @description Faktöriyel hesaplaması için ArrayList yapısı oluşturma
* @course A GRUBU
* @assignment 1.ÖDEV
* @date 31.07.2022
* @author Taha YAĞMA
*/



#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

using namespace std;

class ArrayList{


    int* data; // veri 
    int lenght; // uzunluk
    int cap; // kapasite
    void arttir(); // kapasite arttırma
    ArrayList& atama(ArrayList&);
    public: 

    ArrayList(); // kurucu metod defaul değerler ataması
     // ArrayList kopyalama
    ArrayList& operator = (ArrayList&); // kopyalama için atama operatörü aşırı yüklendi 
    void push_back(const int&); // önden ekleme
    int size(); // dizi boyutunu döndürür
    int capacity(); // dizinin kapasitesini döndürür
    int * begin();  // dizinin başını döndürür
    int* end(); // dizinin sonunu döndürür
    void clear(); // Arraylist temizler
    //~ArrayList(); // yıkıcı metod

    
};

#endif
