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
    ->Args({1<<10, 128})
    ->Args({2<<10, 128})
    ->Args({4<<10, 128})
    ->Args({8<<10, 128})
    ->Args({1<<10, 512})
    ->Args({2<<10, 512})
    ->Args({4<<10, 512})
    ->Args({8<<10, 512});

// Run the benchmark
BENCHMARK_MAIN();