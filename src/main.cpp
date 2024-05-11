#include "core/intervals.hpp"
#include <iostream>
#include <common_functions/abs.hpp>

int main() {
    intervals::Interval<double> interval(0);
    std::cin >> interval;
    std::cout << "Result interval: " << Abs(interval);
}