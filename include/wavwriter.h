#ifndef WAVWRITER_H
#define WAVWRITER_H

#include <inttypes.h>
#include <string>

namespace wav {

namespace writer
{
    bool saveMonoPcmToWavFile(const short* samples, uint32_t samplesLength, short sampleRate, const std::string &filePath);
}

}



#endif // WAVWRITER_H
