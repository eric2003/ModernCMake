#include <omp.h>
#include <benchmark/benchmark.h>
#include <iostream>
#include <vector>
#include <chrono>

// L1: 32KB
// L2: 256KB
// L3: 12MB

constexpr size_t n = 1<<26;
constexpr size_t steps = 32/2;

std::vector<float> a(n);  // 256MB
std::vector<float> b(n);

int main(int argc, char** argv)
{
#pragma omp parallel for
    for ( size_t i = 0; i < n; ++ i ) {
        a[i] = std::sin(i * 0.1f);
    }
    typedef std::chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();
    for (int step = 0; step < steps; step++) {
#pragma omp parallel for
        for (size_t i = 2; i < n - 2; i++) {
            b[i] = (a[i - 2] + a[i + 2]) * 0.25f + a[i] * 0.5f;
        }
        std::swap(a, b);
    }
    auto t2 = Clock::now();
    std::chrono::nanoseconds dt = t2 - t1;
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count();
    std::chrono::nanoseconds::rep ns1 = std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count();

    std::cout << "time taken: "
         << std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count()
         << " nanoseconds" << std::endl;
    float loss = 0;
#pragma omp parallel for reduction(+:loss)
    for (size_t i = 1; i < n - 1; i++) {
        loss += std::pow(a[i - 1] + a[i + 1] - a[i] * 2, 2);
    }
    loss = std::sqrt(loss);
    std::cout << "loss: " << loss << std::endl;
    return 0;
}
