#include "Type.h"

#include "../../glad/include/glad/glad.h"
#include "../../io/Console.h"

namespace fl
{
    namespace type
    {

        ui32 getGLType(const Type &type)
        {
            switch (type)
            {
            case FLOAT:
                return GL_FLOAT;
                break;
            case DOUBLE:
                return GL_DOUBLE;
                break;
            case UNSIGNED_BYTE:
                return GL_UNSIGNED_BYTE;
                break;
            case UNSIGNED_SHORT:
                return GL_UNSIGNED_SHORT;
                break;
            case UNSIGNED_INT:
                return GL_UNSIGNED_INT;
                break;
            default:
                log::error("Invalid type: ", type);
                break;
            }
            return 0;
        }

        ui32 getGLTypeSize(const Type &type)
        {
            switch (type)
            {
            case FLOAT:
                return sizeof(GLfloat);
                break;
            case DOUBLE:
                return sizeof(GLdouble);
                break;
            case UNSIGNED_BYTE:
                return sizeof(GLubyte);
                break;
            case UNSIGNED_SHORT:
                return sizeof(GLushort);
                break;
            case UNSIGNED_INT:
                return sizeof(GLuint);
                break;
            default:
                log::error("Invalid type: ", type);
                break;
            }
            return 0;
        }

    }
}