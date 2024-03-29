#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<double> d_st;
stack<char> op_st;

int level(char a)
{
    if (a == '+' || a == '-') {
        return 1;
    }
    if (a == '*' || a == '/') {
        return 2;
    }
}

void cal(void)
{
    double a, b;
    char c = op_st.top();
    op_st.pop();
    a = d_st.top();
    d_st.pop();
    b = d_st.top();
    d_st.pop();
    switch (c) {
        case '+':
            d_st.push(b + a);
            break;
        case '-':
            d_st.push(b - a);
            break;
        case '*':
            d_st.push(b * a);
            break;
        case '/':
            d_st.push(b / a);
            break;
        default:
            break;
    }
}

int main(void)
{
    string str;
    double x;
    getline(cin, str);
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            x = str[i] - '0';
            while (str[i+1]>='0'&&str[i+1]<='9') {
                x = x * 10 + str[i + 1] - '0';
                i++;
            }
            d_st.push(x);
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            if (op_st.empty() || level(str[i]) > level(op_st.top())) {
                op_st.push(str[i]);
            } else if (!op_st.empty() && level(str[i]) <= level(op_st.top())) {
                //
            }
        }
    }
    return 0;
}