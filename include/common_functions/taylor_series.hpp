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

  Interval<T> DoIter() {
    generator_.next();
    
    Interval<T> i(calc_ * generator_.get());
    result_ += i;
    calc_ *= (x_ - a_) / ++next_iter_;

    return i;
  }

  Interval<T> GetResult() const {
    return result_;
  }

 private:
  Gen generator_;
  const T a_;
  const Interval<T> x_;
  Interval<T> calc_{1};

  std::size_t next_iter_{0};
  Interval<T> result_{0};
};