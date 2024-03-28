#include <iostream>
using namespace std;

typedef struct Stack stack;
typedef stack *nodePtr;
enum Type { typeNumber = 1, typeOp = 2, typeNot = 3 };

struct Stack {
    double num;
    string op;
    enum Type type;
    nodePtr next;

    Stack() = default;

    nodePtr push(double n, nodePtr head)
    {
        nodePtr s = new stack();
        s->num = n;
        s->type = typeNumber;
        s->next = NULL;
        if (head == NULL) {
            head = s;
        } else {
            s->next = head;
            head = s;
        }
        return head;
    }

    nodePtr push(string op, nodePtr head)
    {
        nodePtr s = new stack();
        s->op = op;
        s->type = typeOp;
        s->next = NULL;
        if (head == NULL) {
            head = s;
        } else {
            s->next = head;
            head = s;
        }
        return head;
    }

    nodePtr top(nodePtr head)
    {
        return head;
    }

    nodePtr pop(nodePtr head)
    {
        if (head != NULL) {
            head = head->next;
        }
        return head;
    }

    void printList(nodePtr head)
    {
        nodePtr p = head;
        while (p != NULL) {
            if (p->type == typeNumber) {
                cout << p->num << " ";
            } else if (p->type == typeOp) {
                cout << p->op << " ";
            } else {
                cout << "invalid content !!!"
                     << " ";
            }
            p = p->next;
        }
        cout << endl;
    }

    nodePtr listReverse(nodePtr head)
    {
        nodePtr oldHead, newHead, t;
        oldHead = head;
        newHead = NULL;
        while (oldHead != NULL) {
            t = oldHead->next;
            oldHead->next = newHead;
            newHead = oldHead;
            oldHead = t;
        }
        head = newHead;
        return head;
    }

    // not finished
    nodePtr makeBackward(nodePtr head)
    {
        nodePtr newStack, tempStack, ptr = head;
        stack p;
        while (ptr != NULL) {
            if (p.top(ptr)->type == typeNumber) {
                p.push(p.top(ptr)->num, newStack);
                ptr = p.pop(ptr);
            } else if (p.top(ptr)->type == typeOp) {
                string op = p.top(ptr)->op;
                if (p.top(ptr)->op == "(") {
                    tempStack = p.push(op, tempStack);
                }
            }
        }
        return head;
    }

    double calcStack(nodePtr head)
    {
        double ans;
        return ans;
    }
};

nodePtr manageInput();

// example: 1 + 2 / 3
int main(void)
{
    stack p;
    nodePtr head;
    head = manageInput();
    p.printList(head);
    head = p.makeBackward(head);
    double ans = p.calcStack(head);
    return 0;
}

nodePtr manageInput()
{
    stack p;
    nodePtr head = NULL;
    string s;
    getline(cin, s);
    int i = 0;
    double tempNum = 0;
    string tempOp = "";
    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            tempNum *= 10;
            tempNum += s[i] - '0';
        } else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
            tempOp += s[i];
        } else {
            if (tempOp != "") {
                head = p.push(tempOp, head);
            } else if (tempNum != 0) {
                head = p.push(tempNum, head);
            }
            tempNum = 0;
            tempOp = "";
        }
        i++;
    }
    if (tempOp != "") {
        head = p.push(tempOp, head);
    } else if (tempNum != 0) {
        head = p.push(tempNum, head);
    }
    tempNum = 0;
    tempOp = "";

    head = p.listReverse(head);

    return head;
}