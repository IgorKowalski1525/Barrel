#pragma once

#include "Barrel/Core.h"
#include "Barrel/Events/Event.h"

namespace Barrel
{
	class BARREL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach(){}
		virtual void OnDetach(){}
		virtual void OnUpdate(){}
		virtual void OnEvent(Event& event){}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}