#pragma once

#include <algorithm>
#include <ostream>
#include <istream>

template <typename T>
class Interval {
  friend std::ostream& operator<<(std::ostream& ostream, Interval<T> interval) {
    ostream << interval.left_bound() << ' ' << interval.right_bound();
    return ostream;
  }
  friend std::istream& operator>>(std::istream& istream, Interval<T>& interval) {
    istream >> interval.left_ >> interval.right_;
    return istream;
  }

 public:
  constexpr Interval(T left, T right) : left_(left), right_(right) {
  }
  constexpr explicit Interval(T left) : Interval(left, left) {
  }

  constexpr Interval& operator+=(const Interval& rhs) {
    left_ += rhs.left_;
    right_ = -(-right_ - rhs.right_);
    return *this;
  }
  constexpr Interval operator+(const Interval& rhs) const {
    Interval copy = *this;
    copy += rhs;
    return copy; 
  }
  constexpr Interval& operator-=(const Interval& rhs) {
    left_ -= rhs.right_;
    right_ = -(rhs.left_ - right_);
    return *this;
  }
  constexpr Interval operator-(const Interval& rhs) const {
    Interval copy = *this;
    copy -= rhs;
    return copy;
  }
  constexpr Interval& operator*(const Interval& rhs) {
    left_ = std::min({DownMultiply(left_, rhs.left_), DownMultiply(left_, rhs.right_), DownMultiply(right_, rhs.left_), DownMultiply(right_, rhs.right_)});
    right_ = std::min({UpperMultiply(left_, rhs.left_), UpperMultiply(left_, rhs.right_), UpperMultiply(right_, rhs.left_), UpperMultiply(right_, rhs.right_)});
    return *this;
  }
  constexpr Interval operator*(const Interval& rhs) const {
    Interval copy = *this;
    copy *= rhs;
    return copy;
  }
  constexpr Interval& operator/=(const Interval& rhs) {
    left_ = std::min({DownDivide(left_, rhs.left_), DownDivide(left_, rhs.right_), DownDivide(right_, rhs.left_), DownDivide(right_, rhs.right_)});
    right_ = std::min({UpperDivide(left_, rhs.left_), UpperDivide(left_, rhs.right_), UpperDivide(right_, rhs.left_), UpperDivide(right_, rhs.right_)});
    return *this;
  }
  constexpr Interval operator/(const Interval& rhs) const {
    Interval copy = *this;
    copy /= rhs;
    return copy;
  }

  constexpr Interval& operator+=(T value) {
    return *this += Interval(value);
  }
  constexpr Interval operator+(T value) const {
    return *this + Interval(value);
  }
  constexpr Interval& operator-=(T value) {
    return *this -= Interval(value);
  }
  constexpr Interval operator-(T value) const {
    return *this - Interval(value);
  }
  constexpr Interval& operator*=(T value) {
    return *this *= Interval(value);
  }
  constexpr Interval operator*(T value) const {
    return *this * Interval(value);
  }
  constexpr Interval& operator/=(T value) {
    return *this /= Interval(value);
  }
  constexpr Interval operator/(T value) {
    return *this / value;
  }


  constexpr T left_bound() const {
    return left_;
  }

  constexpr T right_bound() const {
    return right_;
  }

 private:
  static constexpr T UpperMultiply(T lhs, T rhs) {
    return -((-lhs) * rhs);
  }
  static constexpr T DownMultiply(T lhs, T rhs) {
    return lhs * rhs;
  }

  static constexpr T UpperDivide(T lhs, T rhs) {
    return -((-lhs) / rhs);
  }
  static constexpr T DownDivide(T lhs, T rhs) {
    return lhs / rhs;
  }

  T left_;
  T right_;
};
