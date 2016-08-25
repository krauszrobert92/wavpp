#include "wavgenerator.h"

#include <math.h>
#include <iostream>

void wav::generator::addSinSignal(wav::ChannelType channelType, std::vector<short>& samples, wav::SampleRate sampleRate, float amplitude, float frequency)
{
    float t = 0.0f;
    float dt = 1.0f / sampleRate;

    for (uint32_t i=0; i<samples.size(); i+= channelType)
    {
        samples[i] = (short) amplitude * sin (t * 2.0f * M_PI * frequency);
        t += dt;
    }
}

void wav::generator::addSinSignal(wav::Wav &wav, float amplitude, float frequency)
{
    if (wav.getChannelType() == wav::ChannelType::mono)
    {
        addSinSignal(wav.getChannelType(), wav.getMonoChannel(), wav.getSampleRate(), amplitude, frequency);
    }
    else
    {
        addSinSignal(wav::ChannelType::mono, wav.getLeftChannel(), wav.getSampleRate(), amplitude, frequency);
        addSinSignal(wav::ChannelType::mono, wav.getRightChannel(), wav.getSampleRate(), amplitude, frequency);
    }
}

std::vector<short> wav::generator::mixChannels(wav::Wav &wav)
{
    return mixChannels(wav.getLeftChannel().data(), wav.getRightChannel().data(), wav.getSamplesLength());
}

std::vector<short> wav::generator::mixChannels(const short *leftSamples, const short *rightSamples, uint32_t samplesLength)
{
    std::vector<short> chanels( 2 * samplesLength );

    for (uint32_t i = 0; i < samplesLength; i++)
    {
        chanels[ 2*i ] = leftSamples [i];
        chanels[ 2*i + 1 ] = rightSamples [i];
    }

    return chanels;
}
