#include <Barrel.h>

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
};

class Sandbox : public Barrel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Barrel::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Barrel::Application* Barrel::CreateApplication()
{
	return new Sandbox();
}