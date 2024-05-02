#pragma once

class RoundMode final {
 public:
  explicit RoundMode();
  ~RoundMode();

  void SetDownward() noexcept;
  void SetUpward() noexcept;

 private:
  const int prev_mode_;
};