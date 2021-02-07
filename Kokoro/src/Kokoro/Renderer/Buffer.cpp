#include "kopch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Kokoro {

  VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) {
    switch (Renderer::GetAPI()) {
      case RendererAPI::None:
        KO_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
      case RendererAPI::OpenGL: 
        return new OpenGLVertexBuffer(vertices, size);
      default:
        KO_CORE_ASSERT(false, "Unkown RendererAPI!");
      return nullptr;
    }
  }

  IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count) {  
    switch (Renderer::GetAPI()) {
      case RendererAPI::None:
        KO_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
      case RendererAPI::OpenGL: 
        return new OpenGLIndexBuffer(indices, count);
      default:
        KO_CORE_ASSERT(false, "Unkown RendererAPI!");
      return nullptr;
    }
  }
}