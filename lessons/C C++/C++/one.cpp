#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

void fackt(int);

int main()
{
   //STRİNG
   /* string name,surname;

   cout<< "login name: ";
   cin>>name;

   cout<< "login surname: ";
   cin>>surname;

   cout<<"Entry name is: "<<name+" "+surname<< endl; */

   //İF-ELSE BLOK
   /* string password = "tahayagma";

   string input;
   while (1)
   {
      cout<<"lutfen parola girin: ";
      cin>>input;

      if (input == password)
      {
         cout <<"Password valid\n";
      }
      else if (input=="q")
      {
         break;
      }
      
      else cout <<"password invalid\n";
   } */
   
   
   //FAKTÖRİYEL
   /* int toplam = 1;
   int sayi;
   cout << "faktoriyel icin bi sayi gir:";
   cin>> sayi;

   for (int i = sayi; i >1 ; i--)
   {
      toplam *=i;
   }

   cout << "sayiniN faktoriyeli: "<<toplam; */
   

   //Diziler

   /* int array[3] = {1,5,6};

   for (int i = 0; i < 3; i++)
   {
      cout << " "<<array[i];
   } */
   int sayi;
   cout << "login bir sayi:";
   cin>>sayi;

   fackt(sayi);
   
   getch();
   return 0;
}

void fackt(int sayi){
   int toplam = 1;

   for (int i = sayi; i >1; i--)
   {
      toplam *= i;
   }
   cout<< "faktoriyel :"<<toplam;
}