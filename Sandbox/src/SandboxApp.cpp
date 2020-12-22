#include <Kokoro.h>
#include <SDL/SDL.h>

class ExampleLayer : public Kokoro::Layer {
 public:
  ExampleLayer() : Layer("Example") {}

  void OnUpdate() override {
    if (Kokoro::Input::IsKeyPressed(KO_KEY_TAB))
      KO_INFO("Tab Key is Pressed (poll)!!");
  }

  void OnEvent(Kokoro::Event& event) override {
    KO_TRACE("{0}", event);
    if (event.GetEventType() == Kokoro::EventType::KeyPressed) {
      Kokoro::KeyPressedEvent& e = (Kokoro::KeyPressedEvent&)event;
      if (e.GetKeyCode() == KO_KEY_TAB)
        KO_TRACE("Tab key is pressed (event)!");
      KO_TRACE("{0}", (char)e.GetKeyCode());
    }
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
