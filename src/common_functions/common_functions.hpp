#pragma once

#include <functional>

#include <core/intervals.hpp>
#include <core/round_mode.hpp>

template <typename T>
Interval<T> GrowingFunc(std::function<T(T x)> func, Interval<T> interval) {
  RoundMode round_mode;

  round_mode.SetDownward();
  T new_left_bound = func(interval.left_bound());

  round_mode.SetUpward();
  T new_right_bound = func(interval.right_bound());

  return Interval<T>(new_left_bound, new_right_bound);
}