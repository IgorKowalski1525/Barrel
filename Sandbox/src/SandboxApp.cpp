#include <Barrel.h>
#include "imgui/imgui.h"
class ExampleLayer : public Barrel::Layer
{
public:
	ExampleLayer() : Layer("Example"){}

	void OnUpdate() override
	{
		if (Barrel::Input::IsKeyPressed(BR_KEY_TAB))
			BR_INFO("TABBED");
	}

	void OnEvent(Barrel::Event& event) override
	{
		/*BR_CORE_INFO(event)*/
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}
};

class Sandbox : public Barrel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Barrel::Application* Barrel::CreateApplication()
{
	return new Sandbox();
}