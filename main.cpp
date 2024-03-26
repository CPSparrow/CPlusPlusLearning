#include <iostream>
using namespace std;

typedef long long ll;
ll n, k, cityPoint[100005] = {0}, s, x, ans = 0;
int isCenter[100005] = {0};

void ridRepeat()
{
    if (x == n && !isCenter[1]) {
        ans -= cityPoint[x] * cityPoint[1];
    }
    if (x == 1 && !isCenter[n]) {
        ans -= cityPoint[x] * cityPoint[n];
    }
    if (!isCenter[x + 1]) {
        ans -= cityPoint[x] * cityPoint[x + 1];
    }
    if (!isCenter[x - 1]) {
        ans -= cityPoint[x] * cityPoint[x - 1];
    }
}

int main(void)
{
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        std::cin >> cityPoint[i];
        s = s + cityPoint[i];
        ans += cityPoint[i - 1] * cityPoint[i];
    }
    ans += cityPoint[1] * cityPoint[n];
    while (k--) {
        std::cin >> x;
        isCenter[x] = 1;
        s -= cityPoint[x];
        ans += cityPoint[x] * s;
        ridRepeat();
    }
    std::cout << ans << std::flush;
    return 0;
}