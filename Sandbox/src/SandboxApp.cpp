#include <Kokoro.h>
#include <SDL/SDL.h>

class ExampleLayer : public Kokoro::Layer {
 public:
  ExampleLayer() : Layer("Example") {}

  void OnUpdate() override {
    KO_INFO("ExampleLayer::Update");
  }

  void OnEvent(Kokoro::Event& event) override {
    KO_TRACE("{0}", event);
  }
};

class Sandbox : public Kokoro::Application {
 public:
  Sandbox() {
    PushLayer(new ExampleLayer());
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
