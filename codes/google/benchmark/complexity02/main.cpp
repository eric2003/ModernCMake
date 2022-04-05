#include <benchmark/benchmark.h>
#include <string>

static void BM_StringCompare(benchmark::State& state) {
  std::string s1(state.range(0), '-');
  std::string s2(state.range(0), '-');
  for (auto _ : state) {
    benchmark::DoNotOptimize(s1.compare(s2));
  }
  state.SetComplexityN(state.range(0));
}

//BENCHMARK(BM_StringCompare)
//    ->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);

//The following code will specify asymptotic complexity with a lambda function, that might be used to customize high-order term calculation.

BENCHMARK(BM_StringCompare)->RangeMultiplier(2)
    ->Range(1<<10, 1<<18)->Complexity([](benchmark::IterationCount n)->double{return n; });

// Run the benchmark
BENCHMARK_MAIN();