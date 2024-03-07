#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n=10;
    cin>>n;
    int a[25][25]={0};
    for(int i=0;i<25;i++){
        a[i][0]=a[i][i]=1;
    }
    for(int i=2;i<25;i++){
        for(int j=1;j<i;j++){
            a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<i;j++){
            cout<<a[i-1][j-1]<<" ";
        }
        cout<<a[i-1][i-1]<<endl;
    }
    for(int j=1;j<n;j++){
        cout<<a[n-1][j-1]<<" ";
    }
    cout<<a[n-1][n-1]<<flush;
    return 0;
}
