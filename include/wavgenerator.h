#ifndef WAVGENERATOR_H
#define WAVGENERATOR_H

#include "wav.h"


namespace wav {

namespace generator
{
    void addSinSignal(wav::ChannelType channelType, std::vector<short> &samples, SampleRate sampleRate, float amplitude, float frequency);

    void addSinSignal(Wav &wav, float amplitude, float frequency);
}

}


#endif // WAVGENERATOR_H
