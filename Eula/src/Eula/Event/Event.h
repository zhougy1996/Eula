#pragma once

#include "Eula/Core/Base.h"

namespace Eula {

    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMove,
        AppTick, AppUpdate, AppRender,
        KeyPress, KeyRelease,
        MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryWindow         = BIT(1),
        EventCategoryInput          = BIT(2),
        EventCategoryKeyEvent       = BIT(3),
        EventCategoryMouse          = BIT(4),
    };

    class EULA_API Event 
    {
    public:
        bool Handled = false;

        virtual EventType GetEventType() const = 0;
        virtual const char* GetEventName() const = 0;
        virtual int GetEventCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetEventName(); };
        inline bool isCategory(EventCategory category) const{
            return GetEventCategoryFlags() & category;
        }

    };

//Create a bunch of necessary functions for an event category
#define EVENT_CLASS_CATEGORY(category) virtual int GetEventCategoryFlags(){return category;}

//Create a bunch of necessary functions for a specific event
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
        virtual EventType GetEventType() const override { return GetStaticType(); }\
        virtual const char* GetEventName() const override { return #type; }


    class EULA_API EventDispatcher
    {
    public:
        EventDispatcher(Event& event) : m_Event(event) {}
        template <typename T, typename F>
        bool Dispatch(const F& func)
        {
            if (m_Event.GetEventType == T.getStaticType())
            {
                return m_Event.Handled |= func(*(T*)&m_Event);
            }
            return false;
        }
    private:
        Event& m_Event;
    };

}