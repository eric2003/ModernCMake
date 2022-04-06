#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>

template <typename T>
class MyFixture : public ::benchmark::Fixture {
 public:
  MyFixture() : data(0) {}

  T data;
};

BENCHMARK_TEMPLATE_F(MyFixture, Foo, int)(benchmark::State& st) {
  for (auto _ : st) {
    data += 1;
  }
}

BENCHMARK_TEMPLATE_F(MyFixture, Bar, double)(benchmark::State& st) {
  for (auto _ : st) {
    data += 2.0;
  }
}

BENCHMARK_MAIN();