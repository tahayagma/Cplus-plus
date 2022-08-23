#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//dinamik yıgın programı
/*Yıgınlarda LIFO kuralı geçerlidir. Yani Last in First Out(son giren ilk çıkar veya ilk giren son çıkar)
pop yapılırken yıgından en son eklenen deger çıkartılır yani en üstten atar ve atılan deger return edilir.*/

struct yiginDugumu{ // kendine dönüşlü yapı
    int veri;
    struct yiginDugumu *sonrakiPtr; // yıgındugumundan bir tane daha yapı oluşturduk
};

typedef struct yiginDugumu YiginDugumu; //
typedef YiginDugumu *YiginDugumuPtr; // yukarıda typedef kullandığımız için tekrar yapı tanımlarken struct yazmaya gerek kalmaz

//-------------DEFİNED FUNCTIONS------------------------- 
void push(YiginDugumuPtr *,int);
int pop(YiginDugumuPtr *);//pop işleminde pop edilen return edilir,
int bosMu(YiginDugumuPtr);
void yiginYazdir(YiginDugumuPtr);
void menu(void);

int main(){
    
    YiginDugumuPtr yiginPtr = NULL; //yıgının ilk degeri yani yıgınınn sonunu belirtmek için NULL olarak atanır
    int secim,deger;

    menu();
    printf("?");
    scanf("%d",&secim);

    while (secim != 3)
    {
        switch (secim)
        {
        case 1: // degeri yığuna push eder
            printf("Push icin bir deger gir:");
            scanf("%d",&deger);
            push(&yiginPtr,deger);
            break;
        case 2: // yıgından degeri pop et
            if(!bosMu(yiginPtr))
               printf("Atilan deger: %d\n",pop(&yiginPtr));

            yiginYazdir(yiginPtr);
            break;
        default:
            printf("Gecersiz islem.\n\n");
            menu();
            break;
        }
    printf("?");
    scanf("%d",&secim);
    }
    
    printf("program sonlandi.\n");
    getch();
    return 0;
}

// Menü yazdir

void menu(void)
{
    printf("Seciminizi girin:\n"
            "1 Yigina bir deger push et\n"
            "2 Yigindan degeri pop et\n"
            "3 Programi sonlandir\n");
}

// Yıgına Push et

void push(YiginDugumuPtr *ustPtr,int info)
{
    YiginDugumuPtr yeniPtr; // dinamik bellek için yeni yapı oluşturduk

    yeniPtr = malloc(sizeof(YiginDugumu)); //yigin dugumu boyutunda bellekte yer ayırdık ve bunu yeniPtr atadık

    if(yeniPtr !=NULL){ // bellekte boş alan olup olmadığnı sorguladık başarı değilse NULL degeri döndürür.
    //bellek ayırma başarılı ise aşağıdaki işlemleri yap
        yeniPtr->veri =info; // bu yapı yeniPtr.veri ile aynıdır. info degerini veriye atadık 
        yeniPtr->sonrakiPtr = *ustPtr;
        *ustPtr = yeniPtr;
    }
    else
        printf("%d eklenemedi yetersiz alan.\n",info);
}

// Yıgının üstünden bir dügüm pop et
int pop(YiginDugumuPtr *ustPtr)
{
    YiginDugumuPtr geciciPtr;
    int popDeger;

    geciciPtr = *ustPtr; // ustPtr gecici olarak bir ptr de tuttuk.
    popDeger = (*ustPtr)->veri; // ardından pop edilcek degeri de ustPtr de n çektik
    *ustPtr = (*ustPtr)->sonrakiPtr; // ve ustPtr degerini sonraki ptrye atadık bu şekilde baştan sona doğru gider
    free(geciciPtr); // gecici ptryi serbest bırakıyoruz yani boşaltıyoruz.
    return popDeger;
}

// Yıgını yazdir
void yiginYazdir(YiginDugumuPtr suandakiPtr)
{
    if(suandakiPtr == NULL)
        printf("Yigin bostur.\n");
    else{
        printf("Yigin:\n");

        while (suandakiPtr != NULL) // suandakiPtr NULL degilse 
        {
            printf("%d-->",suandakiPtr->veri); // suandakiPtr den veri degeri çek ve yazdır.
            suandakiPtr = suandakiPtr->sonrakiPtr; // suandakiPtr degerini de bir sonraki Ptr olarak degistir
        }
        printf("NULL \n\n");
    }
}

// Yıgın Boş mu

int bosMu(YiginDugumuPtr ustPtr)
{
    return ustPtr == NULL;
}