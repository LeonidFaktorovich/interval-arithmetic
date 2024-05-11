#include <core/round_mode_scope.hpp>

#include <cfenv>
#include <limits>

namespace intervals {

RoundModeScope::RoundModeScope(std::float_round_style mode) noexcept : prev_mode_(std::fegetround()) {
  switch (mode) {
    case std::float_round_style::round_toward_infinity:
      std::fesetround(FE_UPWARD);
      break;
    case std::float_round_style::round_toward_neg_infinity:
      std::fesetround(FE_DOWNWARD);
      break;
    default:
      break;
  }
}

RoundModeScope::~RoundModeScope() {
  std::fesetround(prev_mode_);
}

void RoundModeScope::SetDownward() noexcept {
  std::fesetround(FE_DOWNWARD);
}


void RoundModeScope::SetUpward() noexcept {
  std::fesetround(FE_UPWARD);
}

}