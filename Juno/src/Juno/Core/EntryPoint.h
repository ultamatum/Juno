#pragma once

#ifdef JUNO_PLATFORM_WINDOWS || JUNO_PLATFORM_LINUX

extern Juno::Application* Juno::CreateApplication();

int main(int argc, char** argv)
{
	Juno::Log::Init();						//Initialize logging library
	JUNO_CORE_WARN("Initialized Log!");
	JUNO_INFO("Hello!");

	//Start the application
	auto app = Juno::CreateApplication();
	app->Run();
	delete app;
}

#endif