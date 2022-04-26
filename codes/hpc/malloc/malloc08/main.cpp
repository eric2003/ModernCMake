#include <omp.h>
#include <benchmark/benchmark.h>
#include <iostream>
#include <vector>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
#define TIME_BEGIN(x) auto clock_time_##x = Clock::now();
#define TIME_END(x) { auto curr_time = Clock::now(); \
                      auto dt = curr_time - clock_time_##x; \
    std::cout << #x ": " \
	<< std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count() << " ns " \
	<< std::chrono::duration_cast<std::chrono::microseconds>(dt).count() << " micros " \
	<< std::chrono::duration_cast<std::chrono::milliseconds>(dt).count() << " ms " \
    << std::endl; }

constexpr size_t n = 1ull<<32;  // 16GB

template <class T>
struct pod {
private:
    T m_t;
public:
    pod() {}

    pod(pod &&p) : m_t(std::move(p.m_t)) {}

    pod(pod const &p) : m_t(p.m_t) {}

    pod &operator=(pod &&p) {
        m_t = std::move(p.m_t);
        return *this;
    }

    pod &operator=(pod const &p) {
        m_t = p.m_t;
        return *this;
    }

    pod(T &&t) : m_t(std::move(t)) {}

    pod(T const &t) : m_t(t) {}

    pod &operator=(T &&t) {
        m_t = std::move(t);
        return *this;
    }

    pod &operator=(T const &t) {
        m_t = t;
        return *this;
    }

    operator T const &() const {
        return m_t;
    }

    operator T &() {
        return m_t;
    }

    T const &get() const {
        return m_t;
    }

    T &get() {
        return m_t;
    }

    template <class ...Ts>
    pod &emplace(Ts &&...ts) {
        ::new (&m_t) T(std::forward<Ts>(ts)...);
        return *this;
    }

    void destroy() {
        m_t.~T();
    }
};

int main(int argc, char** argv)
{
    std::vector< pod<int> > arr(n);
    TIME_BEGIN(write_first);
    for ( size_t i = 0; i < 1024; ++ i )
	{
        arr[i] = 1;
    }
    TIME_END(write_first);


    return 0;
}