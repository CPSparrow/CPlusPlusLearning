#include <iostream>
#include <thread>

//这段代码通过提供一个类，在析构函数中使用 join() 确保线程执行完成，线程对象正常析构。

//教参上的话：
//函数 f 执行完毕，局部对象就要逆序销毁了。因此，thread_guard 对象 g 是第一个被销毁的，
//调用析构函数。即使函数 f2() 抛出了一个异常，这个销毁依然会发生（前提是你捕获了这个异常）。
//这确保了线程对象 t 所关联的线程正常的执行完毕以及线程对象的正常析构。

//笔记：这个f2指的是某种可能引发异常的程序块。而 threadGuard 意图在运行中保证线程资源的安全释放

struct func {
    int& m_i;
    func(int& i) :m_i{ i } {}
    void operator()(int n)const {
        for (int i = 0; i <= n; ++i) {
            m_i += i;           // 可能悬空引用
        }
    }
};

class thread_guard{
    std::thread& m_t;
public:
    explicit thread_guard(std::thread& t) :m_t{ t } {}
    ~thread_guard(){
        std::puts("析构");     // 打印 不用在乎
        if (m_t.joinable()) { // 没有关联活跃线程
            m_t.join();
        }
    }
    thread_guard(const thread_guard&) = delete;
    thread_guard& operator=(const thread_guard&) = delete;
};

void f(){
    int n = 0;
    std::thread t{ func{n},10 };
    thread_guard g(t);
    f2(); // 可能抛出异常
}

int main(void)
{
    //
    return 0;
}
