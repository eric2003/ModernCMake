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

int main(int argc, char** argv)
{
    benchmark::RegisterBenchmark("BM_Test111", &BM_Test1);
    benchmark::RegisterBenchmark("BM_Test222", &BM_Test2);
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
    return 0;
}