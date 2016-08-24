#ifndef WAV_H
#define WAV_H

#include <inttypes.h>
#include <vector>

namespace wav {

enum ChannelType : short {
    mono = 1,
    stereo = 2
};

enum SampleRate : uint32_t {
    sampleRate_8000 = 8000,
    sampleRate_11025 = 11025,
    sampleRate_22050 = 22050,
    sampleRate_44100 = 44100,
    sampleRate_48000 = 48000
};



class Wav {
public:

    Wav(ChannelType channelType, SampleRate sampleRate, uint32_t sampleLength);

    enum Channel {
        monoChannel = 0,
        leftChannel = 0,
        rightChannel = 1
    };

    std::vector<short> &getMonoChannel();

    std::vector<short> &getLeftChannel();

    std::vector<short> &getRightChannel();

    ChannelType getChannelType() const;

    SampleRate getSampleRate() const;

private:

    ChannelType channelType;

    SampleRate sampleRate;

    std::vector<short> channels[2];

};

}

#include "wavwriter.h"
#include "wavgenerator.h"

#endif // WAV_H
