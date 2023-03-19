#include "Flat.h"
#include "memory/Heap.h"
namespace fl
{
    void initialize()
    {
        heap::initialize();
    }

    void cleanup()
    {
        heap::cleanup();
    }
}