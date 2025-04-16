#include <Barrel.h>

class ExampleLayer : public Barrel::Layer
{
public:
	ExampleLayer() : Layer("Example"){}

	void OnUpdate() override
	{
		BR_INFO("ExampleLayer::Update");
	}

	void OnEvent(Barrel::Event& event) override
	{
		BR_TRACE("{0}", event.ToString());
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