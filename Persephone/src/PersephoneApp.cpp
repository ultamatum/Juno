#include <Juno.h>
#include <Juno/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Juno
{
	class PersephoneApp : public Application
	{
		public:
			PersephoneApp()
				: Application("Juno Editor")
			{
				PushLayer(new Persephone::EditorLayer());
			}

			~PersephoneApp()
			{

			}
	};

	Application* CreateApplication()
	{
		return new PersephoneApp();
	}
}
