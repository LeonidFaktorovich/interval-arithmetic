#include <core/round_mode.hpp>

#include <fenv.h>

RoundMode::RoundMode() : prev_mode_(fegetround()) {
}

RoundMode::~RoundMode() {
  fesetround(prev_mode_);
}

void RoundMode::SetDownward() noexcept {
  fesetround(FE_DOWNWARD);
}


void RoundMode::SetUpward() noexcept {
  fesetround(FE_UPWARD);
}