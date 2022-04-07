#include <benchmark/benchmark.h>
namespace {
int numFoos = 0;
}
void BM_Counters(benchmark::State& state) {
  for (auto _ : state) {
    // This test requires a non-zero CPU time to avoid divide-by-zero
    benchmark::DoNotOptimize(state.iterations());
  }
  
  // sets a simple counter
  state.counters["Foo"] = ++ numFoos;
  // Set the counter as a rate. It will be presented divided
  // by the duration of the benchmark.
  // Meaning: per one second, how many 'foo's are processed?
  state.counters["FooRate"] = benchmark::Counter(numFoos, benchmark::Counter::kIsRate);
  
  // Set the counter as a rate. It will be presented divided
  // by the duration of the benchmark, and the result inverted.
  // Meaning: how many seconds it takes to process one 'foo'?
  state.counters["FooInvRate"] = benchmark::Counter(numFoos, benchmark::Counter::kIsRate | benchmark::Counter::kInvert);  
  
  // Set the counter as a thread-average quantity. It will
  // be presented divided by the number of threads.
  state.counters["FooAvg"] = benchmark::Counter(numFoos, benchmark::Counter::kAvgThreads);

  // There's also a combined flag:
  state.counters["FooAvgRate"] = benchmark::Counter(numFoos,benchmark::Counter::kAvgThreadsRate);
  
  // This says that we process with the rate of numFoos bytes every iteration:
  state.counters["BytesProcessed"] = benchmark::Counter(numFoos, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1024);  
}

BENCHMARK(BM_Counters);

BENCHMARK_MAIN();