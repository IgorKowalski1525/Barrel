#include "brpch.h"
#include "Application.h"
#include "Barrel/Events/ApplicationEvent.h"
#include "Barrel/Log.h"
namespace Barrel
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		BR_TRACE(e.ToString())

			if (!e.IsInCategory(EventCategoryKeyboard))
				BR_CRITICAL("This is a triumph.")
				while (true);
	}
}