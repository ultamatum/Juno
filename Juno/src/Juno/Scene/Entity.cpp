#include "junopch.h"
#include "Entity.h"

namespace Juno
{

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{}

}