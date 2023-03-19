#pragma once

#include "../Build.h"

namespace fl
{
    namespace heap
    {
        // Heap initialize
        extern FL_API void initialize();
        // Heap cleanup
        extern FL_API void cleanup();

        extern FL_API void *allocate(size_t size);
        extern FL_API void *allocateZero(size_t size);
        extern FL_API void *reallocate(void *block, size_t size);
        extern FL_API void deallocate(void *block);
    }
}