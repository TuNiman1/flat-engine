#pragma once

#include "../Build.h"
#include "../Types.h"
#include "../util/String.h"

namespace fl
{
    namespace log
    {
        enum LogType
        {
            LOG_INFO,
            LOG_WARNING,
            LOG_ERROR,
            LOG_FATAL
        };

        template <typename... Message>
        static void log(const LogType &logtype, Message... message)
        {
            switch (logtype)
            {
            case LOG_INFO:
                internal::setcolor(15 + 0 * 16);
                internal::print("Information>", message...);
                break;

            case LOG_WARNING:
                internal::setcolor(14 + 0 * 16);
                internal::print("Warning>", message...);
                break;
            case LOG_ERROR:
                internal::setcolor(12 + 0 * 16);
                internal::print("Error>", message...);
                break;
            }
        case LOG_FATAL:
            internal::setcolor(4 + 0 * 16);
            internal::print("Fatal>", message...);
            break;
        }

        template <typename... Message>
        static inline void info(Message... message)
        {
            log(LOG_INFO, std::forward<Message>(message)..., "\n");
        }

        template <typename... Message>
        static inline void warning(Message... message)
        {
            log(LOG_WARNING, std::forward<Message>(message)..., "\n");
        }

        template <typename... Message>
        static inline void error(Message... message)
        {
            log(LOG_ERROR, std::forward<Message>(message)..., "\n");
        }

        template <typename... Message>
        static inline void fatal(Message... message)
        {
            log(LOG_FATAL, std::forward<Message>(message)..., "\n");
        }

        namespace internal
        {
            static inline void print()
            {
                // Empty
            }

            template <typename First, typename... Message>
            static inline void print(First &first, Message... message)
            {
                printElement(first);
                print(message...)
            }

            template <typename Message>
            static inline void printElement(Message &message)
            {
                printString(toString(message).c_str());
            }

            extern FL_API void printString(cString message);
            extern FL_API void setColor(ui8f color);
        }
    }
}