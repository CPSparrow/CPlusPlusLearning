#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
//最大子列和问题(数据结构课本)
//max_subSequence
#define MAXK 1000

void run(int(*f)(int*,int),int* num,int size,int case_n){
    clock_t start,stop;
    start=clock();
    for(int i=0;i<MAXK;i++){
        (*f)(num,size);
    }
    stop=clock();
    cout<<"at "<<case_n<<": duration = "<<(double)stop-start<<"\n";
    return ;
}

int f1(int* num,int size){
    int thisSum=0,maxSum=0;
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            thisSum=0;
            for(int k=i;k<j;k++){
                thisSum+=num[k];
            }
            if(thisSum>maxSum){
                maxSum=thisSum;
            }
        }
        
    }
    return maxSum;
}

int f2(int* num,int size){
    int thisSum=0,maxSum=0;
    for(int i=0;i<size;i++){
        thisSum=0;
        for(int j=0;j<size;j++){
            thisSum+=num[j];
        }
        if(thisSum>maxSum){
            maxSum=thisSum;
        }
    }
    return maxSum;
}

int f4(int* num,int size){
    int thisSum=0,maxSum=0;
    for(int i=0;i<size;i++){
        thisSum+=num[i];
        if(thisSum>maxSum){
            maxSum=thisSum;
        }else if(thisSum<0){
            thisSum=0;
        }
    }
    return maxSum;
}

//分而治之的代码懒得打了，先放在这里吧
int max3(int a,int b,int c){
    return a>b?a>c?a:c:b>c?b:c;
}

int main(void){
    return 0;
} 
