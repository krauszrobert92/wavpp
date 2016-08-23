#ifndef WAVHEADER_H
#define WAVHEADER_H

#include "wav.h"

#include <fstream>

/**
 * @brief The WavFileHeader class
 *
 * http://soundfile.sapp.org/doc/WaveFormat/
 *
 */
class WavFileHeader
{
public:

    WavFileHeader(wav::ChannelType channelType, int sampleLength, int sampleRate);

    void writeToStream(std::ofstream &stream);

private:

    struct WavFileHeaderStruct {
        char    __RIFF[4]    = {'R', 'I', 'F', 'F'};
        int    chunkSize;                               // 36 + SubChunk2Size
        char    __WAVE[4]    = {'W', 'A', 'V', 'E'};
        char   __FMT[4]      = {'f', 'm', 't', ' '};
        int    __SUB_CHUNK_1_SIZE = 16;
        short  __AUDIO_FORAMT = 1;                      // 1 = PCM
        short  numChannels;
        int    sampleRate;
        int    byteRate;                                // == SampleRate * NumChannels * BitsPerSample/8
        short  blockAlign;                              // == NumChannels * BitsPerSample/8
        short  bitPerSample = 8 * sizeof(short);
        char   __DATA[4 ]     = {'D', 'A', 'T', 'A'};
        unsigned int sampleLength;                      // == NumSamples * NumChannels * BitsPerSample/8

        WavFileHeaderStruct(wav::ChannelType channelType, int sampleLength, int sampleRate);

    } __attribute__ ( (packed) );


private:
    WavFileHeaderStruct header;
};

#endif // WAVHEADER_H
