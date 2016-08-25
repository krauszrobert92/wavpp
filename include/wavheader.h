#ifndef WAVHEADER_H
#define WAVHEADER_H

#include "wav.h"

#include <fstream>

namespace wav {

/**
 * @brief The WavFileHeader class
 *
 * http://soundfile.sapp.org/doc/WaveFormat/
 *
 */
class WavFileHeader
{
private:

    struct WavFileHeaderStruct {
        uint8_t   __RIFF[4]    = {'R', 'I', 'F', 'F'};
        uint32_t chunkSize;                               // 36 + SubChunk2Size
        uint8_t  __WAVE[4]     = {'W', 'A', 'V', 'E'};
        uint8_t  __FMT[4]      = {'f', 'm', 't', ' '};
        uint32_t __SUB_CHUNK_1_SIZE = 16;
        uint16_t __AUDIO_FORAMT = 1;
        uint16_t numChannels;
        uint32_t sampleRate;
        uint32_t byteRate;                                // == SampleRate * NumChannels * BitsPerSample/8
        uint16_t blockAlign;                              // == NumChannels * BitsPerSample/8
        uint16_t bitPerSample = 8 * sizeof(short);
        uint8_t  __DATA[4]     = {'d', 'a', 't', 'a'};
        uint32_t samplesLength;                      // == NumSamples * NumChannels * BitsPerSample/8

        WavFileHeaderStruct(wav::ChannelType channelType, int samplesLength, int sampleRate);

        void setSampleLength(uint32_t samplesLength);

    } __attribute__ ( (packed) );

public:

    WavFileHeader(wav::ChannelType channelType, int sampleLength, int sampleRate);

    void writeToStream(std::ofstream &stream);

    WavFileHeaderStruct& getHeader();

private:
    WavFileHeaderStruct header;
};

}

#endif // WAVHEADER_H
