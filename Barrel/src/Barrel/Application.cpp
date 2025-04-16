#include "brpch.h"
#include "Application.h"
#include "Barrel/Events/ApplicationEvent.h"
#include "Barrel/Log.h"

#include "GLFW/glfw3.h"
namespace Barrel
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		while(m_Running)
		{
			glClearColor(0, 0.8, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}