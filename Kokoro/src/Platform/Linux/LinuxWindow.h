#pragma once

// IDEA(@dsm6069) maybe use SDL instead of GLFW?
#include "Kokoro/Window.h"
#include "Kokoro/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Kokoro {

  class LinuxWindow : public Window {
   public:
    LinuxWindow(const WindowProps& props);
    virtual ~LinuxWindow();

    void OnUpdate() override;

    inline unsigned int GetWidth() const override { return m_Data.Width; }
    inline unsigned int GetHeight() const override { return m_Data.Height; }

    // Window attributes
    inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
    void SetVsync(bool enabled) override;
    bool IsVSync() const override;

    inline void* GetNativeWindow() const override { return m_Window; }

   private:
    virtual void Init(const WindowProps& props);
    virtual void Shutdown();

    GLFWwindow* m_Window;
    GraphicsContext* m_Context;

    struct WindowData {
      std::string Title;
      unsigned int Width, Height;
      bool VSync;

      EventCallbackFn EventCallback;
    };

    WindowData m_Data;
  };
}  // namespace Kokoro
