#include <benchmark/benchmark.h>

static void BM_DenseRange(benchmark::State& state) {
  for(auto _ : state) {
    std::vector<int> v(state.range(0), state.range(0));
    benchmark::DoNotOptimize(v.data());
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_DenseRange)->DenseRange(0, 1024, 128);

// Run the benchmark
BENCHMARK_MAIN();