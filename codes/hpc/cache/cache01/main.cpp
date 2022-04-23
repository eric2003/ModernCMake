#include <omp.h>
#include <benchmark/benchmark.h>
#include <iostream>

// L1: 32KB
// L2: 256KB
// L3: 12MB

constexpr size_t n = 1<<28;

std::vector<float> a(n);

void BM_fill1GB(benchmark::State &state) {
    for (auto _: state) {
        for ( size_t i = 0; i < (1<<28); ++ i ) {
            a[i] = 1;
        }
    }
}
BENCHMARK(BM_fill1GB);

void BM_fill128MB(benchmark::State &state) {
    for (auto _: state) {
        for ( size_t i = 0; i < (1<<25); ++ i ) {
            a[i] = 1;
        }
    }
}
BENCHMARK(BM_fill128MB);

void BM_fill16MB(benchmark::State &state) {
    for (auto _: state) {
        for ( size_t i = 0; i < (1<<22); ++ i ) {
            a[i] = 1;
        }
    }
}
BENCHMARK(BM_fill16MB);

void BM_fill1MB(benchmark::State &state) {
    for (auto _: state) {
        for ( size_t i = 0; i < (1<<18); ++ i ) {
            a[i] = 1;
        }
    }
}
BENCHMARK(BM_fill1MB);

void BM_fill128KB(benchmark::State &state) {
    for (auto _: state) {
        for ( size_t i = 0; i < (1<<15); ++ i ) {
            a[i] = 1;
        }
    }
}
BENCHMARK(BM_fill128KB);

void BM_fill16KB(benchmark::State &state) {
    for (auto _: state) {
        for ( size_t i = 0; i < (1<<12); ++ i ) {
            a[i] = 1;
        }
    }
}
BENCHMARK(BM_fill16KB);

BENCHMARK_MAIN();