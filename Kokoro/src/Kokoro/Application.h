#pragma once

#include "Core.h"

#include "Window.h"
#include "Kokoro/LayerStack.h"
#include "Kokoro/Events/Event.h"
#include "Kokoro/Events/ApplicationEvent.h"

#include "Kokoro/ImGui/ImGuiLayer.h"

namespace Kokoro {

  class KOKORO_API Application {
   public:
    Application();
    virtual ~Application();

    void Run();

    void OnEvent(Event& e);

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* layer);

    static inline Application& Get() { return *s_Instance; }
    inline Window& GetWindow() const { return *m_Window; }
   private:
    bool OnWindowClose(WindowCloseEvent& e);

    std::unique_ptr<Window> m_Window;
    ImGuiLayer* m_ImGuiLayer;
    bool m_Running = true;
    LayerStack m_LayerStack;

    static Application* s_Instance;
  };

  // To be defined in client
  Application* CreateApplication();

}  // namespace Kokoro
