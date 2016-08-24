#include "wavwriter.h"

#include "wavheader.h"

#include <fstream>

bool wav::writer::saveMonoPcmToWavFile(const short *sample, uint32_t sampleLength, short sampleRate, const std::string &filePath)
{
    std::ofstream stream(filePath, std::ios::binary);

    if (!stream.is_open()) {
        return false;
    }

    WavFileHeader wavHeader(wav::ChannelType::mono, sampleLength, sampleRate);

    wavHeader.writeToStream(stream);

    stream.write((const char*)sample, sampleLength * sizeof (short) );

    stream.close();

    return true;
}

bool wav::writer::saveMonoPcmToWavFile(wav::Wav &wav, const std::__cxx11::string &filePath)
{
    if (wav.getChannelType() == wav::ChannelType::mono)
    {
        saveMonoPcmToWavFile(wav.getMonoChannel().data(), wav.getMonoChannel().size(), wav.getSampleRate(), filePath);
    }
}
