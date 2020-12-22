#pragma once

#include "kopch.h"

#include "Events/Event.h"

namespace Kokoro {

  class KOKORO_API Layer {
   public:
    Layer(const std::string& name = "Layer") : m_DebugName(name) {}
    ~Layer() {}

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}
    virtual void OnImGuiRender() {}
    virtual void OnEvent(Event& e) {}

    inline const std::string GetName() const { return m_DebugName; }
   private:
    std::string m_DebugName;
  };

}  // namespace Kokoro
