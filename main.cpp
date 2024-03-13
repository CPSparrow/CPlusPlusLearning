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
    NodePtr;
  
int _count=0;
  
//print from head to tail
void printList(NodePtr head){
    NodePtr p=head;
    while(p!=NULL){
        cout<<p->num<<" ";
        p=p->next;
    }
    cout<<flush;
}
  
//add node to head
NodePtr addNode(NodePtr head,int n){
    _count++;
    NodePtr p=new node();
    p->num=n;
    p->next=head;
    p->count=_count;
    return p;
}
  
//delete the i-th added node
NodePtr deleteNode(NodePtr head,int n){
    if(n==0||head->count==n){
        head=head->next;
        return head;
    }
    NodePtr p=head->next,q=head;
    while(p->count!=n){
        p=p->next;
        q=q->next;
    }
    q->next=p->next;
    return head;
}
  
//insert a node after the i-th added node
NodePtr insertNode(NodePtr head,int n,int num){
    NodePtr p=head;
    while(p->count!=n){
        p=p->next;
    }
    NodePtr s=new node();
    _count++;
    s->num=num;
    s->count=_count;
    s->next=p->next;
    p->next=s;
    return head;
}
  
/*
H 9
I 1 1
D 1
D 0
H 6
*/

NodePtr f(NodePtr head){
    char s;
    int n,m;
    cin>>s;
    switch(s){
        case 'H':
            cin>>n;
            head=addNode(head,n);
            break;
        case 'I':
            cin>>n>>m;
            head=insertNode(head,n,m);
            break;
        case 'D':
            cin>>n;
            head=deleteNode(head,n);
            break;
        default:
            break;
    }
    return head;
}
    
/*int main(void){
    NodePtr p = NULL;
    p=addNode(p,9);
    p=addNode(p,8);
    p=addNode(p,7);
    p=deleteNode(p,0);
    p=addNode(p,6);
    printList(p);
    //cout<<"\n"<<_count<<flush;
    return 0;
}*/

int main(void){
    int n;
    NodePtr p = NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        p = f(p);
    }
    printList(p);
    return 0;
}/**/