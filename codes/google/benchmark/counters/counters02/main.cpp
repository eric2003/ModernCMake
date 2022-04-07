#include <benchmark/benchmark.h>

static void UserCountersExample1(benchmark::State& state) {
  double numFoos = 0, numBars = 0, numBazs = 0;
  for (auto _ : state) {
    // ... count Foo,Bar,Baz events
    numFoos += 1;
    numBars += 2;
    numBazs += 3;
  }
  state.counters["Foo"] = numFoos;
  state.counters["Bar"] = numBars;
  state.counters["Baz"] = numBazs;
}

BENCHMARK(UserCountersExample1);

BENCHMARK_MAIN();