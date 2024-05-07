#include <benchmark/benchmark.h>

#include <cfenv>

void SetRound(benchmark::State& state) {
  for (auto _ : state) {
    std::fesetround(FE_DOWNWARD);
    std::fesetround(FE_UPWARD);
  }
}

BENCHMARK(SetRound);

void Downward(benchmark::State& state) {
  std::fesetround(FE_DOWNWARD);
  for (auto _: state) {
    benchmark::DoNotOptimize(10.11 / 4.123456);
  }
}

void Nearest(benchmark::State& state) {
  std::fesetround(FE_TONEAREST);
  for (auto _: state) {
    benchmark::DoNotOptimize(10.11 / 4.123456);
  }
}

BENCHMARK(Downward);
BENCHMARK(Nearest);

BENCHMARK_MAIN();

/*
Run on (8 X 1999.99 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 4096 KiB (x4)
  L3 Unified 16384 KiB (x1)
Load Average: 0.16, 0.04, 0.01
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
SetRound         16.2 ns         16.2 ns     43073907
Downward         3.82 ns         3.82 ns    183958865
Nearest          3.81 ns         3.81 ns    182989306
*/