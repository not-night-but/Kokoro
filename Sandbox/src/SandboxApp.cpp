#include <Kokoro.h>
#include <SDL/SDL.h>

class ExampleLayer : public Kokoro::Layer {
 public:
  ExampleLayer() : Layer("Example") {}

  void OnUpdate() override {
    if (Kokoro::Input::IsKeyPressed(KO_KEY_TAB))
      KO_INFO("Tab Key is Pressed!!");
  }

  void OnEvent(Kokoro::Event& event) override {
  }
};

class Sandbox : public Kokoro::Application {
 public:
  Sandbox() {
    PushLayer(new ExampleLayer());
    PushLayer(new Kokoro::ImGuiLayer());
  }
  ~Sandbox() {}
};

Kokoro::Application* Kokoro::CreateApplication() {
  return new Sandbox();
}

// //TODO(@dsm6069) Put wrapper around SDL functions for linking.
// int main() {
//   SDL_LoadObject("libKokoro.so");
// }
