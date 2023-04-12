#pragma once

#include "Blending.h"
#include "Culling.h"
#include "../../Build.h"
#include "../../util/Vector.h"

namespace fl
{
    struct RenderingFlags
    {
        bool depthRead : 1;
        bool depthWrite : 1;
        Culling culling : 2;
        bool wireframe : 1;
        Blending blending : 2;
    };

    class FL_API Renderer
    {
    public:
        Renderer();
        ~Renderer();

        virtual void clear(bool color, bool depth, bool stencil) = 0;

        virtual void setDepthRead(bool flag) = 0;
        virtual void setDepthWrite(bool flag) = 0;
        virtual void setCulling(Culling flag) = 0;
        virtual void setWireframe(bool flag) = 0;
        virtual void setBlending(Blending flag) = 0;

        inline const RenderingFlags &getFlags() const { return m_flags; }
        inline void useFlags() { loadFlags(m_flags); }
        void loadFlags(const RenderingFlags &flags);
        void pushFlags();
        void popFlags();

    private:
        RenderingFlags m_flags;
        Vector<RenderingFlags> m_stack;
    };
}