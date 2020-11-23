#pragma once

#ifdef KO_PLATFORM_LINUX

extern Kokoro::Application* Kokoro::CreateApplication();

int main(int argc, char** argv) {
  auto app = Kokoro::CreateApplication();
  app->Run();
  delete app;
}

#endif
