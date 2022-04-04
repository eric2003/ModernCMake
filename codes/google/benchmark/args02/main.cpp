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
    for (int k = 0; k < state.range(2); ++k)
      data.push_back( k );  
  }
}

BENCHMARK(BM_VectorPushback)
    ->Args({128, 16, 8})
    ->Args({256, 8, 16});

// Run the benchmark
BENCHMARK_MAIN();