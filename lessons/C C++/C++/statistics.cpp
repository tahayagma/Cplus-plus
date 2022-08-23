#include <iostream>
#include <conio.h>
#include <math.h>



using namespace std;

class Statistics{

    public:

        double median(int data[],int len){
            
            //sorted array 
            int temp;
            for (int i = 0; i <len; i++)
            {
                for (int j = i+1; j <len; j++)
                {
                    if (data[i]>data[j])
                    {
                        temp = data[i];
                        data[i]= data[j];
                        data[j] = temp;
                    }
                }
            }

            // long array better useful below equal
            if (len%2 == 1)
                return data[((len+1)/2)-1];
            else
                return (double)(data[len/2]+data[(len/2)-1])/2;
        }

        double average(int data[],int len){
            int total= 0;

            for (int i = 0; i <len; i++)
                total += data[i];
            return (double)total/len;

        }

        int mod(int data[],int len){
            int temp[len] = {0};
            for (int i = 0; i < len; i++)
            {
                int temps = data[i];
                for (int j = i; j <len; j++)
                {
                    if (temps == data[j])
                        temp[i]++;
                }
    
            }
            int s = temp[0];
            int indis=0;
            for (int i = 1; i <len; i++)
            {
                if (s<temp[i])
                {
                   s = temp[i];
                   indis = i;
                }
            }
            if (s>=2)
               cout<<s<<"x -mod: "<<data[indis]<<endl;
               return data[indis];
        }

        double absolute_deviation(int data[],int len){
            int total=0;
            for (int i = 0; i <len; i++)
               total += data[i];

            int average_deviation = 0;
            for (int i = 0; i < len; i++)
                average_deviation += abs((double)data[i]-(total/len));
            
            return (double)average_deviation/len;
            
        }
        double variance(int data[],int len,bool sample = true){//default calculated for sample dataset
        // for population sample value equal false

            int total = 0;
            double av = average(data,len);
            //cout<<"av: "<<av<<endl;
            for (int i = 0; i <len; i++)
            {
                total += pow((data[i]-av),2);
            }
            if (sample == true)
                return (double)total/(len-1);
            else
                return (double)total/(len);
            
            
        }

        double standart_deviation(int data[],int len,bool sample = true){

            return sqrt(variance(data,len,sample));
        }

        double coefficient_of_variation(int data[],int len){
            
            return ((double)standart_deviation(data,len)/average(data,len))*100;
        }
        double covariance(int x[],int len_x,int y[],int len_y,bool sample = true){
        
            double x_average = average(x,len_x);
            double y_average = average(y,len_y);

            int total = 0;
            for (int i = 0; i <len_x; i++)

                total += (x[i]-x_average)*(y[i]-y_average);
            
            if (sample == true)
                return (double)total/(len_x-1);
            else
                return (double)total/len_x;
        }

        double correlation_coefficient(int x[],int len_x, int y[],int len_y, bool sample = true){

            double r = covariance(x,len_x,y,len_y,sample)/(standart_deviation(x,len_x,sample)*standart_deviation(y,len_y,sample));
            return r;
        }

        //LATER CHECK THİS FUNCTİON
        double rank_corr_coef(int x[],int y[],int n){

            int di= 0;
            for (int i = 0; i <n; i++)
            {
                di += pow((x[i]-y[i]),2); 
            }
            int p = 1-((6*di)/((n*n*n)-n));
            return p;
        }

        double skewness_coef(int x[],int len){

            double sk= (double)(average(x,len)-median(x,len))/standart_deviation(x,len,false);

            return 3*sk;
        }

        double kurtosis(int x[],int len){
            int total=0;

            for (int i = 0; i <len; i++)
            {
                total += pow((x[i]-average(x,len)),4);
            }
            
            return total/((len-1)*pow(standart_deviation(x,len),4));

        }
        double z_score(int x[],int len,double score){

            return (double)(score-average(x,len))/standart_deviation(x,len);
        }

        int factorial(int n){
            int fackt=1;
            for (int i = n; i>1; i--)
            {
                fackt *= i;
            }
            return fackt;
        }

        int combination(int n, int r){

            return factorial(n)/(factorial(r)*factorial(n-r));
        }
        int permutation(int n ,int r){
            
            return (factorial(n)/factorial(n-r));
        }
        
        double regression_analysis(int x[],int x_len ,int y[],int y_len,int pred_value=1){

            double x_mean = average(x,x_len);
            double y_mean = average(y,y_len);

            double total = 0;
            double x_total = 0;

            for (int  i = 0; i <x_len; i++)
            {
                total += (x[i]-x_mean)*(y[i]-y_mean);
                x_total += pow((x[i]-x_mean),2);
            }
            
            double b1 = total/x_total;
            double b0 = y_mean-(b1*x_mean);
            double yy;
            double SSE = 0;

            for (int  i = 0; i < x_len; i++)
            {   
                yy = b0+(b1*x[i]); // predict values
                SSE += pow((y[i]-yy),2);
            }
            double MSE = SSE/x_len;
            double RMSE = sqrt((SSE/x_len));
            cout<<"SSE: "<<SSE<<endl;
            cout<<"RMSE: "<<RMSE<<endl;
            cout<<"MSE: "<<MSE<<endl;
            cout<<"b1: "<<b1<<endl;
            cout<<"b0: "<<b0<<endl;
            cout<<"predic value: "<<b1*pred_value+b0<<endl;
            static double values[3] = {SSE,MSE,RMSE};

            //return values; 
        }
};

int main(){

    

    Statistics  s;
    
    int data[] = {10,15,15,17,18};
    int ld = sizeof(data)/sizeof(int);
    int y[] = {32,14,36,94,20};
    int ly = sizeof(y)/sizeof(int);
    s.regression_analysis(data,ld,y,ly,50);
    //cout<<"permutation: "<<s.permutation(10,3);
    //cout<<"absolute: "<<s.absolute_deviation(data,ld)<<endl;
    //cout<<"standart deviation: "<<s.standart_deviation(data,ld,false)<<endl;
    //cout<<"coveriance sample: "<<s.covariance(data,ld,y,ly)<<endl;
    //cout<<"coveriance population: "<<s.covariance(data,ld,y,ly,false);
    cout<<"correlation_coefficient: "<<s.correlation_coefficient(data,ld,y,ly)<<endl;
    //cout<<"belirlilik katsayisi: "<<pow(s.correlation_coefficient(data,y),2);
    //cout<<"rank corr coef: "<<s.rank_corr_coef(data,y);
    

    getch();
    return 0;
}