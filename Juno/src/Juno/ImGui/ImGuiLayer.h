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
			virtual void OnEvent(Event& e) override;
			
			void Begin();
			void End();

			void BlockEvents(bool block) { m_BlockEvents = block; };

			void SetDarkThemeColours();
		private:
			bool m_BlockEvents = true;
			float m_Time = 0;
	};
}
