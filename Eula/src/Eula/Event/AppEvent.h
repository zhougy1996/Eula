#pragma once

#include "Event.h"

namespace Eula {

    class EULA_API AppTickEvent : public Event
    {
    public:
        AppTickEvent() {}

        EVENT_CLASS_CATEGORY(EventCategoryApplication)
        EVENT_CLASS_TYPE(AppTick)
    };

    class EULA_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}

        EVENT_CLASS_CATEGORY(EventCategoryApplication)
        EVENT_CLASS_TYPE(AppUpdate)
    };

    class EULA_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}

        EVENT_CLASS_CATEGORY(EventCategoryApplication)
        EVENT_CLASS_TYPE(AppRender)
    };

}