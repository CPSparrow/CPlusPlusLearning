#include <iostream>
#include <algorithm>
using namespace std;

int cmp(string a,string b){
    return a>b;
}

int main(void){
    string s[20];
    int i=0;
    do{
        cin>>s[i];
        i++;
    }while(s[i-1]!="#");
    sort(s,s+i-1,cmp);
    while(i--){
        cout<<s[i-1]<<"\n";
    }
    return 0;
} 
