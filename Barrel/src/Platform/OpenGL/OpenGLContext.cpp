#include "brpch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
namespace Barrel
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{
		BR_CORE_ASSERT(windowHandle, "Handle is null");
	}

	void Barrel::OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BR_CORE_ASSERT(status, "Failed to initialize glad.");

		BR_CORE_INFO("OpenGL Info:");
		BR_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		BR_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		BR_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));
	}

	void Barrel::OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}

