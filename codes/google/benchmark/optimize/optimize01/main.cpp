#include <benchmark/benchmark.h>

static void BM_test(benchmark::State& state) {
  for (auto _ : state) {
      int x = 0;
      for (int i=0; i < 64; ++i) {
        //benchmark::DoNotOptimize(x += i);
        x += i;
      }
  }
}

static void BM_DoNotOptimize_test(benchmark::State& state) {
  for (auto _ : state) {
      int x = 0;
      for (int i=0; i < 64; ++i) {
        benchmark::DoNotOptimize(x += i);
      }
  }
}

BENCHMARK(BM_test);
BENCHMARK(BM_DoNotOptimize_test);

BENCHMARK_MAIN();