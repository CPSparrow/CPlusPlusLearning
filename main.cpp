#include <iostream>
using namespace std;

int main(void){
    string s="1001";
    int dec=0;
    for(int i=0;i<s.length();i++){
        dec=2*dec+(s[i]-'0');
    }
    cout<<dec<<endl;
    return 0;
} 
