#include <core/round_mode.hpp>

#include <cfenv>

RoundMode::RoundMode() : prev_mode_(std::fegetround()) {
}

RoundMode::~RoundMode() {
  std::fesetround(prev_mode_);
}

void RoundMode::SetDownward() noexcept {
  std::fesetround(FE_DOWNWARD);
}


void RoundMode::SetUpward() noexcept {
  std::fesetround(FE_UPWARD);
}