#include <iostream>
using namespace std;

int a[20],b[20]={0};
int n;

void dfs(int k){
    if(k==n+1){
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            a[k]=i;
            b[i]=1;
            dfs(k+1);
            b[i]=0;
        }
    }
}

int main(void){
    cin>>n;
    dfs(1);
    return 0;
} 
