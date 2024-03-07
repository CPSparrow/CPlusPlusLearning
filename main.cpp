#include <iostream>
#include <algorithm>
using namespace std;

void f(void);

int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        f();
    }
    return 0;
}


///example
/*
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
*/

int _max(int a,int b){
    if(a>b)return a;
    else return b;
}

void f(void){
    int n;
    cin>>n;
    int num[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin>>num[i][j];
        }
    }
    num[1][0]+=num[0][0];
    num[1][1]+=num[0][0];
    for(int i=2;i<n;i++){
        num[i][0]+=num[i-1][0];
        for(int j=1;j<=i-1;j++){
            num[i][j]+=_max(num[i-1][j],num[i-1][j-1]);
        }
        num[i][i]+=num[i-1][i-1];

        /*//print process
        cout<<"time = "<<i<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                cout<<num[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(num[n-1][i]>max){
            max=num[n-1][i];
        }
    }
    cout<<max<<endl;
}
