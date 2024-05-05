#pragma once

#include <functional>

#include <core/intervals.hpp>
#include <core/round_mode_scope.hpp>

template <typename T>
Interval<T> GrowingFunc(std::function<T(T x)> func, Interval<T> interval) {
  RoundModeScope round_mode_scope(std::float_round_style::round_toward_neg_infinity);

  T new_left_bound = func(interval.left_bound());

  round_mode_scope.SetUpward();
  T new_right_bound = func(interval.right_bound());

  return Interval<T>(new_left_bound, new_right_bound);
}