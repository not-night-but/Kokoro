#include "kopch.h"
#include "LinuxWindow.h"

#include "Kokoro/Events/ApplicationEvent.h"
#include "Kokoro/Events/MouseEvent.h"
#include "Kokoro/Events/KeyEvent.h"

#include "Platform/OpenGL/OpenGLContext.h"

namespace Kokoro {

  static bool s_GLFWInitialized = false;

  static void GLFWErrorCallback(int error, const char* description) {
    KO_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
  }

  Window* Window::Create(const WindowProps& props) {
    return new LinuxWindow(props);
  }

  LinuxWindow::LinuxWindow(const WindowProps& props) {
    Init(props);
  }

  LinuxWindow::~LinuxWindow() {}

  void LinuxWindow::Init(const WindowProps& props) {
    m_Data.Title = props.Title;
    m_Data.Width = props.Width;
    m_Data.Height = props.Height;


    KO_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

    if (!s_GLFWInitialized) {
      // TODO(@dsm6069) glfwTerminate on system shutdown
      int succes = glfwInit();
      KO_CORE_ASSERT(succes, "Could not initialize GLFW!");
      glfwSetErrorCallback(GLFWErrorCallback);
      s_GLFWInitialized = true;
    }
    m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);

    m_Context = new OpenGLContext(m_Window);
    m_Context->Init();

    glfwSetWindowUserPointer(m_Window, &m_Data);
    SetVsync(true);

    // Set GLFW callbacks
    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
      data.Width = width;
      data.Height = height;

      WindowResizeEvent event(width, height);
      data.EventCallback(event);
    });

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
      WindowCloseEvent event;
      data.EventCallback(event);
    });

    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

      switch (action) {
        case GLFW_PRESS: {
          KeyPressedEvent event(key, 0);
          data.EventCallback(event);
          break;
        }
        case GLFW_RELEASE: {
          KeyReleasedEvent event(key);
          data.EventCallback(event);
          break;
        }
        case GLFW_REPEAT: {
          KeyPressedEvent event(key, 1);
          data.EventCallback(event);
          break;
        }
      }
    });

    glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int character) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

      KeyTypedEvent event(character);
      data.EventCallback(event);
    });

    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

      switch (action) {
        case GLFW_PRESS: {
          MouseButtonPressedEvent event(button);
          data.EventCallback(event);
        }
        case GLFW_RELEASE: {
          MouseButtonReleasedEvent event(button);
          data.EventCallback(event);
        }
      }
    });

    glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

      MouseScrolledEvent event((float)xOffset, (float)yOffset);
      data.EventCallback(event);
    });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

      MouseMovedEvent event((float)xPos, (float)yPos);
      data.EventCallback(event);
    });
  }

  void LinuxWindow::Shutdown() {
    glfwDestroyWindow(m_Window);
  }

  void LinuxWindow::OnUpdate() {
    glfwPollEvents();
    m_Context->SwapBuffers();
  }

  void LinuxWindow::SetVsync(bool enabled) {
    if (enabled)
      glfwSwapInterval(1);
    else
      glfwSwapInterval(0);

    m_Data.VSync = enabled;
  }

  bool LinuxWindow::IsVSync() const {
    return m_Data.VSync;
  }

}  // namespace Kokoro
