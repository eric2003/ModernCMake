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
BENCHMARK(BM_SetInsert)
   ->Args({1<<10, 128})
   ->Args({2<<10, 128})
   ->Args({4<<10, 128})
   ->Args({8<<10, 128})
   ->Args({1<<10, 512})
   ->Args({2<<10, 512})
   ->Args({4<<10, 512})
   ->Args({8<<10, 512});

// Run the benchmark
BENCHMARK_MAIN();