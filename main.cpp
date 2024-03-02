#include <iostream>
using namespace std;

double _abs(double n){
    if(n<0){
        n*=-1.0;
    }
    return n;
}
 
int main(void){
    int a=609222657,b=389387265,l=15,min_x=1,min_y=1;
    cin>>a>>b>>l;
    double r=(double)b/a;
    for(int i=1;i<=l;i++){
        for(int j=i*r-2;j<=i*r+2;j++){
            if(_abs(r-(double)j/i)<_abs(r-(double)min_x/min_y)&&(double)j/i<=r){
                min_x=j;
                min_y=i;
            }
        }
    }
    cout<<min_y<<" "<<min_x;
    if(0)cout<<"\n"<<_abs((double)9/14-r)<<"  "<<_abs((double)7/11-r)<<endl;
    return 0;
} 
