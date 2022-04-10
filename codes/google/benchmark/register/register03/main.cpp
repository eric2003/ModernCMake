#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>


auto BM_test = [](benchmark::State& state, auto Inputs)
{
  for (auto _ : state) {
    benchmark::DoNotOptimize(state.iterations());
  }
    //std::cout << "Inputs = " << Inputs << std::endl;
};

int main(int argc, char** argv)
{
    benchmark::RegisterBenchmark("BM_test", BM_test, 10);
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
    return 0;
}