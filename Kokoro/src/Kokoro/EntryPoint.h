#pragma once

#ifdef KO_PLATFORM_LINUX

extern Kokoro::Application* Kokoro::CreateApplication();

int main(int argc, char** argv) {
  int var = 5;
  Kokoro::Log::Init();
  KO_CORE_WARN("Initialised Log!");
  KO_INFO("Hello! Var = {0}", var);
  auto app = Kokoro::CreateApplication();
  app->Run();
  delete app;
}

#endif
