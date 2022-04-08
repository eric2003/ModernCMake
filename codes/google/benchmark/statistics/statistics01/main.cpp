#include <benchmark/benchmark.h>
#include <vector>

static void BM_vector_push_back(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<int> v;
    int nSize = 1024;
    for ( int i = 0; i < nSize; ++ i )
    {
        v.push_back(i);
    }
  }
}

BENCHMARK(BM_vector_push_back)->Iterations(100000)->Repetitions(10);


BENCHMARK_MAIN();