#include <Juno.h>
#include <Juno/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Juno
{
	class Persephone : public Application
	{
		public:
			Persephone()
				: Application("Persephone")
			{
				PushLayer(new EditorLayer());
			}

			~Persephone()
			{

			}
	};

	Application* CreateApplication()
	{
		return new Persephone();
	}
}
