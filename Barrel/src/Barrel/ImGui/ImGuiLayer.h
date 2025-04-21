#pragma once

#include "Barrel/Layer.h"
#include "Barrel/Events/KeyEvent.h"
#include "Barrel/Events/MouseEvent.h"
#include "Barrel/Events/ApplicationEvent.h"

namespace Barrel
{
	class BARREL_API ImGuiLayer : public Layer
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
		float m_Time = 0.0f;
	};
}