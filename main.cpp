#include <iostream>
using namespace std;

struct Student{
    char name[25];
    int score[3];
};
typedef struct Student
        student;

void f(void){
    int n;
    cin>>n;
    student s[n];
    int max[3]={0,0,0};
    for(int i=0;i<n;i++){
        cin>>s[i].name>>s[i].score[0]>>s[i].score[1]>>s[i].score[2];
        for(int j=0;j<3;j++){
            if(max[j]<s[i].score[j]){
                max[j]=s[i].score[j];
            }
        }
    }
    for(int i=0;i<n;i++){
        if(s[i].score[0]==max[0]&&s[i].score[1]==max[1]&&s[i].score[1]==max[1]){
            cout<<s[i].name<<endl;
            return;
        }
    }
    cout<<"NO NO.1"<<endl;
    return ;
}

int main() {
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
        f();
    }
    return 0;
}
