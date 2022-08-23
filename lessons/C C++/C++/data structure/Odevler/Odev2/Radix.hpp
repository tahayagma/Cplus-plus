#ifndef RADIX_HPP
#define RADIX_HPP

class Radix{
    public:
    struct num{
        int n;
        int* arr;
        
    };
    int maxSize(num);
    num RadixSort(num,int);
    int* radix(int[],int);
};

#endif