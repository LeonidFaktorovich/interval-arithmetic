#include <core/intervals.hpp>
#include <core/round_mode_scope.hpp>
#include <iostream>
#include <common_functions/abs.hpp>

int main() {
    intervals::RoundModeScope mode(std::float_round_style::round_toward_neg_infinity);
    intervals::Interval<double> interval(0);
    std::cin >> interval;
    std::cout << "Result interval: " << Abs(interval);
}