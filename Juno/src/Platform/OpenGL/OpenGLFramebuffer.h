#pragma once

#include "Juno/Renderer/FrameBuffer.h"

namespace Juno
{
	class OpenGLFrameBuffer : public Framebuffer
	{
		public:
			OpenGLFrameBuffer(const FramebufferSpecification& spec);
			virtual ~OpenGLFrameBuffer();

			void Invalidate();

			virtual void Bind() override;
			virtual void Unbind() override;

			virtual void Resize(uint32_t width, uint32_t height) override;

			virtual uint32_t GetColourAttachmentRendererID() const override { return m_ColourAttachment; }

			virtual const FramebufferSpecification& GetSpecification() const override { return m_Specification; }
		private:
			uint32_t m_RendererID = 0;
			uint32_t m_ColourAttachment = 0, m_DepthAttachment = 0;
			FramebufferSpecification m_Specification;
	};
}