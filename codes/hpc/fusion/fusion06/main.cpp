#include <omp.h>
#include <benchmark/benchmark.h>
#include <iostream>
#include <vector>
#include <chrono>

// L1: 32KB
// L2: 256KB
// L3: 12MB

constexpr size_t n = 1<<26;
constexpr size_t steps = 32/16;

std::vector<float> a(n);  // 256MB
std::vector<float> b(n);

int main(int argc, char** argv)
{
    std::cout << "haha\n";
#pragma omp parallel for
    for (intptr_t i = 0; i < n; i++) {
        a[i] = std::sin(i * 0.1f);
    }
    typedef std::chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();
    for (int step = 0; step < steps; step++) {
    std::cout << "step = " << step << "\n";		
        constexpr intptr_t BS = 128;
        constexpr intptr_t HS = 16;
#pragma omp parallel for
        for (intptr_t ibase = HS; ibase < n - HS; ibase += BS) {
			std::cout << "ibase = " << ibase << " HS = "<< HS << " n - HS=" << n - HS << "\n";	
            float ta[BS + HS * 2], tb[BS + HS * 2];
            for (intptr_t i = -HS; i < BS + HS; i++) {
                ta[HS + i] = a[ibase + i];
            }
#pragma GCC unroll 8
            for (intptr_t s = 2; s <= HS; s += 4) {
#pragma omp simd
                for (intptr_t i = -HS + 2; i < BS + HS - 2; i++) {
                    tb[HS + i] = (ta[HS + i - 2] + ta[HS + i] + ta[HS + i] + ta[HS + i + 2]) * 0.25f;
                }
#pragma omp simd
                for (intptr_t i = -HS + 4; i < BS + HS - 4; i++) {
                    ta[HS + i] = (tb[HS + i - 2] + tb[HS + i] + tb[HS + i] + tb[HS + i + 2]) * 0.25f;
                }
            }
            for (intptr_t i = 0; i < BS; i += 4) {
                _mm_stream_ps(&b[ibase + i], _mm_loadu_ps(&tb[HS + i]));
            }
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
    for (intptr_t i = 1; i < n - 1; i++) {
        loss += std::pow(a[i - 1] + a[i + 1] - a[i] * 2, 2);
    }
    loss = std::sqrt(loss);
    std::cout << "loss: " << loss << std::endl;
    return 0;
}
