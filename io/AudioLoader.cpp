#include "AudioLoader.h"

#include <fstream>

#include "Console.h"

namespace fl
{
    namespace io
    {
        struct RIFFHeader
        {
            i8 chunkID[4];
            ui32 chunkSize;
            i8 format[4];
        };

        struct WAVEFormat
        {
            i8 chunkID[4];
            ui32 chunkSize;
            ui16 audioFormat;
            ui16 numChannels;
            ui32 sampleRate;
            ui32 byteRate;
            ui16 blockAlign;
            ui16 bitsPerSample;
        };

        struct WAVEData
        {
            i8 chunkID[4];
            ui32 chunkSize;
        };

        void loadWAV(cString file, ui16f *numChannels, ui16f *bitsPerSample, ui8 **data, i32 *size, i32 *frequency)
        {
            std::ifstream in(file, std::ios::binary);
            if (!in.is_open())
            {
                log::error("Unable to open the WAV file: \"", file, "\"");
                return;
            }

            RIFFHeader h;
            WAVEFormat f;
            WAVEData d;

            in.read(reinterpret_cast<char *>(&h), sizeof(h));
            in.read(reinterpret_cast<char *>(&f), sizeof(f));
            in.read(reinterpret_cast<char *>(&d), sizeof(d));

            if (!(h.chunkID[0] == 'R' && h.chunkID[1] == 'I' && h.chunkID[2] == 'F' && h.chunkID[3] == 'F') && !(h.chunkID[0] == 'W' && h.chunkID[1] == 'A' && h.chunkID[2] == 'V' && h.chunkID[3] == 'E'))
            {
                log::error("Invalid WAV file: \"", file, "\"");
                return;
            }
            else if (!(f.chunkID[0] == 'f' && f.chunkID[1] == 'm' && f.chunkID[2] == 't' && f.chunkID[3] == ' '))
            {
                log::error("Invalid WAV file: \"", file, "\"");
                return;
            }
            else if (!(d.chunkID[0] == 'd' && d.chunkID[1] == 'a' && d.chunkID[2] == 't' && d.chunkID[3] == 'a'))
            {
                log::error("Invalid WAV file: \"", file, "\"");
                return;
            }

            *data = new ui8[d.chunkSize];
            in.read(reinterpret_cast<char *>(*data), d.chunkSize);

            *size = d.chunkSize;
            *frequency = f.sampleRate;
            *numChannels = f.numChannels;
            *bitsPerSample = f.bitsPerSample;
        }
    }
}