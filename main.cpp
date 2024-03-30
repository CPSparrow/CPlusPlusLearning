#include <iostream>
#include <stack>
using namespace std;

// example for(int i=0; i<v; i++){ visited[i] = 0; for(int j=0; j<v; j++) scanf("%d",&(g->Adj[i][j])); }

int main(void)
{
    stack<char> op;
    string s;
    int left = 0, right = 0;
    bool flag = true;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            left++;
            op.push(s[i]);
        } else if (s[i] == ')') {
            right++;
            if (op.top() == '(') {
                op.pop();
            } else {
                flag = false;
            }
        } else if (s[i] == ']') {
            right++;
            if (op.top() == '[') {
                op.pop();
            } else {
                flag = false;
            }
        } else if (s[i] == '}') {
            right++;
            if (op.top() == '{') {
                op.pop();
            } else {
                flag = false;
            }
        }
    }
    if (op.empty() != true) {
        flag = false;
    }
    cout << left << " " << right << "\n";
    if (flag == true) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
    return 0;
}
