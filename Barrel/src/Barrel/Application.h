#pragma once

#include "Core.h"
#include "Window.h"
#include "Barrel/Events/ApplicationEvent.h"
#include "Barrel/Events/Event.h"
#include "Barrel/LayerStack.h"
#include "Barrel/ImGui/ImGuiLayer.h"
#include "Barrel/Renderer/Shader.h"
#include "Barrel/Renderer/Buffer.h"
#include "Barrel/Renderer/VertexArray.h"
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

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<VertexArray> m_SquareVA;
		std::shared_ptr<Shader> m_BlueShader;
	private:
		static Application* s_Instance;
	};

	//To be defined in a client
	Application* CreateApplication();
}

