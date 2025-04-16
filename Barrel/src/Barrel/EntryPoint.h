#pragma once

#ifdef BR_PLATFORM_WINDOWS

extern Barrel::Application* Barrel::CreateApplication();

int main(int argc, char** argv)
{
	Barrel::Log::Init();
	BR_CORE_WARN("Problem z alkoholem mam tylko wtedy, kiedy go rozlewam, buhaha!");
	BR_INFO("Czas wytoczyc beczke.");
	int a = 5000;
	BR_INFO("Wypite piwa {0}", a);
	auto app = Barrel::CreateApplication();
	app->Run();
	delete app;
}

#endif