#include <benchmark/benchmark.h>
#include <chrono>

static const std::chrono::duration<double, std::milli> time_frame(50);
static const double time_frame_in_sec(
    std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1, 1>>>(
        time_frame)
        .count());
void MyBusySpinwait() {
  const auto start = std::chrono::system_clock::now();

  while (true) {
    const auto now = std::chrono::system_clock::now();
    const auto elapsed = now - start;

    if (std::chrono::duration<double, std::chrono::seconds::period>(elapsed) >=
        time_frame)
      return;
  }
}

void BM_MainThread(benchmark::State& state) {
  for (auto _ : state) {
    MyBusySpinwait();
    state.SetIterationTime(time_frame_in_sec);
  }
  state.counters["invtime"] =
      benchmark::Counter{1, benchmark::Counter::kIsRate};
}

BENCHMARK(BM_MainThread)->Iterations(1)->Threads(1);

BENCHMARK_MAIN();