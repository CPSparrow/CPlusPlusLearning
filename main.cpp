#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int a,b,t=0,sum=0;
    cin>>a>>b; 
    for(int i=a;i<=b;i++){
        sum+=i;
        t++;
        printf("%5d",i);
        if(t%5==0){
        	t=0;
            cout<<"\n";
        }
    }
    if(t!=0){
    	cout<<"\n";
	}
    cout<<"Sum = "<<sum<<flush;
    return 0;
}
