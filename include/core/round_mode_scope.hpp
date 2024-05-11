#pragma once

#include <limits>

namespace intervals {

class RoundModeScope final {
 public:
  explicit RoundModeScope(std::float_round_style mode) noexcept;
  ~RoundModeScope();

  void SetDownward() noexcept;
  void SetUpward() noexcept;

 private:
  const int prev_mode_;
};

}