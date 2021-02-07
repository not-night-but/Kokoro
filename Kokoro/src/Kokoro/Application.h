#pragma once

#include "Core.h"

#include "Window.h"
#include "Kokoro/LayerStack.h"
#include "Kokoro/Events/Event.h"
#include "Kokoro/Events/ApplicationEvent.h"

#include "Kokoro/ImGui/ImGuiLayer.h"

#include "Kokoro/Renderer/Shader.h"
#include "Kokoro/Renderer/Buffer.h"

namespace Kokoro {

  class Application {
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

    unsigned int m_VertexArray;
    std::unique_ptr<Shader> m_Shader;
    std::unique_ptr<VertexBuffer> m_VertexBuffer;
    std::unique_ptr<IndexBuffer> m_IndexBuffer;

    static Application* s_Instance;
  };

  // To be defined in client
  Application* CreateApplication();

}  // namespace Kokoro
