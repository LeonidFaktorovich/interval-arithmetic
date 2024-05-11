#include <benchmark/benchmark.h>
#include <core/intervals.hpp>

void Addition(benchmark::State& state) {
  const intervals::Interval<double> i1(1.0, 12.3456789);
  const intervals::Interval<double> i2(2.0, 45.6789);

  for (auto _ : state) {
    benchmark::DoNotOptimize(i1 + i2);
  }
}

BENCHMARK(Addition);

void Subtraction(benchmark::State& state) {
  const intervals::Interval<double> i1(1.0, 12.3456789);
  const intervals::Interval<double> i2(2.0, 45.6789);

  for (auto _ : state) {
    benchmark::DoNotOptimize(i1 - i2);
  }
}

BENCHMARK(Subtraction);

void Multiplication(benchmark::State& state) {
  const intervals::Interval<double> i1(1.0, 12.3456789);
  const intervals::Interval<double> i2(2.0, 45.6789);

  for (auto _ : state) {
    benchmark::DoNotOptimize(i1 * i2);
  }
}

BENCHMARK(Multiplication);

void Division(benchmark::State& state) {
  const intervals::Interval<double> i1(1.0, 12.3456789);
  const intervals::Interval<double> i2(2.0, 45.6789);

  for (auto _ : state) {
    benchmark::DoNotOptimize(i1 / i2);
  }
}

BENCHMARK(Division);

/*
Run on (8 X 1999.99 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 4096 KiB (x4)
  L3 Unified 16384 KiB (x1)
Load Average: 0.16, 0.14, 0.05
---------------------------------------------------------
Benchmark               Time             CPU   Iterations
---------------------------------------------------------
Addition             8.19 ns         8.19 ns     84348687
Subtraction          8.89 ns         8.89 ns     78234749
Multiplication       93.4 ns         93.4 ns      7542509
Division             93.0 ns         93.0 ns      7624084
*/
