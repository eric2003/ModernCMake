#include <benchmark/benchmark.h>
#include <set>

std::set<int64_t> ConstructRandomSet(int64_t size) {
  std::set<int64_t> s;
  for (int i = 0; i < size; ++i) s.insert(s.end(), i);
  return s;
}

static void BM_SetInsert_With_Timer_Control(benchmark::State& state) {
  std::set<int64_t> data;
  for (auto _ : state) {
    state.PauseTiming();
    data = ConstructRandomSet(state.range(0));
    state.ResumeTiming();
    for (int j = 0; j < state.range(1); ++j) data.insert(rand());
  }
  state.SetItemsProcessed(state.iterations() * state.range(1));
  state.SetBytesProcessed(state.iterations() * state.range(1) * sizeof(int));
}

// Test many inserts at once to reduce the total iterations needed. Otherwise,
// the slower, non-timed part of each iteration will make the benchmark take
// forever.
BENCHMARK(BM_SetInsert_With_Timer_Control)->Ranges({{1 << 10, 8 << 10}, {128, 512}});

BENCHMARK_MAIN();