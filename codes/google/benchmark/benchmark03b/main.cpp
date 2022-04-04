#include <benchmark/benchmark.h>

static void BM_memcpy(benchmark::State& state) {
  int nSize = 1024;
  char* src = new char[nSize]; char* dst = new char[nSize];
  memset(src, 'x', nSize);
  for (auto _ : state)
    memcpy(dst, src, nSize);
  state.SetBytesProcessed(state.iterations() * nSize);
  delete[] src; delete[] dst;
}

BENCHMARK(BM_memcpy);
BENCHMARK(BM_memcpy)->Arg(16);

// Run the benchmark
BENCHMARK_MAIN();
