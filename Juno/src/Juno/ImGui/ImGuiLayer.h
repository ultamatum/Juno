#pragma once

#include "Juno/Core/Layer.h"

#include "Juno/Events/ApplicationEvent.h"
#include "Juno/Events/KeyEvent.h"
#include "Juno/Events/MouseEvent.h"

namespace Juno
{
	class ImGuiLayer : public Layer
	{
		public:
			ImGuiLayer();
			~ImGuiLayer();

			virtual void OnAttach() override;
			virtual void OnDetach() override;
			
			void Begin();
			void End();
		private:
			float m_Time = 0;
	};
}