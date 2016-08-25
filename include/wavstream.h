#ifndef WAVSTREAM_H
#define WAVSTREAM_H

#include "wavheader.h"

namespace wav
{

class WavStream
{
public:
    WavStream(const std::string &filepath, wav::SampleRate sampleRate, wav::ChannelType channelType);

    ~WavStream();

    bool isOpen();

    void write(const short* samples, uint32_t samplesLength);

    void write(const short* leftSamples, const short* rightSamples, uint32_t samplesLength);

    void close();

private:

    std::string filepath;

    wav::SampleRate sampleRate;

    wav::ChannelType channelType;

    wav::WavFileHeader header;

    std::ofstream ostream;

    uint32_t writedSamplesCount;

};

}
#endif // WAVSTREAM_H
