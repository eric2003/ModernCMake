#include <benchmark/benchmark.h>
#include <vector>

static void BM_MultiThreaded(benchmark::State& state) {
  if (state.thread_index() == 0) {
    // Setup code here.
  }
  for (auto _ : state) {
    // Run the test as normal.
    std::vector<int> v;
    int nSize = 1024;
    for ( int i = 0; i < nSize; ++ i )
    {
        v.push_back(i);
    }
  }
  if (state.thread_index() == 0) {
    // Teardown code here.
  }
}

BENCHMARK(BM_MultiThreaded)->ThreadRange(1, 8);

BENCHMARK_MAIN();