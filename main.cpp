#include<iostream>
#include<algorithm>
using namespace std;
  
struct Node{
    int num;
    int count;
    struct Node* next;
};

typedef struct Node
    node;
typedef node*
    nodePtr;

void printList(nodePtr head){
    nodePtr p=head;
    while(p!=NULL){
        cout<<p->num<<" "<<p->count<<"\n";
        p=p->next;
    }
}

nodePtr createList(nodePtr head,int n){
    nodePtr p,q;
    int num,count;
    for(int i=0;i<n;i++){
        cin>>num>>count;
        p=new node();
        p->num=num;
        p->count=count;
        p->next=NULL;
        if(i==0){
            head=p;
            head->next=NULL;
            q=p;
        }else{
            q->next=p;
            q=p;
        }
    }
    return head;
}

nodePtr addListToHead(nodePtr p1,nodePtr p2){
    nodePtr head;
    if(p1->count<p2->count){
        nodePtr t=p1;
        p1=p2;
        p2=t;
    }
    return head;
}

int main(void){
    //
    return 0;
}/**/