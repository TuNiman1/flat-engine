#pragma once

#include "../Build.h"
#include "../Types.h"

namespace fl
{
    class FL_API Serializer
    {
    public:
        Serializer(ui8 *buffer, bool useBigEndian = false);
        ~Serializer();

        inline void writeUInt8(ui8 v) { m_buffer[m_index++] = v; }
        inline void writeInt8(i8 v) { writeUInt8(static_cast<ui8>(v)); }
        inline void writeBool(bool v) { writeUInt8(v ? 1 : 0); }
        void writeUInt16(ui16 v);
        void writeUInt32(ui32 v);
        void writeUInt64(ui64 v);

        void writeFloat32(f32 v);
        void writeFloat64(f64 v);
        void writeFloat128(f128 v);

        void writeString(const String &string);

        inline ui8 readUInt8() { return m_buffer[m_index++]; }
        inline i8 readInt8() { return static_cast<i8>(readUInt8()); }
        inline bool readBool() { return readUInt8() != 0; }
        ui16 readUInt16();
        ui32 readUInt32();
        ui64 readUInt64();

        f32 readFloat32();
        f64 readFloat64();
        f128 readFloat128();

        String readString();

        inline ui16 swapEndian(ui16 v) const { return (v >> 8) | (v << 8); }
        inline ui32 swapEndian(ui32 v) const { return (v >> 24) | (v >> 8 & 0x0000ff00) | (v << 8 & 0x00ff0000) | (v << 24); }
        inline ui64 swapEndian(ui64 v) const { return (v >> 56) | (v >> 40 | 0x000000000000ff00) | (v >> 24 | 0x0000000000ff0000) | (v >> 8 | 0x00000000ff000000) | (v << 8 | 0x000000ff00000000) | (v << 24 | 0x0000ff0000000000) | (v << 40 | 0x00ff000000000000) | (v << 56); }

    private:
        ui8 *m_buffer;
        ui32f m_index;
        bool m_bigEndianInteger;
        bool m_bigEndianFloat;
        bool m_useBigEndian;
    };
}