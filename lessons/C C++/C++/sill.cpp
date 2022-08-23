#include <iostream>
#include <conio.h>
#include <map>

using namespace std;


map<char,char*> m;

int main(){
    
    char dizi[4] = {'A','B','C','D'};
    m.insert({'a',dizi});
    auto itr = m.begin();
    cout<<itr->first<<" "<<itr->second<<endl;
    for (int i = 0; i <4; i++)
    {   
        cout<<itr->second[i]<<endl;
    }
    
    


    getch();
    return 0;
}