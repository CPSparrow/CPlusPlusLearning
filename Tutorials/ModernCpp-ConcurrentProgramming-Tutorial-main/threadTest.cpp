#include <iostream>
#include <thread>

void fCalc(int n, int tag)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            sum += j;
        }
    }
    std::cout << "have sum = " << sum << " with tag = " << tag << std::endl;
    std::cout << "id = " << std::this_thread::get_id() << "\n";
    return;
}

int main(void)
{
    std::cout << "id = " << std::this_thread::get_id() << "\n";
    std::thread t1{fCalc, 5, 1};
    t1.join();
    std::thread t2{fCalc, 4, 2};
    t2.join();
    unsigned long long i = -1;
    std::cout<<i;
    return 0;
}
