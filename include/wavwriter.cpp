#include "wavwriter.h"

#include "wavheader.h"

#include <fstream>

bool wav::writer::saveMonoPcmToWavFile(const short *sample, uint32_t sampleLength, short sampleRate, const std::string &filePath)
{
    std::ofstream stream(filePath.c_str(), std::ios::binary);

    if (!stream.is_open()) {
        return false;
    }

    WavFileHeader wavHeader(wav::ChannelType::mono, sampleLength, sampleRate);

    wavHeader.writeToStream(stream);

    stream.write((const char*)sample, sampleLength * sizeof (short) );

    stream.close();

    return true;
}
