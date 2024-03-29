#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// type 1 for num, 2 for op
typedef struct {
    double num;
    char op;
    int type;
} node;

void test(void);
void printAll(queue<node> *p);
void makeBack(queue<node> *p, queue<node> *newQueue);
void input(queue<node> *p);

// test: 1 + 2 * ( 12 - 568 ) - 3
int main(void)
{
    queue<node> p;
    queue<node> newQueue;
    input(&p);
    makeBack(&p, &newQueue);
    printAll(&newQueue);
    return 0;
}

void makeBack(queue<node> *p, queue<node> *newQueue)
{
    node t;
    stack<node> tempStack;
    while ((*p).empty() == false) {
        t = (*p).front();
        (*p).pop();
        if (t.type == 1) {
            (*newQueue).push(t);
        } else {
            if (t.op == '(') {
                tempStack.push(t);
            } else if (t.op == ')') {
                t = tempStack.top();
                while (t.op != '(') {
                    tempStack.pop();
                    (*newQueue).push(t);
                    t = tempStack.top();
                }
                if (tempStack.top().op == '(') {
                    tempStack.pop();
                }
            } else if (t.op == '*' || t.op == '/') {
                if (tempStack.empty() == false &&
                    (tempStack.top().op == '(' || tempStack.top().op == '+' || tempStack.top().op == '-')) {
                    tempStack.push(t);
                } else {
                    (*newQueue).push(t);
                    (*newQueue).push(tempStack.top());
                    tempStack.pop();
                }
            } else {
                if (tempStack.empty() == true) {
                    continue;
                }
                node newT=tempStack.top();
                //pop all stack until '(' then push the op to stack
            }
        }
    }
    while (tempStack.empty() == false) {
        t = tempStack.top();
        (*newQueue).push(t);
        tempStack.pop();
    }
    printAll(newQueue);
}

void input(queue<node> *p)
{
    string s;
    getline(cin, s);
    int i = 0;
    double num = 0;
    // cout<<"yes";
    while (s[i] != '\0') {
        node n = *(new node());
        if (s[i] == ' ') {
            if (num != 0) {
                n.num = num;
                n.type = 1;
                (*p).push(n);
                num = 0;
            }
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')') {
            n.op = s[i];
            n.type = 2;
            cout << "push a op " << n.op << endl;
            (*p).push(n);
        } else {
            num = num * 10 + s[i] - '0';
        }
        i++;
    }
    node n = *(new node());
    if (num != 0) {
        n.num = num;
        n.type = 1;
        (*p).push(n);
    }
}

void printAll(queue<node> *p)
{
    while ((*p).empty() == false) {
        if ((*p).front().type == 1) {
            cout << (*p).front().num << " ";
        } else {
            cout << (*p).front().op << " ";
        }
        (*p).pop();
    }
}
