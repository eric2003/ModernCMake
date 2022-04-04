#include <benchmark/benchmark.h>
#include <set>
#include <random>
 
std::random_device rd;
std::mt19937 gen(rd());
 
int random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

void ConstructRandomSet( int high, std::set<int> & myset )
{
    int v = random(0, high);
    myset.insert(v);
}

// You might have a microbenchmark that depends on two inputs.  For
// example, the following code defines a family of microbenchmarks for
// measuring the speed of set insertion.
static void BM_SetInsert(benchmark::State& state) {
  std::set<int> data;
  for (auto _ : state) {
    state.PauseTiming();
    ConstructRandomSet(state.range(0), data );
    state.ResumeTiming();
    for (int j = 0; j < state.range(1); ++j)
      data.insert(random(0, state.range(1)));
  }
}

// For more complex patterns of inputs, passing a custom function
// to Apply allows programmatic specification of an
// arbitrary set of arguments to run the microbenchmark on.
// The following example enumerates a dense range on
// one parameter, and a sparse range on the second.
static void CustomArguments(benchmark::internal::Benchmark* b) {
  for (int i = 0; i <= 10; ++i)
    for (int j = 32; j <= 1024*1024; j *= 8)
      b->Args({i, j});
}
BENCHMARK(BM_SetInsert)->Apply(CustomArguments);

// Run the benchmark
BENCHMARK_MAIN();