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
    ->ArgsProduct({
      benchmark::CreateDenseRange(1, 3, /*step=*/1),
      benchmark::CreateDenseRange(1, 5, /*step=*/2)
    });
// Run the benchmark
BENCHMARK_MAIN();