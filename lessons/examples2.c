#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// 2 SAYININ EBOB DEGERİNİ BUL
/* int ebob(int,int);


int main(){

     
    int sayi1,sayi2;
    while (1)
    {
        printf("ebob icin iki tamsayi girin:");
        scanf("%d %d",&sayi1,&sayi2);

        printf("\n%d ve %d sayilarinin ebob degeri : %d\n\n",sayi1,sayi2,ebob(sayi1,sayi2));
    }
   

    getch();
    return 0;
}

int ebob(int sayi1, int sayi2){
    int enk= sayi1;
    int enb= 1;
    if (enk<sayi2)
    {
        enk=sayi2;
    }
    
    for (int i = 2; i <=enk; i++)
    {
        if (sayi2%i == 0 && sayi1%i == 0)
        {
            if (enb<i)
            {
                enb = i;
            }
            
        }
    }
    return enb;
} */


int main(){
    // YAZI TURA
    /* nt number;
    int yazi = 0;
    int tura=0;

    for (int i = 0; i <100; i++)
    {
       number = rand()%2;
       if (number == 0){
           tura++;
       }
       else yazi++;
    }
    
    printf("100 atisata toplam\n%d defa yazi\n%d defa tura geldi",yazi,tura);
 */


    // SAYI TUTMACA
    /* int sayi;
    int number;
    char chose;
    while (1)
    {  
        number = 1+rand()%1000;
        printf("%d\n",number);
        printf("1-1000 arasinda bir sayi tuttum\nTahmin edebilir misin?\n");
        printf("Lutfen ilk tahminini gir:");
        scanf("%d",&sayi);
        if (sayi == number)
        {
           printf("Mukemmel bildiniz !\n");
           printf("Tekrar oynamak ister misin (E ya da H)?\n");
           scanf("%c",&chose);
           if (chose == 'E')
           {
              continue;
           }
           else break;
           
        }

        else if (sayi>number)
        {
            printf("Cok buyuk tekrar deneyin\n");
            continue;
        }
        else 
        printf("Cok kucuk tekrar deneyin\n");
        continue;
        
       
    } */
    
    // BUBLE SORT

    /* int dizi[10] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    int temp,tur = 1;

    while (tur<=9)
    {
        for (int i = 0; i < 10; i++)
        {
            if (dizi[i]>dizi[i+1])
            {
                temp = dizi[i]; //büyük olanı bir yerde tuttuk
                dizi[i] = dizi[i+1]; //büyük olanın yerine küçüğü atadık
                dizi[i+1]= temp; //küçüğün yerine de büyük olanı atadık
            }
            
        }
        tur++;
    }

    
    for (int i = 0; i < 10; i++)
    {
        printf(" %d",dizi[i]);
    } */
    
    // verilen dizinin mod medyan ve ortalamasını bulma
    // fonksiyınlarda yazılan cost ile dizini fonksiyon içinde değişmesi engelleriz.
    /* int frekans[10] = {0};
    int mod = frekans[0];
    int modi;
    int toplam = 0;

    int array[99] = {6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
                    7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
                    6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
                    7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
                    6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
                    7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
                    5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
                    7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
                    7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
                    4, 5, 6, 1, 6, 5, 7, 8, 7 };

    for (int i = 0; i <=99-1; i++)
    {   toplam += array[i];
        for (int j = 1; j <10; j++)
        {
            if (array[i] == j)
            {
               frekans[j]++;
            }
            
        }
           
    }
    
    for (int i = 1; i <10; i++)
    {
        printf("%d cevab frekansi: %d\n",i,frekans[i]);
        if (mod<frekans[i])
        {
            mod = frekans[i];
            modi = i;
        }
        
    }
    printf("\nmodu %d  gecme frekansi: %d",modi,mod);
    printf("\ncevaplarin ortalama degeri: %.4f",(double)toplam/99); */
    
    
    // İKİLİ ARAMA (BINARY SEARCH)

    /*int dizi[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    // NOT EGER DİZİ SIRALI DEGİLSE SIRALANMASI LAZIM

    /*En kötü durumda ikili arama, 1024 elemanlı bir dizide arama yaparken en fazla 10 karşılaştırma yapacaktır.
    1048576(220) elemanlı bir dizide arama değerini bulmak en fazla 20 karşılaştırma gerektirmektedir.
    Bir milyar eleman içeren bir dizide arama değerini bulmak için en fazla 30 karşılaştırma yapılmalıdır

    int aranan;
    int ort;
    int alt = 0;
    int ust = (sizeof(dizi)/4)-1;    
    printf("aranan:");
    scanf("%d",&aranan);
    while (alt<=ust)
    {
        ort = dizi[(alt+ust)/2];
        printf("%d\n",ort);

        if (aranan == ort)
        {
            printf("deger bulundu. %d\n",aranan);
            break;
        }
        else if (aranan>ort)
        {
            alt = ((alt+ust)/2)+1;
        }
        else if (aranan<ort)
        {
            ust = ((alt+ust)/2)-1;
        }
        else
            printf("deger bulunamadı.");  
    } */
    

    // 2 ZAR ATMA OYUNU

   /*  int zar1;
    int zar2;
    int toplam;
    long int dizi[36000];
    int counter = 1;
    while (counter<=36)
    {   zar1 = 1+rand()%6;
        zar2 = 1+rand()%6;
        toplam = zar1+zar2;
        dizi[counter] = toplam;
        printf("zar1: %d--zar2: %d\n",zar1,zar2);
        printf("toplam: %d\n",toplam);
        counter++;
    } */
    

    // UCUS REZERVASYON

   /*  int icilmeyen[5] = {0}; // tüm degerlerin ilk ataması 0 olarak yapildi.
    int icilen[5] = {0};
    int chose;
    int koltuk;
    while (1)
    {
        printf("Sigara icilen bolum icin '1' e  icilmeyen bolum icin '2' ye basin\n");
        scanf("%d",&chose);
        if (chose == 1)
        {
            koltuk = 1+rand()%5;
            if (icilen[koltuk]==0)
            {
                printf("icilen bolum koltuk numarasi: %d\n",koltuk);
                icilen[koltuk] = koltuk;
            }
            else printf("koltuk dolu");
            
            
        }
        else if (chose == 2)
        {
            koltuk = rand()%10;
            if (icilmeyen[koltuk]==0)
            {
                printf("icilen bolum koltuk numarasi: %d\n",koltuk);
                icilmeyen[koltuk] = koltuk;
            }
            else printf("koltuk dolu");
        }
    } */
    
    //palindrome stringler

    /* char a[100],b[100];

    printf("Enter a string:");
    gets(a);

    strcpy(b,a); // a b'ye kopyalandı
    strrev(b); // string tersine çevrildi
    printf("b : %s\n",b);
    printf("a : %s\n",a);
    if (strcmp(a,b)==0) //strcpm ile karsilastirma yapıldı  esitse 0 küçükse 0 da küçük büyükse 0 dan büyük deger döner
    {
        printf("it is palindrome string");
    }
    else printf("is not palindrome string"); */
    
    //Lienar Searching

    /* int wanted;
    int array[10] = {12,52,10,0,3,24,56,74,88,65};
    printf("Enter value want to find:");
    scanf("%d",&wanted);

    for (int i = 0; i <sizeof(array)/4; i++)
    {
        if (array[i] == wanted)
        {
            printf("\n%d Match the value in array",wanted);
            break;
        }
    } */
    
    // STRING LISTE
    /* char *array[4] ={"kupa","karo","sinek","maca"}; //pointerler ile sizeofta 8'e bölünmeli
    for (int i = 0; i < sizeof(array)/8; i++)
    {
        printf("%s\n",array[i]);
    } */
    
   


    getch();
    return 0;
}