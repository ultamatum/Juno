#include <Juno.h>
#include <Juno/Core/EntryPoint.h>

#include "Sandbox2D.h"

class Sandbox : public Juno::Application
{
	public:
		Sandbox()
		{
			PushLayer(new Sandbox2D());
		}

		~Sandbox()
		{

		}
};

Juno::Application* Juno::CreateApplication()
{
	return new Sandbox();
}