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
    void SetUp(const ::benchmark::State&) BENCHMARK_OVERRIDE {
        fixture_interaction::fixture_setup++;
        std::cout << "MyFixture::SetUp" << std::endl;
        std::cout << "fixture_interaction::fixture_setup = " << fixture_interaction::fixture_setup << std::endl;
    }

    ~MyFixture() {}
};

BENCHMARK_F(MyFixture, BM_WithFixture)(benchmark::State& st) {
  for (auto _ : st) {
  }
}

BENCHMARK_REGISTER_F(MyFixture, BM_WithFixture)
    ->Arg(1)
    ->Arg(3)
    ->Arg(5)
    ->Arg(7)
    ->Repetitions(1)
    ->Iterations(100);

// Run the benchmark
BENCHMARK_MAIN();