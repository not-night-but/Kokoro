#pragma once

namespace Kokoro {

  class Application {
   public:
    Application();
    virtual ~Application();

    void Run();
  };

  // To be defined by client
  Application* CreateApplication();

}  // namespace Kokoro
