#include <iostream>
using namespace std;

void listMove(int *num, int size);

int main(void)
{
    int n = 5, m;
    std::cin >> n >> m;
    int num[n];
    for (int i = 0; i < n; i++)
        std::cin >> num[i];
    for (int i = 0; i < m; i++) {
        listMove(num, n);
    }
    for (int i = 0; i < n - 1; i++) {
        std::cout << num[i] << " ";
    }
    std::cout << num[n - 1];
    return 0;
} 

void listMove(int *num, int size)
{
    int t = num[0];
    for (int i = 0; i < size; i++) {
        num[i] = num[i + 1];
    }
    num[size - 1] = t;
}
