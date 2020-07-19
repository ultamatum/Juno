#pragma once
#include "Juno/Renderer/Camera.h"
#include "Juno/Core/Timestep.h"

#include "Juno/Events/ApplicationEvent.h"
#include "Juno/Events/MouseEvent.h"

namespace Juno
{
	//TODO: Move to Camera class (maybe)
	/*struct OrthographicCameraBounds
	{
		float Left, Right;
		float Bottom, Top;

		float GetWidth() { return Right - Left; };
		float GetHeight() { return Top - Bottom; };
	};*/

	class OrthographicCameraController
	{
		public:
			OrthographicCameraController(float aspectRatio, bool rotation = false);

			void OnUpdate(Timestep ts);
			void OnEvent(Event& e);

			void OnResize(float width, float height);

			OrthographicCamera& GetCamera() { return m_Camera; }
			const OrthographicCamera& GetCamera() const { return m_Camera; }

			float GetZoomLevel() { return m_ZoomLevel; }
			void SetZoomLevel(float level) { m_ZoomLevel = level; CalculateView(); }
		private:
			void CalculateView();

			bool OnMouseScrolled(MouseScrolledEvent& e);
			bool OnWindowResized(WindowResizeEvent& e);

		private:
			float m_AspectRatio;
			float m_ZoomLevel = 1.0f;
			OrthographicCamera m_Camera;

			bool m_Rotation;

			glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
			float m_CameraRotation = 0.0f;
			float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
	};
}