#include <iomanip>
#include <iostream>

#include <core/intervals.hpp>
#include <core/round_mode.hpp>
#include <common_functions/taylor_series.hpp>

class ExponentGen {
 public:
  void next() {};
  double get() {return 1; };
};

int main() {
  RoundMode mode;
  mode.SetDownward();

  ExponentGen gen;
  TaylorSeries<double, ExponentGen> series(gen, 0, Interval<double>(1, 3));
  for (std::size_t i = 0; i < 20; ++i) {
    series.DoIter();
  }

  std::cout << std::setprecision(20) << series.GetResult() << '\n';
  // result (2.7182818284590410939 20.085536921517700648)
  // actual (2.7182818284590452353 20.085536923187667740)
}