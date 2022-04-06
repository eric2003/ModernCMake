#include <benchmark/benchmark.h>
#include <vector>

template <class Q> void BM_Sequential(benchmark::State& state) {
  Q q;
  typename Q::value_type v;
  for (auto _ : state) {
    for (int i = state.range(0); --i; )
      q.push_back(v);
  }
  // actually messages, not bytes:
  state.SetBytesProcessed(
      static_cast<int64_t>(state.iterations())*state.range(0));
}
// C++03
BENCHMARK_TEMPLATE(BM_Sequential, std::vector<int>)->Range(1<<0, 1<<10);

// C++11 or newer, you can use the BENCHMARK macro with template parameters:
//BENCHMARK(BM_Sequential<std::vector<int>>)->Range(1<<0, 1<<10);

// Run the benchmark
BENCHMARK_MAIN();