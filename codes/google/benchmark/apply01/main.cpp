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
static void CustomArguments(benchmark::internal::Benchmark* b) {
  for (int i = 0; i <= 10; ++i)
    for (int j = 32; j <= 1024*1024; j *= 8)
      b->Args({i, j});
}

BENCHMARK(BM_VectorPushback)
    ->Apply(CustomArguments);

// Run the benchmark
BENCHMARK_MAIN();