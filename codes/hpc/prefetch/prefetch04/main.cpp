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

void BM_ordered(benchmark::State &state) {
    for ( auto _: state ) {
#pragma omp parallel for
        for ( size_t i = 0; i < n; ++ i ) {
            benchmark::DoNotOptimize(a[i]);
        }
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_ordered);

void BM_random_64B(benchmark::State &state) {
    for ( auto _: state ) {
#pragma omp parallel for
        for ( size_t i = 0; i < n / 16; ++ i ) {
            size_t r = randomize(i) % (n / 16);
            for ( size_t j = 0; j < 16; ++ j ) {
                benchmark::DoNotOptimize(a[r * 16 + j]);
            }
        }
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_random_64B);

void BM_random_64B_prefetch(benchmark::State &state) {
    for ( auto _: state ) {
#pragma omp parallel for
        for ( size_t i = 0; i < n / 16; ++ i ) {
            size_t next_r = randomize(i + 64) % (n / 16);
            _mm_prefetch((const char *)&a[next_r * 16], _MM_HINT_T0);
            size_t r = randomize(i) % (n / 16);
            for ( size_t j = 0; j < 16; ++ j ) {
                benchmark::DoNotOptimize(a[r * 16 + j]);
            }
        }
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_random_64B_prefetch);

BENCHMARK_MAIN();