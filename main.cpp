#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Node
    node;
typedef node*
    nodePtr;
struct Node{
    int num;
    nodePtr next;
    Node(int _num=0,nodePtr _next=NULL):num(_num),next(_next){}
};

//print from head to tail
void printList(nodePtr head){
    nodePtr p=head;
    while(p!=NULL){
        cout<<p->num<<" ";
        p=p->next;
    }
    cout<<flush;
}
 
nodePtr nodeReverse(nodePtr head);

nodePtr createList(int n){
    nodePtr head=NULL,p;
    for(int i=0;i<n;i++){
        nodePtr s=new node(i+1,NULL);
        if(i==0){
            head=s;
            p=s;
        }else{
            p->next=s;
            p=s;
        }
    }
    return head;
}

int main(void){
    int n=5;
    nodePtr head=createList(n);
    head=nodeReverse(head);
    head=nodeReverse(head);
    printList(head);
    return 0;
}/**/

nodePtr nodeReverse(nodePtr head){
    nodePtr oldHead,newHead,temp;
    oldHead=head;
    newHead=NULL;
    while(oldHead!=NULL){
         temp=oldHead->next;
         oldHead->next=newHead;
         newHead=oldHead;
         oldHead=temp;
    }
    return newHead;
}