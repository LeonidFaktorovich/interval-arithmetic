#include <iostream>

#include <core/intervals.hpp>

int main() {
    Interval<double> interval(1, 2);
    std::cout << interval << '\n';
}