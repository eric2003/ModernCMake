#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>

// Testing interaction with Fixture::Setup/Teardown
namespace fixture_interaction {
int setup = 0;
int fixture_setup = 0;
}  // namespace fixture_interaction

class MyFixture : public ::benchmark::Fixture {
public:
    void SetUp(const ::benchmark::State&) {
        fixture_interaction::fixture_setup++;
    }

    ~MyFixture() {}
};

BENCHMARK_F(MyFixture, BM_WithFixture)(benchmark::State& state) {
    for (auto _ : state) {
      std::vector<int> data;
      int nSize = 1024;
      for (int i = 0; i < nSize; ++i)
        data.push_back( i );
    }
}

BENCHMARK_REGISTER_F(MyFixture, BM_WithFixture)
    ->Arg(1)
    ->Arg(3)
    ->Arg(5)
    ->Iterations(100000);

// Run the benchmark
BENCHMARK_MAIN();