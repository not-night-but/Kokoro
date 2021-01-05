#include "kopch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Kokoro {

  OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle{windowHandle} {
    KO_CORE_ASSERT(windowHandle, "Window handle is null!");
  }

  void OpenGLContext::Init() {
    glfwMakeContextCurrent(m_WindowHandle);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    KO_CORE_ASSERT(status, "Failed to initialize Glad!");

    KO_CORE_INFO("OpenGL Info:");
    KO_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
    KO_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
    KO_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
  }

  void OpenGLContext::SwapBuffers() {
    glfwSwapBuffers(m_WindowHandle);
  }

}
