#pragma once

#include "Oak/Layer.h"

namespace Oak
{
	class OAK_API ImGuiLayer : public Layer
	{
		public:
			ImGuiLayer();
			~ImGuiLayer();

			void OnAttach();
			void OnDetach();
			void OnUpdate();
			void OnEvent(Event& event);
		private:
			float m_Time = 0;
	};
}