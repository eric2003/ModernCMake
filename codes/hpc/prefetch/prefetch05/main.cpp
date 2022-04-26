#include <omp.h>
#include <benchmark/benchmark.h>
#include <iostream>
#include <vector>

// L1: 32KB
// L2: 256KB
// L3: 12MB

constexpr size_t n = 1<<27;  // 512MB

std::vector<float> a(n);

static uint32_t randomize(uint32_t i) {
	i = (i ^ 61) ^ (i >> 16);
	i *= 9;
	i ^= i << 4;
	i *= 0x27d4eb2d;
	i ^= i >> 15;
    return i;
}

void BM_read(benchmark::State &state) {
    for (auto _: state) {
        float ret = 0;
#pragma omp parallel for reduction(+:ret)
        for ( size_t i = 0; i < n; ++ i ) {
            ret += a[i];
        }
        benchmark::DoNotOptimize(ret);
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_read);

void BM_write(benchmark::State &state) {
    for (auto _: state) {
#pragma omp parallel for
        for ( size_t i = 0; i < n; ++ i ) {
            a[i] = 1;
        }
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_write);

void BM_read_and_write(benchmark::State &state) {
    for (auto _: state) {
#pragma omp parallel for
        for ( size_t i = 0; i < n; ++ i ) {
            a[i] = a[i] + 1;
        }
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_read_and_write);

BENCHMARK_MAIN();