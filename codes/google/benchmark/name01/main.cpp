#include <benchmark/benchmark.h>
#include <string>

static void BM_memcpy(benchmark::State& state) {
  char* src = new char[state.range(0)];
  char* dst = new char[state.range(0)];
  memset(src, 'x', state.range(0));
  for (auto _ : state)
    memcpy(dst, src, state.range(0));
  state.SetBytesProcessed(int64_t(state.iterations()) *
                          int64_t(state.range(0)));
  delete[] src;
  delete[] dst;
}

BENCHMARK(BM_memcpy)->Name("cfd_memcpy")->RangeMultiplier(2)->Range(8, 8<<10);

// Run the benchmark
BENCHMARK_MAIN();