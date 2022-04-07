#include <benchmark/benchmark.h>

void BM_Counters_Simple(benchmark::State& state) {
  for (auto _ : state) {
  }
  state.counters["foo"] = 1;
  state.counters["bar"] = 2 * static_cast<double>(state.iterations());
}

BENCHMARK(BM_Counters_Simple);

BENCHMARK_MAIN();