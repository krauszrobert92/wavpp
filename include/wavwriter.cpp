#include "wavwriter.h"

#include "wavheader.h"

#include <fstream>
#include <iostream>

bool wav::writer::writeToFile(wav::Wav &wav, const std::string &filePath)
{
    if (wav.getChannelType() == wav::ChannelType::mono)
    {
        return writeSamplesToFile (wav.getMonoChannel().data(), wav.getMonoChannel().size(), wav::ChannelType::mono, wav.getSampleRate(), filePath);
    }
    else
    {
        std::vector<short> chanels = mixChannels(wav);
        return writeSamplesToFile(&chanels[0], chanels.size(), wav::ChannelType::stereo, wav.getSampleRate(), filePath);
    }
}

std::vector<short> wav::writer::mixChannels(wav::Wav &wav)
{
    std::vector<short> chanels( 2 * wav.getSamplesLength() );

    for (uint32_t i = 0; i < wav.getSamplesLength(); i++)
    {
        chanels[ 2*i] = wav.getLeftChannel()[i];
        chanels[ 2*i + 1 ] = wav.getRightChannel()[i];
    }

    return chanels;
}

bool wav::writer::writeSamplesToFile(const short* samples, uint32_t samplesLength, wav::ChannelType channelType, wav::SampleRate sampleRate, const std::string &filePath )
{
    std::ofstream stream(filePath, std::ios::binary);

    if (!stream.is_open()) {
        return false;
    }

    WavFileHeader wavHeader(channelType, samplesLength, sampleRate);

    wavHeader.writeToStream(stream);

    stream.write((const char*)samples, samplesLength * sizeof (short) );

    stream.close();

    return true;
}





