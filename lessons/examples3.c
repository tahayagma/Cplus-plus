// kart dagitma
/* #include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void kar(int [][13]);
void dagit(const int[][13], const char *[], const char*[]);

int main(){

    int deste[4][13] = {0};
    //satirlar takimlari göstermektedir. 0. satir kupa takımı 1.satır karo 2.satır sinek 3.satir maça gösterir
    //sütunlar kartları temsil eder.0-9 sütunları sırasıyla As-10 kartlarını 10-12 ise vale kız ve papaz

    char *takim[4] = {"kupa","karo","sinek","maca"};
    char *taraf[13] ={"As", "iki", "Uc", "Dort","Bes", "Alti", "Yedi", "Sekiz","Dokuz", "On", "Vale", "Kiz", "Papaz"};

    srand(time(0));

    kar(deste);
    dagit(deste,takim,taraf);

    getch();
    return 0;
}

void kar(int deste[][13])
{   
    int satir,sutun,kart;

    for (kart = 1; kart <= 52; kart++)
    {
        satir = rand()%4;
        sutun = rand()%13;
        if (deste[satir][sutun] ==0)
        {
            deste[satir][sutun] = kart;
        }
        
    }
}

void dagit(const int deste[][13],const char *takim[],const char *taraf[])
{
    int satir,sutun,kart;
    for (kart = 1; kart <= 52; kart++)
    {
        for (satir = 0; satir <=3; satir++)
        {
            for (sutun = 0; sutun <=12; sutun++)
            {
                if (deste[satir][sutun] == kart)
                {
                    printf("%s  %s %c",takim[satir],taraf[sutun],kart%2==0?'\n':'\t');
                }   
            }   
        }
    }
} */

/* #include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void func1(int);
void func2(int);
void func3(int);

int main(){


    void(*f[3])(int)= {func1,func2,func3};
    // fonskiyonları bir pointer ile bir arada tuttuk *f[0] seklinde örneğin func1 çağrılır.

    int secim;
    printf("0 ile 2 arasinda bir sayi ya da cikis icin 3 girin:");
    scanf("%d",&secim);

    while (secim>=0 && secim<3)
    {
        (*f[secim])(secim);
        burada fonksiyonları bşr gösterici ile tuttuk ve gelen 1.secim fonksiyonu secer digeri ise
        fonksiyonun alacağı  degeri fonksiyona gönderir böylelikle fonksiyonları bir arada tuttuk
         printf("0 ile 2 arasinda bir sayi ya da cikis icin 3 girin:");
        scanf("%d",&secim);
    }

    printf("programin calismasi bitti\n");
    
    getch();
    return 0;
}

void func1(int a ){

    printf("%d degeri ile func1 cagrildi.\n");
}

void func2(int a ){

    printf("%d degeri ile func2 cagrildi.\n");
}

void func3(int a ){

    printf("%d degeri ile func3 cagrildi.\n");
} */

// İKİ SAYI ARASINDAKİ ASAL DEGERLERİ BULMA
/* #include <stdio.h>
#include <stdlib.h>
#include <conio.h>
# include <math.h>
void asal_bul(int);
int main(){

   //ASAL SAYİYİ BUL
   int sayi;
   
    while (1)
    {
         int counter = 0;
        printf("sayi gir:");
        scanf("%d",&sayi);

        for (int i = 2; i <sayi-1; i++)
        {
            if (sayi%i == 0)
            {
                counter++;
            }
        }
        
        if (counter == 0)
        {
            printf("sayi asaldir\n");
        }
        else printf("degildir\n");
    }
    
    int sayi1,sayi2;
    int large,small;
    int counter = 0;

    printf("sayilari gir:");
    scanf("%d %d",&sayi1,&sayi2);

    if (sayi1>sayi2)
    {
        large = sayi1;
        small = sayi2;
    }
    else 
        large = sayi2;
        small = sayi1;
    for (int i =small ; i <=large; i++)
    {
        asal_bul(i);
    }

    getch();
    return 0;
}

void asal_bul(int sayi)
{
    int counter = 0;
    for (int i = 2; i <sayi; i++)
    {
        if (sayi%i == 0)
        {
            counter++;
        }
    }
    
    if (counter == 0)
    {
        printf("%d asaldir\n",sayi);
    }
} */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){

    //RAKAMLARİ TOPLAMİ VE MUKEMMEL SAYİ BULMA
    /* int sayi;
    printf("sayi gir:");
    scanf("%d",&sayi);
    int N = sayi;
    int toplam = 0;
    int positive = 1;
    while (N!=0)
    {
        toplam += N%10;
        N = N/10;
    }
    printf("rakamlari toplami :%d",toplam);
    for (int i = 2; i < sayi; i++)
    {
       if (sayi%i == 0)
       {
           positive +=i;
       }
       
    }

    if (positive == sayi)
    {
        printf("\n%d sayisi mukemmeldir.",sayi);
    }
    else printf("\n%d sayisi mukemmel degildir",sayi); */
    
    //sonraki 10 asal sayi bul
    /* int sayi;
    int counter = 0;
    int c = 0;
    int n = 0;

    printf("bir sayi gir:");
    scanf("%d",&sayi);

    for (int i = 2; i <sayi-1; i++)
    {
        if (sayi%i == 0)
        {
            counter++;
        }
    }

    if (counter == 0)
    {   sayi = sayi+1;
        while (n<10)
        {
            for (int i = 2 ;i<sayi; i++)
            {
                if (sayi%i == 0)
                {
                    c++;
                }
            }
            if (c == 0)
            {
                printf("asal sayi: %d\n",sayi);
                n++;
            }
            sayi++;
        }
    }
    else printf("degildir\n"); */
    
    //girilen 10 sayilik dizi içinden ENK ve ENB bulma
    /* int sayi[10];
    int enb;
    int enk;

    for (int i = 0; i < 10; i++)
    {
       printf("%d .sayiyi gir:",i+1);
       scanf("%d",&sayi[i]);
    }
    enb = sayi[1];
    enk = sayi[0];
    
    for (int i = 0; i < 10; i++)
    {
        if (sayi[i]>enb)
        {
            enb = sayi[i];
        }
        else if (sayi[i]<enk)
        {
            enk = sayi[i];
        }
    }
    printf("enk: %d",enk);
    printf("enb: %d",enb);
     */
    
    //girilen 5 sayının küçükten büyüğe sıralama
    /* int dizi[5];

    for (int i = 0; i < 5; i++)
    {
        printf("%d. sayiyi gir:",i+1);
        scanf("%d",&dizi[i]);
    }
    int temp;
    for (int i = 0; i < 5; i++)
    {
        for (int n  = i+1; n < 5; n++)
        {
            if (dizi[i]>dizi[n])
            {
                temp = dizi[i];
                dizi[i] = dizi[n];
                dizi[n] = temp;
            }   
        }
    }
    for (int i = 0; i <5; i++)
    {
        printf("%d ",dizi[i]);
    } */
    
    // Linear arama
    /*int sayi[10] = {54,21,80,3,65,89,20,15,87,90};
    int aranan;
    printf(" aranan deger:");
    scanf("%d",&aranan);

    for (int i = 0; i <sizeof(sayi)/4; i++)
    {
        if (sayi[i] == aranan)
        {
            printf("%d degeri dizi icinde var",aranan);
        }
        
    } */
    
    // MATRİS TANILAMA VE TRASNPOSE İŞLEMİ
    /* int satir,sutun;
    printf("matris boyutu gir:");
    scanf("%d %d",&satir,&sutun);

    int array[satir][sutun];

    for (int i = 0; i <satir; i++)
    {
        for (int n = 0; n < sutun; n++)
        {
           printf("array[%d][%d] degeri gir:",i,n);
           scanf("%d",&array[i][n]);
        }
        
    }
    printf("\n");
    for (int i = 0; i <satir; i++)
    {
        for (int n = 0; n < sutun; n++)
        {
           printf("[%d]",array[i][n]);
           printf(" ");

        }
        printf("\n");
    }

    //transpose
    printf("\nmatrix transpose edilmis\n\n");
    int counter = 0;
    while (counter<sutun)
    {
        for (int i = 0; i <satir; i++)
        {
            printf("[%d]",array[i][counter]);
            printf(" ");
        }
        printf("\n");
        counter++;
    } */
    
    char char1[50];
    char char2[50];

    printf("char1 gir: ");
    scanf("%s",&char1);

    printf("char2 gir:");
    scanf("%s",&char2);
    
    printf("char1: %d\nchar2: %d",strlen(char1),strlen(char2));

    if (strlen(char1)>strlen(char2))
    {
        printf("\nchar1 daha uzun: %d",strlen(char1));
    }
    else printf("\nchar2 daha uzun: %d",strlen(char2));
    

    getch();
    return 0;
}