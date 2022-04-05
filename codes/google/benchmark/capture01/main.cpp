#include <benchmark/benchmark.h>
#include <iostream>
static int count = 0;
template <class ...Args>
void BM_takes_args(benchmark::State& state, Args&&... args) {
  auto args_tuple = std::make_tuple(std::move(args)...);
  for (auto _ : state) {
    if ( count >= 2 ) continue;
    ++ count;
    std::cout << std::get<0>(args_tuple) << ": " << std::get<1>(args_tuple)
              << '\n';
  }
}
// Registers a benchmark named "BM_takes_args/int_string_test" that passes
// the specified values to `args`.
BENCHMARK_CAPTURE(BM_takes_args, int_string_test, 42, std::string("abc"));

// Registers the same benchmark "BM_takes_args/int_test" that passes
// the specified values to `args`.
//BENCHMARK_CAPTURE(BM_takes_args, int_test, 42, 43);


// Run the benchmark
BENCHMARK_MAIN();