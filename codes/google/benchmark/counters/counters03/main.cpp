#include <benchmark/benchmark.h>

namespace {
int num_calls = 0;
}
void BM_Counters_WithBytesAndItemsPSec(benchmark::State& state) {
  for (auto _ : state) {
    // This test requires a non-zero CPU time to avoid divide-by-zero
    benchmark::DoNotOptimize(state.iterations());
  }
  state.counters["foo"] = 1;
  state.counters["bar"] = ++num_calls;
  state.SetBytesProcessed(364);
  state.SetItemsProcessed(150);
}

BENCHMARK(BM_Counters_WithBytesAndItemsPSec);

BENCHMARK_MAIN();