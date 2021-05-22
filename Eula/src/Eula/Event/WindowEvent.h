#pragma once

#include "Event.h"

namespace Eula {

    class EULA_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

        inline unsigned int GetWidth() const { return m_Width; }
        inline unsigned int GetHeight() const { return m_Height; }
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: (" << GetWidth() << ", " << GetHeight() << ")";
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategoryWindow)
        EVENT_CLASS_TYPE(WindowResize)
    private:
        unsigned int m_Width, m_Height;
    };

    class EULA_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        EVENT_CLASS_CATEGORY(EventCategoryWindow)
        EVENT_CLASS_TYPE(WindowClose)
    };

}