#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>

void BM_Stats(benchmark::State& state) {
  for (auto _ : state) {
    int nSize = 1024;
    for (int x = 0; x < nSize; ++x) {
      benchmark::DoNotOptimize(x);
    }
  }
}

void BM_Stats_CFD(benchmark::State& state) {
  for (auto _ : state) {
    int nSize = 1024;
    for (int x = 0; x < nSize; ++x) {
      benchmark::DoNotOptimize(x);
    }
  }
}
  
BENCHMARK(BM_Stats)
  ->Repetitions(2)
  ->Iterations(10000)
  ->UseManualTime();
BENCHMARK(BM_Stats_CFD)
  ->Repetitions(2)
  ->Iterations(10000)
  ->UseManualTime()
  ->ComputeStatistics("cfd_max", [](const std::vector<double>& v) -> double {
    std::cout << "v.size() = " << v.size() << std::endl;
    return *(std::max_element(std::begin(v), std::end(v)));
  });  

BENCHMARK_MAIN();