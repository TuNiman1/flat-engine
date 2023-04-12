#include "Renderer.h"

#include "../../io/Console.h"
#include "../../Build.h"

#define FL_MAX_STACK_SIZE 64

namespace fl
{
    Renderer::Renderer() : m_flags(), m_stack()
    {
    }

    Renderer::~Renderer()
    {
    }

    void Renderer::loadFlags(const RenderingFlags &flags)
    {
        setDepthRead(flags.depthRead);
        setDepthWrite(flags.depthWrite);
        setCulling(flags.culling);
        setWireframe(flags.wireframe);
        setBlending(flags.blending);
    }

    void Renderer::pushFlags()
    {
#ifdef FL_DEBUG
        if (m_stack.size() >= FL_MAX_STACK_SIZE)
        {
            log::warning("Max rendering stack size reached: ", m_stack.size());
            return;
        }
#endif
        m_stack.pushBack(m_flags);
    }
    void Renderer::popFlags()
    {
#ifdef FL_DEBUG
        if (m_stack.size() == 0)
        {
            log::error("Rendering stack is empty, flags cannot be popped");
            return;
        }
#endif

        m_flags = m_stack.getLastElement();
        m_stack.popBack();
        loadFlags(m_flags);
    }
}