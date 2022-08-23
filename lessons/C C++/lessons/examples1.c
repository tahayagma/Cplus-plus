#include <stdio.h>
#include <conio.h>


int main(){

    /* int not = 60;

    printf("%s\n",not<=60 ? "Gectiniz":"kaldınız"); 
    //tek satır il/else kullandık. Eğer not 60 küçüy esit ise gectiniz değilse kaldınız yazacak

    //not >= 60 ? printf ( "Geçtiniz\n") : printf ( "Kaldınız\n" );     yukarıdaki ile aynı işlemleri yapar*/

    //NOT ORTALAMA HESAPLA
    /*float ortalama;
    int toplam = 0;
    int not;
    int a = 0;
    int ogrenci_sayisi;
    printf("sinava giren ogrenci sayisi:");
    scanf("%d",&ogrenci_sayisi);
    if (ogrenci_sayisi == 0 || ogrenci_sayisi<0)
    {
        printf("ogrenci sayisi sifirdan buyuk olmalidir");
    }
    else
    {
        while (a<ogrenci_sayisi)
        {
            printf("%d. ogrencinin notunu girin:",a+1);
            scanf("%d",&not);
            if (not<0)
            {
                printf("\nnot degeri sifirdan kucuk olamaz\n\n");
                continue;//döngünün basina gider
            }
            else
            {
                toplam += not;
                a++;
            }
        }
        
        ortalama = (float)toplam/ogrenci_sayisi; //cıkan sonucun tipi float yapıldı.

        printf("\nogrencilerin not ortalamasi: %.2f\n",ortalama);
    }*/
    

    //KOMİSYON MAASI HESAPLA
    /* float brut_satis;
    float toplam_maas;

    printf("Dolar cinsinden satis tutarini giriniz:");
    scanf("%f",&brut_satis);

    toplam_maas = 200+brut_satis*0.09;
    
    printf("Maas: %.2f $",toplam_maas); */
    
    //FAİZ HESAPLAR
    /*float anaPara;
    float faizOrani;
    int gunluk_faiz;
    float faiz_tutar;
    
    while(1)
    {   
        printf("Ana parayi gir:");
        scanf("%f",&anaPara);
        printf("Faiz Oranini gir:");
        scanf("%f",&faizOrani);
        printf("Kac gunluk faiz:");
        scanf("%d",&gunluk_faiz);

        faiz_tutar = (anaPara*faizOrani*gunluk_faiz)/365;

        printf("Faiz ucreti: %.2f $ dir\n",faiz_tutar);
        printf("----------------------------------\n\n");
    }*/
    
    //KARE CİZDİRME
    /*// ici dolu kare
    int kenar_sayisi;
    printf("satir ve sutun gir:");
    scanf("%d",&kenar_sayisi);

   /* for (int i = 0; i<=kenar_sayisi; i++)
   {    
       for (int i = 0; i <=kenar_sayisi; i++)
       {
           printf(" *");
       }
       printf("\n");
   }
    //ici boş
   for (int i = 0; i<=kenar_sayisi; i++)
   {    
       for (int j = 0; j <=kenar_sayisi; j++)
       {    
           if (i == 0 || i == kenar_sayisi)
           {
               printf("*");
           }
           else
           {
               printf(" ");
           }
       }
       printf("\n");
   }*/

    //PALİNDROME SAYİ BUL
    /*int sayi;
    int rakam;
    int counter=0;

    printf("sayi gir:");
    scanf("%d",&sayi);
    int N  = sayi;
    int M= sayi;

    while (N!=0)
    {
        N%10;
        counter++;
        N= N/10;
        
    }
    int dizi[counter];

    for (int i = 0; i < counter; i++)
    {
        rakam = sayi%10;
        dizi[i]= rakam;
        sayi = sayi/10;
    }

   if (dizi[0] == dizi[counter-1] && dizi[1] == dizi[counter-2])
   {
       printf("\n%d sayisi palindrome bir sayidir.",M);
   }*/

    // KAÇ TANE 7 RAKAMİ VARDİR.
    /*int sayi;
    int N;
    int counter = 0;
    int rakam;
    
    printf("sayi gir:");
    scanf("%d",&sayi);
    N = sayi;
    while (N!= 0)
    {
        rakam = N%10;
        if (rakam == 7)
        {
            counter++;
        }
        N = N/10;
    }
    
    printf("%d tane 7 rakami vardir.",counter);*/

    //KARE OLUSTUR
    /*for (int i = 0; i < 6; i++)
    {
       for (int j = 0; j < 15; j++)
       {
           if (j%2 == 0)
            {
                printf(" *");
            }
       }
       printf("\n");
       
       
    }*/
    
    //tek cift toplama
    /* int counter=2;
    int counter1=1;
    for (int i = 2; i <=30; i+=2)
    {   
        counter+=i;
    }
    printf("cift toplamlar: %d\n",counter);

    for (int j = 1; j <=15; j+=2)
    {
        counter1+=j;
    }
    
    printf("tek toplamlar: %d",counter1); */

    //FOR İLE FAKTÖRİYEL
    /* int toplam = 0;
    int factorail =1;
    for (int i = 1; i<=5; i++)
    { 
        for (int j = 1; j<=i; j++)
        {   printf("%d\n",j);
            factorail*=j;
        }
        toplam += factorail;
        factorail=1;
    }
    
    printf("%d",toplam); */

    //girilen ilk sayi dizinin uzunluğunu veriyor ve ENK bulunur 
    /* int sayi;
    printf("1.sayiyi gir:");
    scanf("%d",&sayi);

    int dizi[sayi-1];
    dizi[0] = sayi;

    for (int i = 1; i < sayi; i++)
    {
        printf("%d.sayiyi gir:",i+1);
        scanf("%d",&dizi[i]);
    }
    int enk;
    enk = dizi[0];
    for (int i = 1; i <sayi; i++)
    {
        if (enk>dizi[i])
        {
           enk = dizi[i];
        }
        
    }
    printf("en kucuk deger: %d",enk); */
    
    int hipo;

    for (int i = 1; i <=500; i++)
    {
        for (int n = 1; n <=500; n++)
        {
          hipo = (i*i)+(n*n);
          if (hipo<=500)
          {
              printf("kenar1:%d kenar2: %d hipo: %d\n",i,n,hipo);
          }
          
           
        }
        
    }

    getch();
    return 0;
}