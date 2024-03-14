#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Node
    node;
typedef node*
    nodePtr;

//双向链表的定义
struct Node{
    int num;
    nodePtr next;
    nodePtr previous;
};

//在双向链表中把node t 插入到node p 之后
void insertNode(nodePtr p,nodePtr t){
    t->previous=p;
    t->next=p->next;
    p->next->previous=t;
    p->next=t;
}

nodePtr createList(nodePtr head,int n){
    nodePtr p;
    for(int i=0;i<n;i++){
        nodePtr s=new node();
        s->num=i+1;
        if(i==0){
            head=s;
            s->next=s->previous=s;
            p=s;
        }else{
            s->next=head;
            s->previous=p;
            p->next=s;
            head->previous=s;
            p=s;
        }
    }
    return head;
}

//example: 1 2 3 4 5 6, m=2
//pop: 2 4 6 3 1 5
nodePtr popForward(nodePtr p,int step){
    int count=1;
    while(p!=p->next){
        count++;
        p=p->next;
        if(count==step){
            cout<<p->num<<"*";
            p->previous->next=p->next;
            p->next->previous=p->previous;
            p=p->next;
            return p;
        }
    }
    cout<<p->num;
    return NULL;
}

//example: 1 2 3 4 5 6, m=2
//pop: 6 4 2 5 1 3
nodePtr popBackward(nodePtr p,int step){
    int count=1;
    while(p!=p->previous){
        count++;
        p=p->previous;
        if(count==step){
            cout<<p->num<<"*";
            p->previous->next=p->next;
            p->next->previous=p->previous;
            p=p->previous;
			return p;
        }
        
    }
    cout<<p->num;
    return NULL;
}

//for debug
void printList(nodePtr head){
    nodePtr p=head;
    do{
        cout<<p->num<<"*";
        p=p->next;
    }while(p!=head);
}

int main(void){
    int n=6,m=3,k=5;
    cin>>n>>m>>k;
    nodePtr head=NULL;
    head=createList(head, n);
    nodePtr p=head;
    int tag=1;
    while(p!=NULL){
        if(tag==1){
            p=popBackward(p,m);
        }else{
            p=popForward(p,k);
        }
        tag*=-1;
    }
    return 0;
}/**/
