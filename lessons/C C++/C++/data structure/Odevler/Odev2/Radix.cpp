#include "Radix.hpp"

int* Radix::radix(int array[],int n){
    num number;
    number.arr = array;
    number.n = n;
    int max = maxSize(number);
    for(int b = 10;max/(b/10)>0;b*=10){
        number = RadixSort(number,b);
    }
    return number.arr;
}

int Radix::maxSize(num number){
    int max = number.arr[0];
    for(int i=1;i<number.n;i++){
        if(number.arr[i]>max)
            max = number.arr[i];
    }
    return max;
}
Radix::num Radix::RadixSort(num number,int b){
    int n = number.n;
    int dizi[n];
    for(int i= 0;i<n;i++)dizi[i] = number.arr[i];
    int counter = 0;
    num new_arr;
    for(int i = 0;i<10;i++)
    {   
        for(int j= 0;j<n;j++)
        {  
            if((dizi[j]%b)/(b/10) == i)
                new_arr.arr[counter++]=dizi[j];
        }
    }
    return new_arr;
}