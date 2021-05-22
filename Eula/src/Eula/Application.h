#pragma once
#include "Eula/Core/Base.h"

namespace Eula {

    class EULA_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    //This function need to be defined and implemented by the client(Application)
    Application* CreateApplication();

}
