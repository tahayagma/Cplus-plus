#include <iostream>
#include <conio.h>


using namespace std;

class matrixs{

    public:
        double transpose(double n[3][4]){
            int counter = 0;
            double trans_matris[4][3];
            cout<<"tranpose edilmis hali "<<endl;
            while (counter<4)
            {
                for (int i = 0; i <3; i++)
                    trans_matris[counter][i] = n[i][counter];
                counter++;
            }
            
            return n[3][4];
        }
        double multiply(double n[2][3],double m[3][2]){
            double multi_matrix[2][2]= {0};
            int toplam= 0;
            for (int i = 0; i < 2; i++)// a matrisi için satır sayısını i ye atadık
            {
                for (int j = 0; j <2; j++)
                { // b matrisinin kolon sayısını aldık j ye verdik 
                    
                    for (int k = 0; k <3; k++)// burada her ikisinde ortak olan 3 olduğu için k degerine 3 verdik
                        
                        toplam += n[i][k]*m[k][j]; // için satır sayısı ve b için kolın sayısı 2 oldu yani a[i]  ve b[j]
            
                    //cout<<"topl: "<<toplam<<endl;
                    multi_matrix[i][j]= toplam;
                    toplam = 0;
                    //cout<<endl;
                }       
            }

            cout<<"matrix is multiplying"<<endl;

            for (int i = 0; i <2; i++)
            {
                for (int j = 0; j <2; j++)
                    cout<<multi_matrix[i][j]<<" ";
                cout<<endl;
            }
            return 5; // void olmadığı için hata return olmazsa hata varmış gibi görünüyor
        }

        double Addition (double n[3][2],double m[3][2]){

            double addition[3][2];// toplama işlemi sonucunda 3x2 lik bir matris elde edilir.
            
            for (int i = 0; i <3; i++)
            {
                for (int j = 0; j <2; j++)

                    addition[i][j] = n[i][j]+m[i][j];
            }
            return 5;

        }

        double Subtraction(double n[3][2],double m[3][2]){

            double subtract[3][2];
            for (int i = 0; i <3; i++)
            {
                for (int j = 0; j <2; j++)
                
                    subtract[i][j] = n[i][j]-m[i][j];
            }

            return 5;

        }
};


int main(){

    double n[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    matrixs s;
    double a[2][3] = {1,2,-1,3,1,4};
    double b[3][2] = {2,1,-1,6,7,2};

    s.multiply(a,b);


    
    
    getch();
    return 0;
}

