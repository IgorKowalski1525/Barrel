#pragma once

#include "Core.h"
#include "Window.h"
#include "Barrel/Events/ApplicationEvent.h"
#include "Barrel/Events/Event.h"
#include "Barrel/LayerStack.h"

namespace Barrel
{
	class BARREL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in a client
	Application* CreateApplication();
}

