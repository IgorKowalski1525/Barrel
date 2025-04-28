#include "brpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
namespace Barrel
{
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch(Renderer::GetAPI())
		{
		case RendererAPI::None: BR_CORE_ASSERT(false, "RendererAPI::None is not good."); return nullptr;
			break;
		case RendererAPI::OpenGL: return new OpenGLVertexBuffer(vertices, size);
			break;
		}
		BR_CORE_ASSERT(false, "Idk what the fuck kinda RendererAPI is this.");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None: BR_CORE_ASSERT(false, "RendererAPI::None is not good."); return nullptr;
			case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices, size);
		}
		BR_CORE_ASSERT(false, "Idk what the fuck kinda RendererAPI is this.");
		return nullptr;
	}
}