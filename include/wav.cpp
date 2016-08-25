#include "wav.h"

#include <stdexcept>

wav::Wav::Wav(wav::ChannelType channelType, SampleRate sampleRate, uint32_t sampleLength)
    : channelType(channelType)
    , sampleRate (sampleRate)
{
    if (channelType == ChannelType::mono)
    {
        channels[monoChannel].resize(sampleLength);
    } else
    {
        channels[leftChannel].resize(sampleLength);
        channels[rightChannel].resize(sampleLength);
    }

}

std::vector<short> & wav::Wav::getMonoChannel()
{
  if (channelType != ChannelType::mono)
      throw std::runtime_error("wav::Wav::getMonoChannel wav has not mono channel");

  return channels[monoChannel];
}

std::vector<short> & wav::Wav::getLeftChannel()
{
    if (channelType == ChannelType::mono)
        throw std::runtime_error("wav::Wav::getMonoChannel wav has not stereo channels");

    return channels[leftChannel];
}

std::vector<short> & wav::Wav::getRightChannel()
{
    if (channelType == ChannelType::mono)
        throw std::runtime_error("wav::Wav::getMonoChannel wav has not stereo channels");

    return channels[rightChannel];
}

wav::SampleRate wav::Wav::getSampleRate() const
{
    return sampleRate;
}

uint32_t wav::Wav::getSamplesLength() const
{
    return channels[monoChannel].size();
}

wav::ChannelType wav::Wav::getChannelType() const
{
    return channelType;
}

