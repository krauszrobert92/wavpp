#ifndef WAVGENERATOR_H
#define WAVGENERATOR_H

#include "wav.h"


namespace wav {

namespace generator
{
    void addSinSignal(wav::ChannelType channelType, std::vector<short> &samples, SampleRate sampleRate, float amplitude, float frequency);

    void addSinSignal(Wav &wav, float amplitude, float frequency);

    std::vector<short> mixChannels(wav::Wav &wav);

    std::vector<short> mixChannels(const short *leftSamples, const short *rightSamples, uint32_t samplesLength);

}

}

#endif // WAVGENERATOR_H
