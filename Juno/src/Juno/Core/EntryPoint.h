#pragma once

#ifdef JUNO_PLATFORM_WINDOWS || JUNO_PLATFORM_LINUX

extern Juno::Application* Juno::CreateApplication();

int main(int argc, char** argv)
{
	Juno::Log::Init();						//Initialize logging library

	JUNO_PROFILE_BEGIN_SESSION("Startup", "JunoProfile-Startup.json");
	auto app = Juno::CreateApplication();
	JUNO_PROFILE_END_SESSION();

	JUNO_PROFILE_BEGIN_SESSION("Runtime", "JunoProfile-Runtime.json");
	app->Run();
	JUNO_PROFILE_END_SESSION();

	JUNO_PROFILE_BEGIN_SESSION("Shutdown", "JunoProfile-Shutdown.json");
	delete app;
	JUNO_PROFILE_END_SESSION();
}

#endif