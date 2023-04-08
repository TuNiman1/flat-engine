#include "Serializer.h"
#include "../System.h"

namespace fl
{
    Serializer::Serializer(ui8 *buffer, bool useBigEndian) : m_buffer(buffer), m_index(0), m_bigEndianInteger(system::isBigEndianInteger()), m_bigEndianFloat(system::isBigEndianFloat()), m_useBigEndian(useBigEndian)
    {
    }

    Serializer::~Serializer()
    {
    }
}