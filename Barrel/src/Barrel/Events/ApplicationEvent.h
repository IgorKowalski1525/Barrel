#pragma once

#include "Event.h"

#include <sstream>

namespace Barrel
{
	class BARREL_API ApplicationEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class BARREL_API WindowResizeEvent : public ApplicationEvent
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: (" << m_Width << "," << m_Height << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)

	private:
		unsigned int m_Width, m_Height;
	};

	class BARREL_API WindowCloseEvent : public ApplicationEvent
	{
	public:
		WindowCloseEvent() {};
		EVENT_CLASS_TYPE(WindowClose)
	};

	class BARREL_API WindowFocusEvent : public ApplicationEvent
	{
	public:
		WindowFocusEvent() {};
		EVENT_CLASS_TYPE(WindowFocus)
	};

	class BARREL_API WindowLostFocusEvent : public ApplicationEvent
	{
	public:
		WindowLostFocusEvent() {};
		EVENT_CLASS_TYPE(WindowLostFocus)
	};

	class BARREL_API WindowMovedEvent : public ApplicationEvent
	{
	public:
		WindowMovedEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {};

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }
		std::string ToString() const
		{
			std::stringstream ss;
			ss << "WindowMovedEvent: (" << m_XOffset << "," << m_YOffset << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowMoved)
	private:
		float m_XOffset, m_YOffset;
	};

	class BARREL_API AppTickEvent : public ApplicationEvent
	{
	public:
		AppTickEvent(){}
		EVENT_CLASS_TYPE(AppTick)
	};

	class BARREL_API AppUpdateEvent : public ApplicationEvent
	{
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate)
	};

	class BARREL_API AppRenderEvent : public ApplicationEvent
	{
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
	};
}