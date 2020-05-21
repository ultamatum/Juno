#pragma once

#include "Juno/Layer.h"

#include "Juno/Events/ApplicationEvent.h"
#include "Juno/Events/KeyEvent.h"
#include "Juno/Events/MouseEvent.h"

namespace Juno
{
	class JUNO_API ImGuiLayer : public Layer
	{
		public:
			ImGuiLayer();
			~ImGuiLayer();

			virtual void OnAttach() override;
			virtual void OnDetach() override;
			virtual void OnImGuiRender() override;
			
			void Begin();
			void End();
		private:
			float m_Time = 0;
	};
}