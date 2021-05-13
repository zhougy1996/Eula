#pragma once

//use EULA_API to replace _declspec(dllexport) or _declspec(dllimport)
#ifdef EULA_PLATFORM_WINDOWS
    #ifdef EULA_BUILD_DLL
        #define EULA_API _declspec(dllexport)
    #else
        #define EULA_API _declspec(dllimport)
    #endif // EULA_BUILD_DLL
#else
    #error Eula only supports Windows!
#endif // EULA_PLATFORM_WINDOWS


