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
  }

  void OpenGLContext::SwapBuffers() {
    glBegin(GL_TRIANGLES);

    glVertex2f(-0.5f, -0.5f);
    glVertex2f( 0.5f, -0.5f);
    glVertex2f( 0.0f,  0.5f);

    glEnd();

    glfwSwapBuffers(m_WindowHandle);
  }

}
