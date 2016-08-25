#ifndef WAVWRITER_H
#define WAVWRITER_H

#include <inttypes.h>
#include <string>
#include "wav.h"

namespace wav {

class writer
{
public:
   static bool writeToFile(wav::Wav &wav, const std::string &filePath);

protected:
    static std::vector<short> mixChannels(wav::Wav &wav);

    static bool saveStereoPcmToWavFile(const short* leftChannel, const short* rightChannel, uint32_t samplesLength, SampleRate sampleRate, const std::string &filePath);

    static bool writeSamplesToFile(const short* samples, uint32_t samplesLength, wav::ChannelType channelType, wav::SampleRate sampleRate, const std::string &filePath);

};

}



#endif // WAVWRITER_H
