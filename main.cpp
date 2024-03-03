#include <iostream>
using namespace std;

void dfs(int *num,int *tag,int size,int k){
    if(k==size){
        for(int i=0;i<size;i++){
            cout<<num[i]<<" ";
        }
        cout<<"\n";
        return ;
    }
    for(int i=0;i<size;i++){
        if(tag[i]==0){
            num[k]=i+1;
            tag[i]=1;
            dfs(num,tag,size,k+1);
            tag[i]=0;
        }
    }
}

int main(void){
    int n=4;
    cin>>n;
    int a[n],b[n]={0};
    dfs(a,b,n,0);
    return 0;
} 
