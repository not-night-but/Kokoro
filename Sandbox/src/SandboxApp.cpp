#include <Kokoro.h>
#include <SDL/SDL.h>

class Sandbox : public Kokoro::Application {
 public:
  Sandbox() {}
  ~Sandbox() {}
};

Kokoro::Application* Kokoro::CreateApplication() {
  return new Sandbox();
}

// //TODO(@dsm6069) Put wrapper around SDL functions for linking.
// int main() {
//   SDL_LoadObject("libKokoro.so");
// }
