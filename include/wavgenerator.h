#ifndef WAVGENERATOR_H
#define WAVGENERATOR_H

#include "wav.h"


namespace wav {

namespace generator
{
    void addSinSignal(wav::ChannelType channelType, short *sample, uint32_t sampleSize, short sampleRate, float amplitude, float frequency);
}

}


#endif // WAVGENERATOR_H
