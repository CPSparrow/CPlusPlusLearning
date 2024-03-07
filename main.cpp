#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int m,n;
    cin>>m>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int j=0;j<m;j++){
        //move
        int t[n];
        for(int i=0;i<n;i++){
            t[i]=a[i][n-1];
        }
        for(int i=n-1;i>0;i--){
            for(int k=0;k<n;k++){
                a[k][i]=a[k][i-1];
            }
        }
        for(int i=0;i<n;i++){
            a[i][0]=t[i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
