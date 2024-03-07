#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    struct Node *Next; 
};
typedef struct Node
        node;
typedef node*
        NodePtr;

//chen
NodePtr creatList(int *num,int n){
    NodePtr head,p,q;
    head = new Node();
    q=head;
    for(int i=0;i<n;i++){
        p=new node();
        p->data=num[i];
        q->Next=p;
        q=p;
    }
    q->Next=NULL;
    return head;
}

//chen
NodePtr insertList(NodePtr head,int x){
    NodePtr q,p,s;
    s=new node();
    s->data=x,s->Next=NULL;
    q=head,p->Next=NULL;
    while (p!=NULL) {
        if(p->data>=x){
            break;
        }
        q=p;
        p=p->Next;
    }
    q->Next=s;
    s->Next=p;
    return head;
}

//chen
void printList(NodePtr head){
    //node_list with empty node
    NodePtr p=head->Next;
    while (p!=NULL) {
        cout<<p->data<<"\n";
        p=p->Next;
    }
    return;
}

int main(void) {
    int n=5;
    int num[n]={1,2,3,4,5};
    NodePtr p=creatList(num, n);
    printList(p);
    return 0;
}
