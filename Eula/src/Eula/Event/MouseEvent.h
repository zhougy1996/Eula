#pragma once

#include "Event.h"

namespace Eula {
    class EULA_API MouseMoveEvent : public Event
    {
    public:
        MouseMoveEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

        inline float GetX() const { return m_MouseX; }
        inline float GetY() const { return m_MouseY; }
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMoveEvent: (" << m_MouseX << ", " << m_MouseY << ")";
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        EVENT_CLASS_TYPE(MouseMove)
    private:
        float m_MouseX, m_MouseY;
    };


    class EULA_API MouseScrollEvent : public Event
    {
    public:
        MouseScrollEvent(float offsetX, float offsetY) : m_OffsetX(offsetX), m_OffsetY(offsetY) {}

        inline float GetXOffset() const { return m_OffsetX; }
        inline float GetYOffset() const { return m_OffsetY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrollEvent: " << m_OffsetX << ", " << m_OffsetY;
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        EVENT_CLASS_TYPE(MouseScroll)
    private:
        float m_OffsetX, m_OffsetY;
    };


    class EULA_API MouseButtonEvent : public Event
    {
    public:
        inline int GetMouseButton() const { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        MouseButtonEvent(int button) : m_Button(button) {}

        int m_Button;
    };

    class EULA_API MouseButtonPressEvent : MouseButtonEvent
    {
    public:
        MouseButtonPressEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPress)
    };

    class EULA_API MouseButtonReleaseEvent : MouseButtonEvent
    {
    public:
        MouseButtonReleaseEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleaseEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonRelease)
    };


}
