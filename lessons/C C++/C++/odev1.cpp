#include <conio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <map>
#include <sstream> 

using namespace std;

struct CityDistance
{
    int city_code;
    int city_distance;
};

map<int,string> cities; // int anahtarı city code string değeri ise city name olacak

class Line{

    int line_code,cities_number;
    string line_name;
    string line_craft_type;
    vector<CityDistance> line_cities;
    public:
    Line() // parametresiz kurucu
    {
        cout<<"parametresiz kurucu calisti ve ortalama hizlar tanimlandi"<<endl;
        int Boeig = 600;
        int Airbus = 750;
        int Jettyl= 700;
        int Lockheed = 650;
    }
    
    // parametreli kurucu
    Line(int line_code,string line_name,string line_craft_type,int cities_number,int city_codee,int city_distancee){
        this->line_code = line_code;
        this->line_name = line_name;
        this->cities_number = cities_number;
        this->line_craft_type = line_craft_type;
        line_cities[0].city_code = city_codee;
        line_cities[0].city_distance = city_distancee;
    }
    void print_schedule(int start_city_code,int end_city_code);
};

int main(){
    //vector<Line> LineObj(6); // (6 hat olduğu için) 6 tane Line sınıfının nesneler vektörü tanımlandı.

    string sehir_adi,hat_adi,hat_tipi,total;
    int sehir_kodu,hat_kodu,sehir_kodu_l,sehir_mesafe,sehir_sayisi;
    
    /*//____________cities map ekleme___________________
    ifstream City("CITIES.txt");
    while (City>>sehir_kodu>>sehir_adi)
        cities.insert({sehir_kodu,sehir_adi});
    City.close();
    //___________________________________________________

    cout<<"Reading Cities Map"<<endl;

    //__________________CİTİES MAP OKUMA____________________________
    for (auto itr = cities.begin(); itr != cities.end(); ++itr)
        cout<<"sehir kodu: "<<itr->first<<"\t"<<"sehir adi: "<<itr->second<<endl;
    //__________________________________________________________________________*/
    
    //________________LINES TXT OKUMA_____________________________
    vector<string> strVector;
    ifstream Lines("LINES.txt");
    int counter = 0;
    while (getline(Lines,total,' '))
    {      
            if(total == "LINE"){cout<<"satir"<<counter<<endl;counter++;}
           /* if (total.size() != 0 || total == "LINE")
           {
               strVector.push_back(total);
               cout<<"satir"<<counter<<endl;
               //cout<<counter<<" Total: "<<total<<endl;
               counter++;
           } */
    }
    cout<<strVector.size()<<endl;
        //cout<<"satir: "<<i+1<<"__"<<strVector[i]<<endl;
    
    
    /*while (Lines>>hat_kodu>>hat_adi>>hat_tipi>>sehir_sayisi>>sehir_kodu_l,sehir_mesafe)
           //Line l(hat_kodu,hat_adi,hat_tipi,sehir_sayisi,sehir_kodu_l,sehir_mesafe);
            cout<<"hat kodu: "<<hat_l<<endl;*/
    Lines.close();

    //_______________________LINES CLASS YAZDIRMA____________________
    /*for (auto itr = LineObj.begin(); itr  != LineObj.end(); ++itr)
    {
        cout<<itr->line_code<<itr->line_name<<itr->line_craft_type<<endl;
    }*/
    getch();
    return 0;
}