#pragma once

#include <concepts>
#include <functional>

#include <core/intervals.hpp>
#include <core/round_mode.hpp>

template<class Gen, typename Result>
concept Generator = requires(Gen generator)
{ 
    { generator.next() } -> std::convertible_to<void>;
    { generator.get() } -> std::convertible_to<Result>;
};
 
template <typename T, Generator<T> Gen>
class TaylorSeries final {
 public:
  TaylorSeries(Gen generator, T a, Interval<T> x) : generator_(std::move(generator)), a_(a), x_(x) {
  }

  void DoIter() {
  }

 private:
  Gen generator_;
  T a_;
  Interval<T> x_;

  std::size_t next_iter_{0};
  T factorial_{1};
  Interval<T> result_{0};
};