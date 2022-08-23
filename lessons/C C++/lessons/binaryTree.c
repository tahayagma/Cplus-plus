 #include <conio.h>
 #include <stdio.h>
 #include <stdlib.h>
/*bir düğüm yapısıdır her düğümde bir int tipinde bi veri tutulacaktır. Her düğümde düğümün kendisinden
sonra gelen alt ağa.ların düğümlerini işaret etmek için iki işaretçi tanımlanmıştır.*/
struct dugum
{
    int veri;
    struct dugum *sol;
    struct dugum *sag
};

struct dugum *kok = NULL; // kök düğümüne null deger atandı

struct dugum *dOlustur(int sayi)
{
    struct dugum *yeniDugum = (struct dugum*)malloc(sizeof(struct dugum));
    yeniDugum->veri= sayi;// fonksiyona gelen sayiyi yeni düğümün veri değişkenine atadık.
    yeniDugum->sag =NULL;
    yeniDugum->sol = NULL;
    return yeniDugum;
};

 int main(){

    struct dugum *kokDugum = dOlustur(40); //dolutur funt int sayi gönderip bir düğüm oluşturduk.
    struct dugum *dugumA = dOlustur(50); 
    struct dugum *dugumB = dOlustur(60);
    struct dugum *dugumC = dOlustur(70); 
    struct dugum *dugumD = dOlustur(80);
    kokDugum->sol = dugumA; /*kok düğümün sol işaretçisi dugumA'yı sag işaretçisi sie dugumB'yi işaret eder.*/
    kokDugum->sag = dugumB;
    dugumB->sol = dugumC;
    dugumB->sag = dugumD;






     getch();
     return 0;
 }