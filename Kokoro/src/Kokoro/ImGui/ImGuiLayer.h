#pragma once

#include "Kokoro/Layer.h"
#include "Kokoro/Events/KeyEvent.h"

namespace Kokoro {

  class ImGuiLayer : public Layer {
   public:
    ImGuiLayer();
    ~ImGuiLayer();

    void OnAttach() override;
    void OnUpdate() override;
    void OnDetach() override;
    void OnEvent(Event& event) override;
   private:
    float m_Time = 0;
  };
}  // namespace Kokoro
