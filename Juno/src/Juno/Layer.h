#pragma once

#include "Juno/Core.h"
#include "Juno/Core/Timestep.h"
#include "Juno/Events/Event.h"

namespace Juno
{
	class JUNO_API Layer
	{
		public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer();

			virtual void OnAttach() {}
			virtual void OnDetach() {}
			virtual void OnUpdate(Timestep ts) {}
			virtual void OnImGuiRender() {}
			virtual void OnEvent(Event& event) {}

			inline const std::string& GetName() const { return m_DebugName; }
		protected:
			std::string m_DebugName;

	};
}