#include <benchmark/benchmark.h>
#include <vector>

static void BM_VectorPushback(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<int> data;
    state.PauseTiming();
    for (int i = 0; i < state.range(0); ++i)
      data.push_back( i );
    state.ResumeTiming();
    for (int j = 0; j < state.range(1); ++j)
      data.push_back( j );
  }
}

BENCHMARK(BM_VectorPushback)
    ->ArgsProduct({{111, 345, 789}, {20, 40, 60, 80}});
// Run the benchmark
BENCHMARK_MAIN();