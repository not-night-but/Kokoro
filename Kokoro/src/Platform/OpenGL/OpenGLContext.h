#pragma once

#include "Kokoro/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Kokoro {

  class OpenGLContext : public GraphicsContext {
   public:
    OpenGLContext(GLFWwindow* windowHandle);

    void Init() override;
    void SwapBuffers() override;
   private:
    GLFWwindow* m_WindowHandle;
  };
}  // namespace Kokoro
