#pragma once

#include "Event.h"

namespace Eula {

    class EULA_API KeyEvent : public Event 
    {
    public:
        //set categories of key events
        EVENT_CLASS_CATEGORY(EventCategoryKeyEvent | EventCategoryInput)
        inline int GetKeyCode() const { return m_KeyCode; }
        virtual std::string ToString() const { return "KeyEvent: " + m_KeyCode; }
    protected:
        KeyEvent(int keyCode) :m_KeyCode(keyCode) {}
        int m_KeyCode;
    };


    class EULA_API KeyPressEvent : public KeyEvent
    {
    public:
        KeyPressEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

        EVENT_CLASS_TYPE(KeyPress)
        inline int GetRepeatCount() { return m_RepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }
    private:
        int m_RepeatCount;
    };

    class EULA_API KeyReleaseEvent : public KeyEvent
    {
    public:
        KeyReleaseEvent(int keyCode) : KeyEvent(keyCode) {}

        EVENT_CLASS_TYPE(KeyRelease)

        std::string ToString() const override
        {
            return "KeyReleaseEvent: " + m_KeyCode;
        }
    };
}
