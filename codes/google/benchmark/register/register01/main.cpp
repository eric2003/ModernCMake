#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>

void BM_Test1(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(state.iterations());
  }
}

void BM_Test2(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(state.iterations());
  }
}

BENCHMARK(BM_Test1);
BENCHMARK(BM_Test2);

int main(int argc, char** argv)
{
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
    return 0;
}