#include <iomanip>
#include <iostream>

#include <core/intervals.hpp>
#include <core/round_mode.hpp>
#include <common_functions/taylor_series.hpp>

class SinusGen {
 public:
  void next() {
    // first step
    if (current_value_ == -1) {
      current_value_ = 1;
      return;
    }

    if (current_value_ == 1) {
      current_value_ = 0;
    } else {
      current_value_ = 1;
    }
  };
  double get() {return current_value_; };
 private:
  double current_value_{-1};
};

int main() {
  RoundMode mode;
  mode.SetDownward();

  SinusGen gen;
  TaylorSeries<double, SinusGen> series(gen, /* pi/2 */ 1.5707963267948966, Interval<double>(1.565, 1.575));
  for (std::size_t i = 0; i < 100; ++i) {
    series.DoIter();
  }

  std::cout << std::setprecision(20) << series.GetResult() << '\n';
  // expected (0.9999832013448760614 1.0000000000000000000)
  // actual   (0.9999878170502365382 1.0000088354472274065)
}