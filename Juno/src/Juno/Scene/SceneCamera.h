#pragma once

#include "Juno/Renderer/Camera.h"

namespace Juno
{
	class SceneCamera : public Camera
	{
		public:
			enum class ProjectionType { Perspective = 0, Orthographic = 1 };

			SceneCamera();
			virtual ~SceneCamera() = default;

			void SetOrthographic(float size, float nearClip, float farClip);
			void SetPerspective(float verticalFOV, float nearClip, float farClip);

			void SetViewportSize(uint32_t width, uint32_t height);

			float GetPerspectiveVerticalFOV() const { return m_PerspectiveFOV; }
			void SetPerspectiveVerticalFOV(float fov) { m_PerspectiveFOV = fov; RecalculateProjection(); }
			float GetPerspectiveNearClip() const { return m_PerspectiveNear; };
			void SetPerspectiveNearClip(float nearclip) { m_PerspectiveNear = nearclip; RecalculateProjection(); };
			float GetPerspectiveFarClip() const { return m_PerspectiveFar; };
			void SetPerspectiveFarClip(float farclip) { m_PerspectiveFar = farclip; RecalculateProjection(); };

			float GetOrthographicSize() const { return m_OrthographicSize; }
			void SetOrthographicSize(float size) { m_OrthographicSize = size; RecalculateProjection(); }
			float GetOrthographicNearClip() const { return m_OrthographicNear; };
			void SetOrthographicNearClip(float nearclip) { m_OrthographicNear = nearclip; RecalculateProjection(); };
			float GetOrthographicFarClip() const { return m_OrthographicFar; };
			void SetOrthographicFarClip(float farclip) { m_OrthographicFar = farclip; RecalculateProjection(); };

			ProjectionType GetProjectionType() const { return m_ProjectionType; };
			void SetProjectionType(ProjectionType type) { m_ProjectionType = type; RecalculateProjection(); };
		private:
			void RecalculateProjection();

			ProjectionType m_ProjectionType = ProjectionType::Orthographic;

			float m_PerspectiveFOV = glm::radians(45.0f);
			float m_PerspectiveNear = 0.01f, m_PerspectiveFar = 1000.0f;

			float m_OrthographicSize = 10.0f;
			float m_OrthographicNear = -1.0f, m_OrthographicFar = 1.0f;

			float m_AspectRatio = 0.0f;
	};
}
