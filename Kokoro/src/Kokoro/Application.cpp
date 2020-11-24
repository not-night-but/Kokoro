#include "kopch.h"
#include "Application.h"

#include "Kokoro/Events/ApplicationEvent.h"
#include "Kokoro/Log.h"

namespace Kokoro {

  Application::Application() {
  }

  Application::~Application() {
  }

  void Application::Run() {
    WindowResizeEvent e(128, 720);
    KO_INFO(e);
    while (true) {
    }
  }

}  // namespace Kokoro
