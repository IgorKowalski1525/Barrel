#pragma once

#include "Core.h"
#include "Window.h"
#include "Barrel/Events/ApplicationEvent.h"
#include "Barrel/Events/Event.h"
#include "Barrel/LayerStack.h"
#include "Barrel/ImGui/ImGuiLayer.h"
#include "Barrel/Renderer/Shader.h"
#include "Barrel/Renderer/Buffer.h"

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

		inline Window& GetWindow() const { return *m_Window; }
		inline static Application& GetApplication() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

	//To be defined in a client
	Application* CreateApplication();
}

