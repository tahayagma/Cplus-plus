#include <iostream>
#include <conio.h>
#include <fstream>


using namespace std;
//int * StrToArr(string);

class Polinom{

    int pol_array[4];
    int leng = 4;

    public:
    Polinom();
    Polinom(int []);
    

    const Polinom operator+(const Polinom &); // polinom toplama
    const Polinom operator-(const Polinom &); // çıkarma
    Polinom& const_plus(const Polinom &); // sabit artırma
    Polinom operator+=(const Polinom &); // polinom toplama ve atama
    const int operator==(const Polinom &); // polinom derece karşılaştırma
    void derece();
    void print();
    void pol_derece(const Polinom &,const Polinom &); // iki polinom derece karşılaştırma
    const Polinom operator+(int);//scaler sayı ile polinom toplama

    ~Polinom();
};

//DEFAULT CONSTRUCTOR
Polinom::Polinom(){
    //pol_array = {0}; // sifirlandi
    cout<<"Default Constructor calisti ve degerler sifirlandi."<<endl;
    }

// PARAMETERED CONSTRUCTOR    
Polinom::Polinom(int array[]){
    //leng = sizeof(pol_array)/4;
    for (int i = 0; i <leng; i++)
    {
        pol_array[i] = array[i];
    }
    cout<<"parametreli constructor calisti ve degerler atandi"<<endl;

}

// OPERATOR +
const Polinom Polinom::operator+(const Polinom &p){
    cout<<"opertor + calisti"<<endl;
    Polinom Sonuc1;
    for (int i = 0; i <leng; i++)
       Sonuc1.pol_array[i] = p.pol_array[i]+pol_array[i];
    
    return Sonuc1;

}

const Polinom Polinom::operator+(int scaler_n){

    cout<<"scaler sayi polinom toplama calisti"<<endl;
    Polinom Sonuc2;

    for (int i = 0; i < leng; i++)
    {
        Sonuc2.pol_array[i] = pol_array[i]+scaler_n;
    }
    return Sonuc2;
}

Polinom Polinom::operator+=(const Polinom &c){
    cout<<"polinom toplama ve atama calisti."<<endl;
    for (int i = 0; i <leng; i++)
        pol_array[i] = pol_array[i]+c.pol_array[i];
}

const Polinom Polinom::operator-(const Polinom &p){
    cout<<"polinom çıkarma calisti"<<endl;
    Polinom Sonuc3;
    for (int i = 0; i <leng; i++)
    {
        Sonuc3.pol_array[i] = pol_array[i]-p.pol_array[i];
    }
    return Sonuc3;
    
}

const int Polinom::operator==(const Polinom &c){

    cout<<"sonuc: "<<derece() == c.derece();
    return (derece()== c.derece());
}


// PRİNT
void Polinom::print(){
    cout<<"Print function is running"<<endl;
    for (int i = 0; i <leng; i++)
    {
        cout<<pol_array[i]<<" ";
    }
    cout<<endl;
    derece();
}

// DERECE
void Polinom::derece(){

    cout<<"Degree is running"<<endl;
    cout<<"derece: "<<leng-1<<endl;
}



// DESTRUCTOR
Polinom::~Polinom(){
    cout<<"destructor calisti"<<endl;
    //delete[] pol_array;//bunu calisirsa pol_array rasgele değerler alır
    }

int main(){
    Polinom Pol[8]; // 8 adet nesne oluşturuldu.
    Polinom Sonuc1,Sonuc2,Sonuc3,Sonuc4;
    /*ifstream file("polinom.txt");
    int *p;

    string s;

    while (getline(file,s)){

    }*/
    
    int polinom1[4] = {3,0,5,7};
    int polinom2[3] = {6,8,-2};
    int polinom3[3] = {-1,0,8};
    int polinom4[5] = {2,-1,-1,0,-3};
    int polinom5[4] = {1,2,5,4};
    int polinom6[4] = {-1,2,-1,3};
    int polinom7[5] = {-3,2,-8,1,2};
    int polinom8[5] = {4,-2,-9,2,8};
    int polinom9[4] = {9,0,0,1};
    int polinom10[3] = {-2,0,3};

   //Pol[0]=(polinom1);
   Pol[5]=(polinom5);
   //Pol[7] = (polinom10);
   Pol[3] = (polinom3);
   Pol[6] = (polinom9);
   //Pol[2] = (polinom2)
   //Sonuc1=Pol[0].operator+(Pol[5]);
   //Sonuc1.print();

   //Sonuc2 = Pol[7].operator+(18);
   //Sonuc2.print();

   //Sonuc3 = Pol[0].operator-(Pol[6]);
   //Sonuc3.print();


   //Pol[3].operator+=(Pol[7]);
   //Pol[3].print();


    
    

    getch();
    return 0;
}

/*int * StrToArr(string s){
    int leng= 0;
    for (int  i = 0; i <s.length(); i++)
    {
        if (s[i]>=48 && s[i]<=57)// s[i] != (char)44 && s[i] != (char)32 && s[i] != (char)45 ASCII TABLE
            leng++;
    }
    static int array[leng];
    int c = 0;
   for (int  i = 0; i <s.length(); i++)
    {
        if (s[i] != (char)44 && s[i] != (char)32 && c<=leng)
        {
            if (s[i] == '-')
            {
                array[c] = (-1*(s[i+1]-48));
                i++;
                c++;
            }
            else{
                array[c] = (s[i]-48);
                c++;
            }
           
        }   
    }
    /*for (int i = 0; i <leng; i++)
        cout<<" "<<array[i];
    cout<<endl;
    return array;}*/

