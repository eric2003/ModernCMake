#include <benchmark/benchmark.h>
#include <vector>

static void BM_vector_push_back(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<int> v;
    v.reserve(1);
    v.push_back(42);
  }
}

static void BM_vector_push_back_DoNotOptimize(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<int> v;
    v.reserve(1);
    benchmark::DoNotOptimize(v.data()); // Allow v.data() to be clobbered.
    v.push_back(42);
    benchmark::ClobberMemory(); // Force 42 to be written to memory.
  }
}

BENCHMARK(BM_vector_push_back);
BENCHMARK(BM_vector_push_back_DoNotOptimize);
BENCHMARK(BM_vector_push_back_DoNotOptimize)->Iterations(1);
BENCHMARK(BM_vector_push_back_DoNotOptimize)->Iterations(1000000)->Repetitions(10);


BENCHMARK_MAIN();