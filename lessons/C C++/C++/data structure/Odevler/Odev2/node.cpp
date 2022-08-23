#include "node.hpp"
#include <stdio.h>
//#include <iostream>


node::node(int data=0,int* arr=0,int ArrLen = 0,node*left =NULL,node*right= NULL):data(data),left(left),right(right),ArrLen(ArrLen)
{
    for(int i=0;i<ArrLen;i++){
        dizi[i] = arr[i];
    }
};
