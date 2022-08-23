#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


struct hirdavat
{
    int kayitNo;
    char ürünAdi[100];
    int miktar;
    double ucret;
};


/* struct musteriVerisi
{
    int hesapNo;
    char soyisim[15];
    char isim[10];
    double bakiye;
}; */


int main(){

    FILE *fPtr;

    struct hirdavat hirdavat1[8];
    

    if ((fPtr = fopen("hirdavat.dat","w")) == NULL)
        printf("dosya acilmadi");
    else
    {
        for (int i = 1; i <=8; i++)
        {
           printf("ürün kayit no:");
           scanf("%d",&hirdavat1[i].kayitNo);
           printf("Urun adi gir:");
           gets(hirdavat1[i].ürünAdi);
           printf("miktar gir:");
           scanf("%d",&hirdavat1[i].miktar);
           printf("ucreti gir:");
           scanf("%f",&hirdavat1[i].ucret);
        }

    }
    

    /* struct musteriVerisi bosVeri = {0,"","",0.0}; // ilk degerlerini 0 ve boş olarak atadık.

    FILE *cfPtr;

    if ((cfPtr = fopen("kredi.dat","w")) == NULL)
        printf("dosya acilmadi.");
    else
    {
        for (int i = 1; i <=100; i++)
            fwrite(&bosVeri,sizeof(struct musteriVerisi),1,cfPtr);
            // cfPtr ile gösterilen dosyaya msuteriVerisi boyutundaki bosVeri yapısının yazdırılmasını sağlar.
        
        fclose(cfPtr);
    } */

    getch();
    return 0;
}