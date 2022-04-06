#include <benchmark/benchmark.h>
#include <vector>

// Testing interaction with Fixture::Setup/Teardown
namespace fixture_interaction {
int setup = 0;
int fixture_setup = 0;
}  // namespace fixture_interaction

#define FIXTURE_BECHMARK_NAME MyFixture

class FIXTURE_BECHMARK_NAME : public ::benchmark::Fixture {
 public:
  void SetUp(const ::benchmark::State&) BENCHMARK_OVERRIDE {
    fixture_interaction::fixture_setup++;
  }

  ~FIXTURE_BECHMARK_NAME() {}
};

BENCHMARK_F(FIXTURE_BECHMARK_NAME, BM_WithFixture)(benchmark::State& st) {
  for (auto _ : st) {
  }
}

static void DoSetupWithFixture(const benchmark::State&) {
  fixture_interaction::setup++;
}

BENCHMARK_REGISTER_F(FIXTURE_BECHMARK_NAME, BM_WithFixture)
    ->Arg(1)
    ->Arg(3)
    ->Arg(5)
    ->Arg(7)
    ->Setup(DoSetupWithFixture)
    ->Repetitions(1)
    ->Iterations(100);

// Run the benchmark
BENCHMARK_MAIN();