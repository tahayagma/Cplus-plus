#include <iostream>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <fstream>

using namespace std;
// factöriyel ve kombinasyon fonksiyon protoripleri,
/* void combination(int ,int);
int factorial(int);
int fackt_recursive(int);*/

//int ranj(int* ,int);

int main(){
    
    //-1 girilene kadar sayıları topla ve ortalamasını al
    /* int x;
    int top= 0;
    int counter = 0;
    while (true)
    {
        std::cout << "login numbers:"<<endl;
        cin>>x;
        if (x == -1)
           break;
        else
            top +=x;
            counter++;
    }
    
    std::cout<<(float)top/counter; */

    /* for (;;)  // be şekilde sonsuz bir for loop tanımlanabilir while true ile aynı işlemi yapar.
    {
        cout<<"sonsuz döngü"<<endl;
    } */

    //fibonacci

    /* int x=0,y=1;

    int kac;
    int fib;
    cout<<"kac sayi olsun: ";
    cin>>kac;
    cout<<x<<" "<<y;
    while (kac>=1)
    {
        fib = x+y;
        cout<<" "<<fib;
        x = y;
        y= fib;
        kac--;
    } */
    
    //negative and positive ratio
    /* int number;
    int n,positive=0,negative=0,zeros=0;
    cout<< "login number:";
    cin>>n;

    for (int i = 1; i <=n; i++)
    {
        cout<<i<<".number: ";
        cin>>number;
        if (number >0)
            positive += 1;

        else if (number <0)
            negative += 1;
        else
            zeros += 1; 
    }
    
    cout<<"pos: "<<positive<<" negative: "<<negative<<" zeros: "<<zeros<<endl;
    
    cout<<"pos_ratio: "<<(float)positive/n<<" nega_ratio: "<<(float)negative/n<<" zero_ratio: "<<(float)zeros/n<<endl;*/

    
    /* int sayi;

    cout<<"login:";
    cin>>sayi;

    for (int i = sayi; i>=1; i--)
    {
        for (int j = i; j>=1; j--)
        {
            cout<<"*";
        }
        cout<<endl;
    } */
    
    //Identity matrix(birim matris)
    /* int size;

    cout<< "size:";
    cin>> size;

    for (int i = 0; i<size; i++)
    {
        for (int j = 0; j <size; j++)
        {
            if (i==j)
                cout<<" "<<1; // i<=j dersek köşegen altındaki matrisi 1 ler.
            else
                cout<<" "<<0;
        }
        cout<<endl;
    } */
    
    //ters birim matris
    /* int size;

    cout<< "size:";
    cin>> size;
    for (int i = 0; i<size; i++)
    {
        for (int j = 0; j <size; j++)
        {
            if (i+j==size-1)
                cout<<" "<<1;
            else
                cout<<" "<<0;
        }
        cout<<endl;
    } */

    // üstüçgen ve altüçgen  matris olusturma
    /* int size;

    cout<< "size:";
    cin>> size;
    for (int i = 0; i<size; i++)
    {
        for (int j = 0; j <size; j++)
        {
            if (i+j==size-1 || i+j>=size)// i+j<=size küçük eşittir ile de altüçgen matris oluşturulur.
                cout<<" "<<1;
            else
                cout<<" "<<0;
        }
        cout<<endl;
    } */
    

    /* int num;

    cout<<"number:";

    cin>> num;

    for (int i = 0; i<num; i++)
    {
        for (int j = 0; j<=i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    } */
    
    //0 and 1 piramit
    /* 
    for (int  i = 0; i < 26; i++)
    {
        for (int j = 0; j <i; j++)
        {
            cout<<j<<" ";
        }
        for (int k = i; k>=0; k--)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    } */
    
    // harfler piramit
    /* char car;
    cout<<"login character:";
    cin>>car;

    for (int  i = (int)car-65; i < 26; i++)
    {
        for (int j =(int)car-65; j <=i; j++)
        {
            cout<<(char)(65+j)<<" ";
        }
        for (int k = i-1; k>=(int)car-65; k--)
        {
            cout<<(char)(65+k)<<" ";
        }
        cout<<endl;
    } */
    
    // kombinasyon
    /* int n,r;
    cout<<"login n:";
    cin>>n;
    cout<<"login r:";
    cin>>r;
    
    combination(n,r); // ya protorip yada fonksiyonun yukaruda tanımlamasın aksi takdir fonksiyonu bulamaz.
    cout<<fackt_recursive(5);*/

    // İLK 20 MERSENNE SAYISI
    /* int topla = 1;
    for (int i = 1; i <21; i++)
    {
      for (int j = i; j>=1; j--)
      {
         topla *= 2;
      }
      cout<<" "<<topla-1;
      topla = 1;
    } */
   
   //RASGELE SAYI ÜRETME

    /* int rg;
    srand (time(NULL)); // şekilde saati kullanarak rasgele bir sayi üretmek için besleme yapıyoruz seed
    for (int i = 0; i < 10; i++)
    {
        rg =1+ rand()%6; // 1 ile 6 arasında rasgele sayı üretir
        cout<<rg;
    } */
     
    // diziler ile işlemler
    /* int array[5];

    for (int i = 0; i <5; i++)
    {
        cout<<"dizinin "<<i<<". elemanini gir:";
        cin>>array[i];
    }
    
    int enb = array[0];
    int enk = array[0];
    int total = 0;
    for (int i = 1; i <5; i++){
        total += array[i];
        if (array[i]>enb)
        {
            enb = array[i];
        }
        else if (array[i]<enk){
            enk= array[i];
        }
    }

    cout<<"en buyuk deger : "<<enb<<endl;
    cout<<"en kucuk deger : "<<enk<<endl;
    cout<<"total: "<<total<<endl;
    cout<<"average: "<<(float)total/5; */

    //asal
    /* int n;
    cout<<"n: ";
    cin>>n;
    int asal;

    for (int i = 0; i <=n; i++)
    {
        for (int j = 2; j <=i; j++)
        {
            if (i%j == 0){

            }
            else
                asal = i;        
        }
        
    }
    cout<<asal;
 */

    // dizideki en büyük 3 eleman sıralama
    /* int size;
    cout<<"Login array size:";
    cin>>size;
    int array[size];

    for (int i = 0; i <size; i++)
    {
        cout<<"add "<<i<<". value in array:"<<endl;
        cin>>array[i];
    }
    
    int temp;
    for (int i = 0; i <size; i++)
    {
        for (int j = 0; j<size; j++)
        {
            if (array[i]<array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    int total = 0;
    for (int i = size-1; i > size-4; i--) // son üç elemanı büyük olanlardır ve bunların toplamı isteniyor.
    {
        total += array[i];
    }
    cout<<"Total:"<<total;
    cout<<endl;

    for (int i = 0; i < size; i++)
    {
        cout<<" "<<array[i];
    } */
    

    //cout<<(char)84<<(char)65<<(char)72<<(char)65;

    //char to binary
    /* int arr[4] = {84,65,72,65};
    int binary[4][7];
    int n;
    for (int i = 0; i <4; i++)
    {
        n = arr[i];
        for (int j = 6; j>0; j--)
        {
            binary[i][j] = n%2;
            n = n/2;
        }
        binary[i][0] = 1;
    }
    for (int i = 0; i <4; i++)
    { 
        for (int j = 0; j<7; j++)
        {
            cout<<binary[i][j];
        }
        cout<<endl;
    } */
    
    // 2 Oyuncu zar atma oyunu
    /* int n;
    cout<<"kac defa zar atilacak:";
    cin>>n;
    int ilk;
    int iki;
    int score = 0;
    srand(time(NULL));
    for (int i = 0; i <n; i++)
    {
        ilk = 1+ rand()%6;
        iki= 1+rand()%6;
        if (ilk>iki)
            score++;
        else if (iki>ilk)
            score--;
        
        cout<<ilk<<" "<<iki;
        ilk = 0; iki=0;
        cout<<endl;
    }
    
    if (score>0)
        cout<<"sonuc: 1.oyuncu kazanir";
    else if (score<0)
        cout<<"sonuc: 2. oyuncu kazanir.";
    else
        cout<<"beraber"; */
    

    //TRANSPOSE PROCESS
    /* int row,col;
    cout<<"row and col: ";
    cin>>row>>col;

    int matrix[row][col];
    
    for (int i = 0; i <row; i++)
    {
        for (int j = 0; j <col; j++)
        {
            cout<<"login "<<i<<" "<<j<<":  ";
            cin>>matrix[i][j];
            cout<<endl;
        }
    }
    for (int i = 0; i <row; i++)
    {
        for (int j = 0; j <col; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    // yeni bir matris olusturmak gerekir.
    cout<<"transpose edilmis matris: "<<endl;
    //trans
    int counter = 0;
    while (counter<col)
    {
        for (int i = 0; i <row; i++)
        {
            cout<<matrix[i][counter]<<" ";
        }
        cout<<endl;
        counter ++;
        
    } */
    
    //MATRİSLERDE TOPLAMA-ÇIKARMA İŞLEMİ
    /* int a[3][2] = {1,3,1,0,1,2};// boyutlar aynı olmalı
    int b[3][2] = {0,0,7,5,2,1};
    //matrislerde toplam işlemi,
    int toplanan[3][2];// toplama işlemi sonucunda 3x2 lik bir matris elde edilir.
    int cikarma[3][2];
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j <2; j++)
        {
            toplanan[i][j] = a[i][j]+b[i][j];
            cikarma[i][j] = a[i][j]-b[i][j];
        }
        cout<<endl;
        
    }
    //toplanan matris yazdırıldı.
    cout<<"toplama islemi"<<endl;
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j <2; j++)
        {
            cout<<toplanan[i][j]<<" ";
        }
        cout<<endl;
        
    }
    cout<<"cikarma islemi"<<endl;
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j <2; j++)
        {
            cout<<cikarma[i][j]<<" ";
        }
        cout<<endl;
        
    } */
    
    
    
    //MATRİSLERDE ÇARPMA
    /* int a[2][3] = {1,2,-1,3,1,4};
    int b[3][2] = {2,1,-1,6,7,2};
    int carpma[2][2];// carpam işleminde 1. matrisin sütun sayısı ile 2. matrisin satır sayısı aynı olmalı. degilse T ile aynı yapılabilir.
    int toplam = 0;

    for (int i = 0; i < 2; i++)// a matrisi için satır sayısını i ye atadık
    {
        for (int j = 0; j <2; j++){ // b matrisinin kolon sayısını aldık j ye verdik 
            //cout<<a[i][j]<<" ";
            //cout<<b[j][i]<<" "; 

            //cout<<a[i][j]*b[j][i]<<endl;
            for (int k = 0; k <3; k++){   // burada her ikisinde ortak olan 3 olduğu için k degerine 3 verdik
              toplam += a[i][k]*b[k][j]; // için satır sayısı ve b için kolın sayısı 2 oldu yani a[i]  ve b[j]

              //cout<<a[i][k]*b[k][j];
            }
            cout<<"topl: "<<toplam<<endl;
            toplam = 0;
            cout<<endl;
        }
        
    } */
   
   // pointer aritmetiği ile dinanik bellek kullanımı
   /* int n;
   int *array = (int *)malloc(sizeof(int)*n);
   cout<<" login n: ";cin>>n;

   for (int i = 0; i <n; i++)
   {
       cout<<i<<". deger: ";
       cin>>*(array+i);
   }
   for (int j = 0; j <n; j++)
        
        cout<<" "<<*(array+j); */
    // HER DİZİ BİR POİNTER DIR. FONKS GÖNDERİRKEN AYRICA POİNTER TANIMLAMA YA GEREK YOKTUR DİREK GÖNDEREBİLİRİZ.
   
    //pointer ile dizideki ranj bulma fonksiyon ile
    /* int n;
    int *arr =(int *)malloc(sizeof(int)*n);
    cout<<"login n:";cin>>n;

    for (int i = 0; i <n; i++)
    {
        cout<<i<<". deger: ";
        cin>>arr[i];
    }

    cout<<ranj(arr,n);*/
    
    //
    
    //polindrome

    /* string kelime;
    cout<<"please enter some value: ";cin>>kelime;
    char kelime2[kelime.size()+1];
    int counter = 0;
    for (int i = kelime.size()-1; i>=0; i--)
    {
        if (kelime[i]!= '\0')
            kelime2[counter]=kelime[i];
            counter++;
    }
    if (kelime == kelime2)
        cout<<"girilen deger palindromdur";
    else
        cout<<"girilen deger palindrome degildir."; */
    
    // DOSYA İSLEMLERİ

    //yazdirma

    ofstream dosya,output; // fstream içindeki fonksiyonları kullanmak bir dosya pointeri olusturduk.

    dosya.open("C:\\Users\\akmet\\desktop\\dene.txt"); // istenilen dizinde bir dosya açıldı. default olarak ./ yerde açar.

    if (dosya.is_open()) // eger dosya basarili bir sekilde acildiysa yazdırma islemi yaptik.
    {
        dosya<<"ali baba"; // dosya<< le yazdirma yapilir.
        dosya.close();
    }
    else
        cout<<"dosya acilamadi.";

    // okuma ve tersine çevirme
    ifstream dosya2("C:\\Users\\akmet\\desktop\\dene.txt");
    string s;
    //output.open("C:\\Users\\akmet\\desktop\\cikti.txt"); // ters için yeni txt acma
    while (getline(dosya2,s))
    {   //cout<<s<<endl;// tam okuma yapar
        for (int i = s.size(); i >=0; i--)// tersine çevirme
        {
            cout<<s[i];
            //output<<s[i];// ters olanı yazdırma
        }
        
    }
    dosya2.close();
    output.close();
    
    

    getch();
    return 0;
}
//RANJ
/* int ranj(int *arr, int size){
    int enb = arr[0];
    int enk = arr[0];

    for (int i = 0; i <size; i++)
    {
        if (enb<arr[i])
            enb = arr[i];
        else if (enk>arr[i])
            enk = arr[i];
    }
    return enb-enk;
    
} */

//recursive (Öz yinelemeli fonksiyonlar)

/* int fackt_recursive(int n){

    if (n==1)
        return 1;
    return n*fackt_recursive(n-1);
} */

//factöritel ve kombinasyon fonksiyon gövdeleri
/* int factorial(int n){
    int n_fact=1;

    for (int i = n; i>=1; i--)
    {
        n_fact *= i;
    }
    return n_fact;
}

void combination(int n,int r){ // gelen verileri yukarıda tanımlanan factorail gönderip return edilen deger ile işlem yaptık
    int m= n-r;
    
    int comb = factorial(n)/(factorial(r)*factorial(m));
    
    cout<<"comb:"<<comb;

} */