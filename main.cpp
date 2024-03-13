#include<iostream>
#include<string>
using namespace std;

const int N=210;
int t,e[N],ne[N]={-1},head=-1,idx=0;

void addToHead(int x){
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;
}

void add(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}

void deleteNode(int k){
    ne[k]=ne[ne[k]];
}

int main()
{
    cin>>t;
    int x;
    for(int i=0;i<10;i++){
        cin>>x;
        if(i==0){
            addToHead(x);
        }else{
            add(i-1,x);
        }
    }
    if(t==1){
        head=ne[head];
    }else{
        deleteNode(t-2);
    }
    for(int i=head;i!=-1;i=ne[i]){
        if(i==head){
            cout<<e[i];
        }else{
            cout<<" "<<e[i];
        }
    }
    return 0;
}
