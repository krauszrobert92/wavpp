#ifndef WAVWRITER_H
#define WAVWRITER_H

#include <inttypes.h>
#include <string>
#include "wav.h"

namespace wav {

namespace writer
{
    bool saveMonoPcmToWavFile(const short* samples, uint32_t samplesLength, short sampleRate, const std::string &filePath);

    bool saveMonoPcmToWavFile(wav::Wav &wav, const std::string &filePath);
}

}



#endif // WAVWRITER_H
