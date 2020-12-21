#pragma once

#include "kopch.h"
#include "Kokoro/Input.h"

namespace Kokoro {
  class LinuxInput : public Input {
   protected:
    bool IsKeyPressedImpl(int keycode) override;

    bool IsMouseButtonPressedImpl(int button) override;
    std::pair<float, float> GetMousePositionImpl() override;
    float GetMouseXImpl() override;
    float GetMouseYImpl() override;
  };
}  // namespace Kokoro
