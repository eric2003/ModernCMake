#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>

// Testing interaction with Fixture::Setup/Teardown
namespace fixture_interaction {
int setup = 0;
int fixture_setup = 0;
}  // namespace fixture_interaction

class MyFixture : public benchmark::Fixture {
public:
  void SetUp(const ::benchmark::State& state) {
      fixture_interaction::fixture_setup++;
      std::cout << "MyFixture::SetUp" << std::endl;
      std::cout << "fixture_interaction::fixture_setup = " << fixture_interaction::fixture_setup << std::endl;
  }

  void TearDown(const ::benchmark::State& state) {
      std::cout << "MyFixture::TearDown" << std::endl;
  }
};


BENCHMARK_F(MyFixture, FooTest)(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<int> data;
    std::cout << "state.range(0)=" << state.range(0) << std::endl;
    for (int i = 0; i < state.range(0); ++i)
      data.push_back( i );
  }  
}

//BENCHMARK_REGISTER_F(MyFixture, FooTest)
//    ->Arg(8)
//    ->Arg(64);
BENCHMARK_REGISTER_F(MyFixture, FooTest)
    ->Arg(1)
    ->Arg(3)
    ->Arg(5)
    ->Arg(7)
    //->Setup(DoSetupWithFixture)
    ->Repetitions(1)
    ->Iterations(100);

// Run the benchmark
BENCHMARK_MAIN();