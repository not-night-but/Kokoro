#pragma once
#include "Kokoro/Renderer/Buffer.h"

namespace Kokoro {

  class OpenGLVertexBuffer : public VertexBuffer {
  public:
    OpenGLVertexBuffer(float* vertices, uint32_t size);
    ~OpenGLVertexBuffer();
    void Bind() const;
    void Unbind() const;

  private:
    uint32_t m_RendererID;
  };

  class OpenGLIndexBuffer : public IndexBuffer {
  public:
    OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
    ~OpenGLIndexBuffer();
    void Bind() const;
    void Unbind() const;

    uint32_t GetCount() const { return m_Count; }
  
  private:
    uint32_t m_RendererID, m_Count;
  };

}  //  namespace Kokoro