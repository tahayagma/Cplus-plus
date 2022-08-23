#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    int n;
    cout<<"dugum sayisini gir: ";
    cin>>n;
    char nodeName[n];
    enum Nodes{} s;
    int dizi[n][n];

    for(int i =0;i<n;i++){
        cout<<i+1<<".dugum adi gir: "<<endl;
        cin>>nodeName[i];
    }

    for (int i = 0; i <n; i++)
    {   dizi[i][i] = 0;
        for (int j = i+1; j < n; j++)
        {
            cout<<nodeName[i]<<"-"<<nodeName[j]<<" arasinda kenar varsa 1 yoksa 0 gir: "<<endl;
            cin>>dizi[i][j];
            dizi[j][i] = dizi[i][j];
        }
        
    }

    for(int i =0; i<n;i++){
        for(int j = 0;j<n;j++)
            cout<<dizi[i][j]<<" ";
        cout<<endl;
    }
        
    getch();
    return 0;
}