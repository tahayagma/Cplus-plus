#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

template <typename T> // şablon tanımlandı. Veri tipinin ne olduğu bilinmediği için typename olarak tanımlandı.
void print(vector<T>& v){ //
    typename vector<T>::iterator i = v.begin(); // vektrörün ilk dizesini alır. iterator pointer mantığındadır.
    //typename diyerek alınacak şablonun veri tipinin ne olacağını bilmiyoruz. string int ..... gibi
    while (i != v.end()) // sona eşit olmadığı sürece devam edecek.
    {
        cout<<*i++<<" ";
    }
    cout<<endl;
};

int main(){

    vector<int> v; // v adında ve int tipinde boş bir vektör tanımlandı.
    vector<int> v1(10); // 10 elemanlı bir vektör tanımlandı. İnt olduğu için ve degerler belli olmadığı için tümünü 0 olarak atar
    vector<int> v2(5,10); // oluşturulan vektöre başlangıç olarak 5 tane 10 atanır.
    return 0;}