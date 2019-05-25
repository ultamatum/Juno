#pragma once

#ifdef OK_PLATFORM_WINDOWS

extern Oak::Application* Oak::CreateApplication();

int main(int argc, char** argv)
{
	Oak::Log::Init();
	OK_CORE_WARN("Initialized Log!");
	OK_INFO("Hello!");

	auto app = Oak::CreateApplication();
	app->Run();
	delete app;
}

#endif