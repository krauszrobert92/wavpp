#include "wavgenerator.h"

#include <math.h>

void wav::generator::addSinSignal(wav::ChannelType channelType, short *sample, uint32_t sampleSize, short sampleRate, float amplitude, float frequency)
{
    for (int32_t i=0; i<sampleSize; i+= channelType)
    {
        sample[i] = (short)(amplitude * sin ( 2.0f * M_PI * frequency ) * ((i /channelType / sampleRate )));
    }
}
