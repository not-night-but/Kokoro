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
    void OnUpdate() override;
    void OnDetach() override;
    void OnEvent(Event& event) override;
   private:
    bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
    bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
    bool OnMouseMovedEvent(MouseMovedEvent& e);
    bool OnMouseScrolledEvent(MouseScrolledEvent& e);
    bool OnKeyPressedEvent(KeyPressedEvent& e);
    bool OnKeyReleasedEvent(KeyReleasedEvent& e);
    bool OnKeyTypedEvent(KeyTypedEvent& e);
    bool OnWindowResizeEvent(WindowResizeEvent& e);
   private:
    float m_Time = 0;
  };
}  // namespace Kokoro
