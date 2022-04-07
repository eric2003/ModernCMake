#include <benchmark/benchmark.h>

void BM_time_label_nanosecond(benchmark::State& state) {
  for (auto _ : state) {
  }
}

void BM_time_label_microsecond(benchmark::State& state) {
  for (auto _ : state) {
  }
}

void BM_time_label_millisecond(benchmark::State& state) {
  for (auto _ : state) {
  }
}

void BM_time_label_second(benchmark::State& state) {
  for (auto _ : state) {
  }
}

BENCHMARK(BM_time_label_millisecond)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_time_label_microsecond)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_time_label_nanosecond)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_time_label_second)->Unit(benchmark::kSecond);

BENCHMARK_MAIN();