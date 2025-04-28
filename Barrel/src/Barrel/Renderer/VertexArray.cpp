#include "brpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"
namespace Barrel
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: BR_CORE_ASSERT(false, "RendererAPI::None is not good."); return nullptr;
			break;
		case RendererAPI::OpenGL: return new OpenGLVertexArray();
			break;
		}
		BR_CORE_ASSERT(false, "Idk what the fuck kinda RendererAPI is this.");
		return nullptr;
	}
}