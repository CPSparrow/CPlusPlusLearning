#include<iostream>
#include<string>
using namespace std;

struct Node{
    int id;
    struct Node* next;
};

typedef struct Node
        node;

typedef node*
        nodePtr;

//create a reversing node list based on a list
nodePtr createList(int *num, int n){
    nodePtr head,p,q;
    for(int i=0;i<n;i++){
        p=new node();
        p->id=num[i];
        if(i==0){
            head=p;
            p->next=p;
            q=p;
        }else{
            q->next=p;
            q=p;
            p->next=head;
        }
    }
    return head;
}

//print a reversing node list
void printList(nodePtr head){
    nodePtr p=head;
    do{
        cout<<p->id<<" ";
        p=p->next;
    }while(p!=head);
}

//pop ever m-th node
void popNode(nodePtr head,int m){
    nodePtr p=head->next,q=head;
    int count=1;
    do{
        count++;
        if(count==m){
            cout<<p->id<<" ";
            p=p->next;
            q->next=p;
            //q=p;
            count=1;
        }
        p=p->next;
        q=q->next;
    }while(p!=p->next);
    cout<<p->id;
}

/*
求解约瑟夫（Joseph）问题。
有n个小孩围成一圈，给他们从1开始依次编号，从编号为1的小孩开始报数，数到第m个小孩出列，然后从出列的下一个小孩重新开始报数，数到第m个小孩又出列，…，如此反复直到所有的小孩全部出列为止，求整个出列序列。
如当n=6，m=5时的出列序列是5，4，6，2，3，1。
*/
int main()
{
    //1 2 3 4 5 6
    int n,m;
    cin>>n>>m;
    int t[n];
    for(int i=0;i<n;i++){
        t[i]=i+1;
    }
    nodePtr head = createList(t,n);
    popNode(head, m);
    return 0;
}
