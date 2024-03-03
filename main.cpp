#include <iostream>
#include <algorithm>
using namespace std;

struct _bw{
    int w;
    int v;
    double p;
}bw[10001];

int cmp(_bw a,_bw b){
    return a.p>b.p;
}

int main(void){
    int n,c;
    cin>>n>>c;
    double ans=0;
    for(int i=0;i<n;i++){
        cin>>bw[i].w>>bw[i].v;
        bw[i].p=(double)bw[i].v/(double)bw[i].w;
    }
    sort(bw,bw+n,cmp);
    int i=0;
    while(c>bw[i].w){
        ans+=bw[i].v;
        c-=bw[i].w;
        i++;
    }
    ans+=bw[i].p*c;
    printf("%.1lf",ans);
    if(0){
        cout<<endl;
        for(int i=0;i<n;i++){
            printf("--%d %d %.1lf\n",bw[i].w,bw[i].v,bw[i].p);
        }
    }
    return 0;
} 
