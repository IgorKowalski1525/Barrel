#include <Barrel.h>
class Sandbox : public Barrel::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Barrel::Application* Barrel::CreateApplication()
{
	return new Sandbox();
}