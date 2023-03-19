#include "Console.h"

#define FL_USE_IOSTREAM
#ifdef FL_PLATFORM_WINDOWS
#define FL_LOG_COLORS 1
#else
#define FL_LOG_COLORS 0
#endif

#include <iostream>

#if FL_LOG_COLORS
#include <Windows.h>
#endif

#include "../Platform.h"

namespace fl
{
    namespace log
    {
        namespace internal
        {
            void printString(cString message)
            {
#ifdef FL_USE_IOSTREAM
                std::cout << message;
#else
                printf(message);
#endif
            }
            FL_API void setColor(ui8f color)
            {
#if FL_LOG_COLORS
                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(handle, color);
#endif
            }
        }
    }
}