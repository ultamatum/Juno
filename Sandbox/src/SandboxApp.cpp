#include <Oak.h>

class Sandbox : public Oak::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Oak::Application* Oak::CreateApplication()
{
	return new Sandbox();
}