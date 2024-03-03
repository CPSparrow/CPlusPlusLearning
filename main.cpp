#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

/*
d1 = 149
d2 = 149
clk_tck = 1000
(注：该结果随机器变化会有波动)
*/

clock_t start,stop;
double d1,d2;

int f1(int *num,int n){
    if(n){
        return f1(num,n-1)+num[n-1];
    }
    return 0;
}

int f2(int *num,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=num[i];
    }
    return sum;
}

int main(void){
    int n=1000;
    int num[n];
    for(int i=0;i<n;i++){
        num[i]=i*2-3;
    }
    start=clock();
    for(int i=0;i<90000;i++)int j=f1(num,n);
    stop=clock();
    d1=((double)(stop-start));
    start=clock();
    for(int i=0;i<90000;i++)int j=f2(num,n);
    stop=clock();
    d2=((double)(stop-start));
    cout<<"d1 = "<<d1<<"\n";
    cout<<"d2 = "<<d2<<"\n";
    cout<<"clk_tck = "<<CLK_TCK<<"\n";

    return 0;
} 
