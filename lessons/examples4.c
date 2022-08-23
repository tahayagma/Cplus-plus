#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int main(){
    // STRİNG İŞLEMLERİ

    /* const char *str = "deneme olarak bu botu girilmistir.";
    const char *str2= "k";
    int bul = 'p';


    //printf("%s",strchr(str,'u')); // str içindeki ilk u degerinden sonrasını alır.

    //printf("%c",*strpbrk(str,str2)); //str içinde bulduğu ilk 'K' karakterini döndürür.

    //printf("%s",strrchr(str,bul));//str içindeki ilk bul degerinden sonrasını alır. Yoksa return (null)

    //printf("%s",strstr(str,"bu")); //str içindeki ilk bu degerinden sonrasını alır. Yoksa return (null)

    char split[] = "denee olarak su fırın yapıldı ve attı";
    char *ptratom;
    ptratom = strtok(split," "); // ilk deger ile bölme işlemi(split) yapar ve ilk kelimeyi döndürür.

    printf("%s",ptratom);
     */


    /* char c = 'b';
    char a = 'a';
    
    //printf("'%c'rakam %s",c,isdigit(c) ? "dır":"degildir");

    
    printf("%s",strcmp(c,a));
 */

    /* char metin;

    char chr;
    int counter = 0;

    printf("metin gir:");
    gets(metin);

    printf("karater gir:");
    scanf("%s",&chr);
    printf("\n%d",strlen(metin));
    */
    
    // HARF FREQ BULMA
    /* char metin[100];
    char dene[100];
    int tekrar[26] = {0};

    printf("metin girin:");
    gets(metin);
    for (int i = 0; i <strlen(metin); i++)
    {
       dene[i] = toupper(metin[i]);
    }
    printf("-------------------------\n");
    puts(dene);
    //printf("%d",strcmp('A',65));
    int x,counter = 0;
    while (dene[counter] != '\0')
    {
        if (dene[counter]>='A' && dene[counter]<='Z')
        {
            x = dene[counter]-'A';
            tekrar[x]++;
        }
        counter++;
    }
    for (int i = 0; i <26; i++)
    {
        if (tekrar[i]>=1)
        {
            printf("%c harfi freq :%d\n",i+'A',tekrar[i]);
        }
        
    } */    
    
    
    //HARFLER
    /* for (int i = 65; i <91; i++)
    {
       printf("%d-%c\n",i,i);
    }
    printf("-----------kucuk harfler----------------\n");
    for (int i = 97; i <123; i++)
    {
       printf("%d-%c\n",i,i);

    } */
   
   



    getch();
    return 0;
}