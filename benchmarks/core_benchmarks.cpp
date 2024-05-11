#include <benchmark/benchmark.h>
#include <core/intervals.hpp>
#include <core/round_mode_scope.hpp>

void Addition(benchmark::State& state) {
  const double i1 = 12.3456789;
  const double i2 = 45.6789;

  for (auto _ : state) {
    benchmark::DoNotOptimize(i1 + i2);
  }
}

BENCHMARK(Addition);

void IntervalsAddition(benchmark::State& state) {
  intervals::RoundModeScope mode(std::float_round_style::round_toward_neg_infinity);
  const intervals::Interval<double> i1(1.0, 12.3456789);
  const intervals::Interval<double> i2(2.0, 45.6789);

  for (auto _ : state) {
    benchmark::DoNotOptimize(i1 + i2);
  }
}

BENCHMARK(IntervalsAddition);

void Subtraction(benchmark::State& state) {
  const double i1 = 12.3456789;
  const double i2 = 45.6789;

  for (auto _ : state) {
    benchmark::DoNotOptimize(i1 - i2);
  }
}

BENCHMARK(Subtraction);

void IntervalsSubtraction(benchmark::State& state) {
  intervals::RoundModeScope mode(std::float_round_style::round_toward_neg_infinity);
  const intervals::Interval<double> i1(1.0, 12.3456789);
  const intervals::Interval<double> i2(2.0, 45.6789);

  for (auto _ : state) {
    benchmark::DoNotOptimize(i1 - i2);
  }
}

BENCHMARK(IntervalsSubtraction);

void Multiplication(benchmark::State& state) {
  const double i1 = 12.3456789;
  const double i2 = 45.6789;

  for (auto _ : state) {
    benchmark::DoNotOptimize(i1 * i2);
  }
}

BENCHMARK(Multiplication);

void IntervalsMultiplication(benchmark::State& state) {
  intervals::RoundModeScope mode(std::float_round_style::round_toward_neg_infinity);
  const intervals::Interval<double> i1(1.0, 12.3456789);
  const intervals::Interval<double> i2(2.0, 45.6789);

  for (auto _ : state) {
    benchmark::DoNotOptimize(i1 * i2);
  }
}

BENCHMARK(IntervalsMultiplication);

void Division(benchmark::State& state) {
  const double i1 = 12.3456789;
  const double i2 = 45.6789;

  for (auto _ : state) {
    benchmark::DoNotOptimize(i1 / i2);
  }
}

BENCHMARK(Division);

void IntervalsDivision(benchmark::State& state) {
  intervals::RoundModeScope mode(std::float_round_style::round_toward_neg_infinity);
  const intervals::Interval<double> i1(1.0, 12.3456789);
  const intervals::Interval<double> i2(2.0, 45.6789);

  for (auto _ : state) {
    benchmark::DoNotOptimize(i1 / i2);
  }
}

BENCHMARK(IntervalsDivision);

/*
Run on (8 X 1999.99 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 4096 KiB (x4)
  L3 Unified 16384 KiB (x1)
Load Average: 0.27, 0.13, 0.06
------------------------------------------------------------------
Benchmark                        Time             CPU   Iterations
------------------------------------------------------------------
Addition                      1.91 ns         1.91 ns    366869536
IntervalsAddition             8.19 ns         8.19 ns     85543080
Subtraction                   1.73 ns         1.73 ns    410959959
IntervalsSubtraction          8.28 ns         8.28 ns     86202548
Multiplication                1.88 ns         1.88 ns    360238591
IntervalsMultiplication       91.1 ns         91.1 ns      7454240
Division                      2.47 ns         2.47 ns    277053060
IntervalsDivision             92.0 ns         92.0 ns      7422877
*/
