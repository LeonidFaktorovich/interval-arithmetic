#pragma once

#include <cmath>

#include <core/intervals.hpp>

namespace intervals {

template <typename T>
Interval<T> Abs(Interval<T> interval) {

  T left_abs = std::fabs(interval.left_bound());
  T right_abs = std::fabs(interval.right_bound());
  return Interval<T>(std::min(left_abs, right_abs), std::max(left_abs, right_abs));
}

}