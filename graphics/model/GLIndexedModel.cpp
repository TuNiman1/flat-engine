#include "GLIndexedModel.h"

#include "../../glad/include/glad/glad.h"
#include "Attribute.h"
#include "Primitive.h"

namespace fl
{

    GLIndexedModel::GLIndexedModel() : m_vbo(0), m_ibo(0), m_vao(0), m_primitive(0), m_indexType(0), m_numIndices(0)
    {
        setPrimitive(P_TRIANGLE);
    }

    GLIndexedModel::~GLIndexedModel()
    {
    }

    void GLIndexedModel::initialize()
    {
        FL_DEBUG_ASSERT_M(!isInitialized(), "Unable to initialize an indexed model that is already initialized.");
        glGenBuffers(1, &m_vbo);
        glGenBuffers(1, &m_ibo);
        glGenVertexArrays(1, &m_vao);
    }

    void GLIndexedModel::cleanup()
    {
        FL_DEBUG_ASSERT_M(isInitialized(), "Unable to clean up an indexed model that is not initialized.");
        glDeleteBuffers(1, &m_vbo);
        glDeleteBuffers(1, &m_ibo);
        glDeleteVertexArrays(1, &m_vao);
        m_vbo = 0;
        m_ibo = 0;
        m_vao = 0;
    }

    void GLIndexedModel::setData(const void *vertexData, ui32 numVertices, const void *indexData, ui32 numIndices, const Type &indexType, const Attribute *attributes, ui32 numAttributes, UsageHint usageHint)
    {
        m_numIndices = numIndices;
        m_indexType = type::getGLType(indexType);

        glBindVertexArray(m_vao);

        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

        ui32 stride = 0;
        for (ui32 i = 0; i < numAttributes; i++)
        {
            stride += type::getGLTypeSize(attributes[i].type) * attributes[i].amount;
        }
        glBufferData(GL_ARRAY_BUFFER, stride * numVertices, vertexData, usagehint::getGLUsageHint(usageHint));
        ui32 pointer = 0;
        for (ui32 i = 0; i < numAttributes; i++)
        {
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, attributes[i].amount, type::getGLType(attributes[i].type), attributes[i].normalized, stride, reinterpret_cast<const void *>(pointer));
            pointer += type::getGLTypeSize(attributes[i].type) * attributes[i].amount;
        }

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, type::getGLTypeSize(indexType) * m_numIndices, indexData, usagehint::getGLUsageHint(usageHint));

        glBindVertexArray(0);
    }

    void GLIndexedModel::render() const
    {
        glBindVertexArray(m_vao);
        glDrawElements(m_primitive, m_numIndices, m_indexType, nullptr);
        glBindVertexArray(0);
    }

    void GLIndexedModel::setPrimitive(const Primitive &primitive)
    {
        m_primitive = primitive::getGLPrimitive(primitive);
    }

}