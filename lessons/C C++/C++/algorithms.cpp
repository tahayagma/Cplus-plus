
/* BİNARY SEARCH
#include <iostream>
#include <conio.h>

using namespace std;
struct values
    {
        int *array;
        int index;
    };
int * sirala(int *,int);

struct values bs(int *,int,int);

int main(){
    int dizi[5] = {2,1,3,5,4};
    int size = sizeof(dizi)/4;
    int *c = sirala(dizi,size);
    for (int i = 0; i <size; i++)
        cout<<c[i]<<endl;

    getch();
    return 0;
}

struct values bs(int *dizi,int size ,int hedef){
    struct values s;
    int *s_dizi = sirala(dizi,size); 
    int bas = 0;
    int son = s_dizi[(size-1)];
    int orta = (bas+son)/2;
    int index = -1;
    while (bas<=son)
    {
        if (s_dizi[orta]>hedef)
            son = orta-1;
        else if (s_dizi[orta]<hedef)
            bas = orta+1;
        else 
            index = s_dizi[orta];
            break;
    }

    s.array = s_dizi;
    s.index = index;
    return s;
}

int  * sirala(int *dizi,int size)
    {
        int pivot = dizi[0];
        int temp;
        int counter = 0;
        while (counter<size)
        {
            for (int i = 1; i<size+1; i++)
            {
                if (dizi[i]<pivot){
                    temp = dizi[i-1]; // bir önceki değeri geçici olarak tutuyoruz
                    dizi[i-1] =dizi[i]; //ardından önceki değeri şuanki değer ile değiştirdik.
                    dizi[i] = temp; // şuanki değeri de bir önceki değer ile değiştirdik.
                }
                pivot = dizi[i]; // sonra pivot değerimizi bir sonraki değer olarak tanımlıyoruz
            counter++;
            }    
        }
        return dizi;
    }
 */


/* BFS(Breadth First Search)

#include <iostream>
#include <conio.h>
#include <queue>

using namespace std;
void BFS(int);


int main(){
    
    BFS(0);



    getch();
    return 0;
}

void BFS(int start){
    queue<int>kuyruk;
    int dizi[4][4] = {{0,1,0,0},{1,0,1,1},{0,1,0,0},{0,1,0,0}};
    bool visited[16] = {false}; // tüm değerler false ile dolduruldu.
    int ilk;
    kuyruk.push(start); // root değerini ilk olarak kuyruğa ekledik.
    while (!kuyruk.empty())
    {
        ilk = kuyruk.front(); // kuyruktaki ilk değer çekildi.
        visited[ilk] = true;
        for (int i = 0; i <4; i++)//4 satır ve 4 sütun olduğu için
        {
            if (dizi[ilk][i]==1 && visited[i] == false)
            {
                visited[i] == true;
                kuyruk.push(i);
            }
        }
        kuyruk.pop(); // ilk değer ziyaret edilip siliniyor ardından komşuları kuyruğa ekleniyor
    }

}*/


// DFS (Depth First Search)

#include <iostream>
#include <conio.h>
#include <stack>
#include <map>
#include <string>

using namespace std;


map<char,std::array<char,3>> m;

int main(){
    //char nodes[] = {'A','B','C','D'};
    /*char A_yavru[] = {'B','C'};
    char B_yavru[] = {'A','D'};
    char C_yavru[] = {};
    char D_yavru[] = {'A','B'};*/
    
    m['A'] = {'B','C'};
    m['B'] = {'A','D'};
    m['C'] = {};
    m['D'] = {'A','B'};
    
    /*auto itr = m.begin();
    cout<<itr->first<<" "<<endl;
    cout<<"second boyut: "<<for( int i= 0; itr->second[i];<<endl;*/

    for (auto itr = m.begin(); itr != m.end(); ++itr)
    {
        cout<<itr->first<<"\t";
        for(int i= 0; i<sizeof(itr->second)-1;i++)
            cout<<itr->second[i];
        cout<<endl;
    }
    

    /* for (int i = 0; i <sizeof(itr->second); i++)
    {   
        if (itr->second[i] == '\0')
        {
        }
        else
            cout<<"i: "<<i<<" ";
            cout<<itr->second[i]<<endl;
    } */
    
    
    /*string yavru;
    cout<<"yavrulari gir: ";
    cin>>yavru;
    int boyut = yavru.length();
    char neww[boyut];
    cout<<"new boyut: "<<sizeof(neww)<<endl;
    for (int i = 0; i <yavru.size(); i++)
    {
        if (yavru[i] == ',' || yavru[i]=='\0')
        {}
        else
            yavru[i]
    } */
    
    
    /* char yavru[] = {'A','B','C','D','E'};
    cout<<"yavru boyut: "<<sizeof(yavru)<<endl;
    m.insert({'a',yavru});
    auto itr = m.begin();
    cout<<itr->first<<" "<<itr->second<<endl;
    cout<<"yavru boyut: "<<sizeof(itr->second)<<endl;
     */
    getch();
    return 0;
}
