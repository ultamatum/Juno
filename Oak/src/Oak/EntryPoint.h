#pragma once

#ifdef OK_PLATFORM_WINDOWS

extern Oak::Application* Oak::CreateApplication();

int main(int argc, char** argv)
{
	Oak::Log::Init();						//Initialize logging library
	OK_CORE_WARN("Initialized Log!");
	OK_INFO("Hello!");

	//Start the application
	auto app = Oak::CreateApplication();
	app->Run();
	delete app;
}

#endif