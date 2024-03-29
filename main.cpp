#include <iostream>
#include <stack>
using namespace std;

int conversion(int num, int k)
{
    int ans=0;
    stack<int> p;
    while (num > 0) {
        p.push(num % k);
        num /= k;
    }
    while (p.empty() == false) {
        ans = ans * 10 + p.top();
        p.pop();
    }
    return ans;
}

int main(void)
{
    cout << conversion(8, 2);
    return 0;
}
