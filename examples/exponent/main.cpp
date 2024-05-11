#include <iomanip>
#include <iostream>

#include <core/intervals.hpp>
#include <core/round_mode_scope.hpp>
#include <common_functions/taylor_series.hpp>

class ExponentGen {
 public:
  void next() {};
  double get() {return 1; };
};

int main() {
  intervals::RoundModeScope mode(std::float_round_style::round_toward_neg_infinity);

  ExponentGen gen;
  intervals::TaylorSeries<double, ExponentGen> series(gen, 0, intervals::Interval<double>(1, 3));
  for (std::size_t i = 0; i < 100; ++i) {
    series.DoIter();
  }

  std::cout << std::setprecision(20) << series.GetResult() << '\n';
  // expected (2.7182818284590452353 20.085536923187667740)
  // actual   (2.7182818284590410939 20.085536923187973457)
}