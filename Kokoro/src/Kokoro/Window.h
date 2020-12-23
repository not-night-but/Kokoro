#pragma once

#include "kopch.h"

#include "Kokoro/Core.h"
#include "Kokoro/Events/Event.h"

namespace Kokoro {

  struct WindowProps {
    std::string Title;
    unsigned int Width;
    unsigned int Height;

    WindowProps(const std::string& title = "Kokoro Engine",
      unsigned int width = 1280, unsigned int height = 720)
      : Title(title), Width(width), Height(height) {}
  };

  // Interface representing a desktop system based window
  class Window {
   public:
    using EventCallbackFn = std::function<void(Event&)>;

    virtual ~Window() {}

    virtual void OnUpdate() = 0;

    virtual unsigned int GetWidth() const = 0;
    virtual unsigned int GetHeight() const = 0;

    // Window attributes
    virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
    virtual void SetVsync(bool enabled) = 0;
    virtual bool IsVSync() const = 0;

    virtual void* GetNativeWindow() const = 0;

    static Window* Create(const WindowProps& props = WindowProps());
  };
}  // namespace Kokoro
