#pragma once

#include "Oak/Layer.h"

#include "Oak/Events/ApplicationEvent.h"
#include "Oak/Events/KeyEvent.h"
#include "Oak/Events/MouseEvent.h"

namespace Oak
{
	class OAK_API ImGuiLayer : public Layer
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