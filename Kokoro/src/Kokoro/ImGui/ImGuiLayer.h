#pragma once

#include "Kokoro/Layer.h"
#include "Kokoro/Events/KeyEvent.h"
#include "Kokoro/Events/MouseEvent.h"
#include "Kokoro/Events/ApplicationEvent.h"

namespace Kokoro {

  class ImGuiLayer : public Layer {
   public:
    ImGuiLayer();
    ~ImGuiLayer();

    void OnAttach() override;
    void OnDetach() override;
    void OnImGuiRender() override;

    void Begin();
    void End();

   private:
    float m_Time = 0;
  };
}  // namespace Kokoro
