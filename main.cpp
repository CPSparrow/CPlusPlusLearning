#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n,t,max=0,thisMax=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        thisMax+=t;
        if(thisMax>max){
            max=thisMax;
        }
        if(thisMax<0){
            thisMax=0;
        }
    }
    cout<<max;
    return 0;
}
