#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>

template <typename T>
class MyFixture : public ::benchmark::Fixture {
 public:
  MyFixture() : data(0) {}

  T data;
};

BENCHMARK_TEMPLATE_DEFINE_F(MyFixture, Foo, int)(benchmark::State& st) {
  for (auto _ : st) {
    data += 1;
  }
}


BENCHMARK_TEMPLATE_DEFINE_F(MyFixture, Bar, double)(benchmark::State& st) {
  for (auto _ : st) {
    data += 2.0;
  }
}

BENCHMARK_REGISTER_F(MyFixture, Bar)
    ->Arg(1)
    ->Arg(3)
    ->Arg(5);
BENCHMARK_REGISTER_F(MyFixture, Foo)
    ->Arg(2)
    ->Arg(4)
    ->Arg(6);

BENCHMARK_MAIN();