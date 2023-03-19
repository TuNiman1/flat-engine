#include "Exception.h"

#include <iostream>

namespace fl
{
    namespace exception
    {

        void crash()
        {
            fl::log::fatal("The application has crashed.");
            std::cin.get();
            exit(1);
        }
    }
}