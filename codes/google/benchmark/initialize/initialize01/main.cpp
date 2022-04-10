#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>

void BM_empty(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(state.iterations());
  }
}

BENCHMARK(BM_empty);

int main(int argc, char* argv[]) {
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
    return 0;
}